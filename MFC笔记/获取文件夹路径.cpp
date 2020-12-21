CString m_strFileOut = _T("");
TCHAR servPath[MAX_PATH];//用来存放文件夹路径
BROWSEINFO bi;
LPITEMIDLIST pidl;
bi.hwndOwner = this->m_hWnd;
bi.pidlRoot = NULL;
bi.pszDisplayName = servPath;
bi.lpszTitle = _T("选择输出文件路径");
bi.ulFlags = BIF_RETURNONLYFSDIRS;
bi.lpfn = NULL;
bi.lParam = NULL;
bi.iImage = NULL;
if ((pidl = SHBrowseForFolder(&bi)) != NULL)
{
	if (SUCCEEDED(SHGetPathFromIDList(pidl, servPath))) //得到文件夹的全路径，不要的话，只得本文件夹名
	{
		AfxMessageBox(servPath);//显示文件路径到编辑框
	}
}