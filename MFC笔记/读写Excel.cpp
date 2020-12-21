#include <ole2.h> // OLE2 Definitions
#include <stdio.h>
#include <windows.h>

// AutoWrap() - Automation helper function...
HRESULT AutoWrap(int autoType, VARIANT* pvResult, IDispatch* pDisp, LPOLESTR ptName, int cArgs...) {
    // Begin variable-argument list...
    va_list marker;
    va_start(marker, cArgs);

    if (!pDisp) {
        MessageBox(NULL, TEXT("NULL IDispatch passed to AutoWrap()"), TEXT("Error"), 0x10010);
        _exit(0);
    }

    // Variables used...
    DISPPARAMS dp = { NULL, NULL, 0, 0 };
    DISPID dispidNamed = DISPID_PROPERTYPUT;
    DISPID dispID;
    HRESULT hr;
    wchar_t buf[200];
    char szName[200];


    // Convert down to ANSI
    WideCharToMultiByte(CP_ACP, 0, ptName, -1, szName, 256, NULL, NULL);

    // Get DISPID for name passed...
    hr = pDisp->GetIDsOfNames(IID_NULL, &ptName, 1, LOCALE_USER_DEFAULT, &dispID);
    if (FAILED(hr)) {
        wsprintf(buf, TEXT("IDispatch::GetIDsOfNames(\"%s\") failed w/err 0x%08lx"), szName, hr);
        MessageBox(NULL, buf, TEXT("AutoWrap()"), 0x10010);
        _exit(0);
        return hr;
    }

    // Allocate memory for arguments...
    VARIANT* pArgs = new VARIANT[cArgs + 1];
    // Extract arguments...
    for (int i = 0; i < cArgs; i++) {
        pArgs[i] = va_arg(marker, VARIANT);
    }

    // Build DISPPARAMS
    dp.cArgs = cArgs;
    dp.rgvarg = pArgs;

    // Handle special-case for property-puts!
    if (autoType & DISPATCH_PROPERTYPUT) {
        dp.cNamedArgs = 1;
        dp.rgdispidNamedArgs = &dispidNamed;
    }

    // Make the call!
    hr = pDisp->Invoke(dispID, IID_NULL, LOCALE_SYSTEM_DEFAULT, autoType, &dp, pvResult, NULL, NULL);
    if (FAILED(hr)) {
        wsprintf(buf, TEXT("IDispatch::Invoke(\"%s\"=%08lx) failed w/err 0x%08lx"), szName, dispID, hr);
        MessageBox(NULL, buf, TEXT("AutoWrap()"), 0x10010);
        _exit(0);
        return hr;
    }
    // End variable-argument section...
    va_end(marker);

    delete[] pArgs;

    return hr;
}

int main() {
    wchar_t wStr[] = L"这是一段中文";
    // Initialize COM for this thread...
    CoInitialize(NULL);

    // Get CLSID for our server...
    CLSID clsid;
    HRESULT hr = CLSIDFromProgID(L"Excel.Application", &clsid);

    if (FAILED(hr)) {

        ::MessageBox(NULL, TEXT("CLSIDFromProgID() failed"), TEXT("Error"), 0x10010);
        return -1;
    }

    // Start server and get IDispatch...
    IDispatch* pXlApp;
    hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_IDispatch, (void**)&pXlApp);
    if (FAILED(hr)) {
        ::MessageBox(NULL, TEXT("Excel not registered properly"), TEXT("Error"), 0x10010);
        return -2;
    }

    // Make it visible (i.e. app.visible = 1)
    {
        WCHAR ptName[] = L"Visible";
        VARIANT x;
        x.vt = VT_I4;
        x.lVal = 1;
        AutoWrap(DISPATCH_PROPERTYPUT, NULL, pXlApp, ptName, 1, x);
    }

    // Get Workbooks collection
    IDispatch* pXlBooks;
    {
        WCHAR ptName[] = L"Workbooks";
        VARIANT result;
        VariantInit(&result);
        AutoWrap(DISPATCH_PROPERTYGET, &result, pXlApp, ptName, 0);
        pXlBooks = result.pdispVal;
    }

    // Call Workbooks.Add() to get a new workbook...
    IDispatch* pXlBook;
    {
        WCHAR ptName[] = L"Add";
        VARIANT result;
        VariantInit(&result);
        AutoWrap(DISPATCH_PROPERTYGET, &result, pXlBooks, ptName, 0);
        pXlBook = result.pdispVal;
    }

    // Create a 15x15 safearray of variants...
    VARIANT arr;
    arr.vt = VT_ARRAY | VT_VARIANT;
    {
        SAFEARRAYBOUND sab[2];
        sab[0].lLbound = 1; sab[0].cElements = 15;
        sab[1].lLbound = 1; sab[1].cElements = 15;
        arr.parray = SafeArrayCreate(VT_VARIANT, 2, sab);
    }

    // Fill safearray with some values...
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            // Create entry value for (i,j)
            VARIANT tmp;
            tmp.vt = VT_I4;
            tmp.lVal = i * j;
            // Add to safearray...
            long indices[] = { i,j };
            SafeArrayPutElement(arr.parray, indices, (void*)&tmp);
        }
    }

    // Get ActiveSheet object
    IDispatch* pXlSheet;
    {
        WCHAR ptName[] = L"ActiveSheet";
        VARIANT result;
        VariantInit(&result);
        AutoWrap(DISPATCH_PROPERTYGET, &result, pXlApp, ptName, 0);
        pXlSheet = result.pdispVal;
    }

    // Get Range object for the Range A1:O15...
    IDispatch* pXlRange;
    {
        VARIANT parm;
        parm.vt = VT_BSTR;
        parm.bstrVal = ::SysAllocString(L"A1:O15");

        WCHAR ptName[] = L"Range";
        VARIANT result;
        VariantInit(&result);
        AutoWrap(DISPATCH_PROPERTYGET, &result, pXlSheet, ptName, 1, parm);
        VariantClear(&parm);

        pXlRange = result.pdispVal;
    }


    WCHAR ptName[] = L"Value";
    // Set range with our safearray...
    AutoWrap(DISPATCH_PROPERTYPUT, NULL, pXlRange, ptName, 1, arr);

    // Wait for user...
    ::MessageBox(NULL, TEXT("All done."), TEXT( "Notice"), 0x10000);

    // Set .Saved property of workbook to TRUE so we aren't prompted
    // to save when we tell Excel to quit...
    {
        WCHAR ptName[] = L"Saved";
        VARIANT x;
        x.vt = VT_I4;
        x.lVal = 1;
        AutoWrap(DISPATCH_PROPERTYPUT, NULL, pXlBook, ptName, 1, x);
    }

    WCHAR ptName1[] = L"Quit";
    // Tell Excel to quit (i.e. App.Quit)
    AutoWrap(DISPATCH_METHOD, NULL, pXlApp, ptName1, 0);

    // Release references...
    pXlRange->Release();
    pXlSheet->Release();
    pXlBook->Release();
    pXlBooks->Release();
    pXlApp->Release();
    VariantClear(&arr);

    // Uninitialize COM for this thread...
    CoUninitialize();
    return 0;
}
