CFileDialog fileDlg(TRUE);
fileDlg.m_ofn.lpstrTitle = L"打开文件";
//fileDlg.m_ofn.lpstrFilter=_T("Program(*.exe)\0*.exe\0All Files(*.*)\0*.*\0\0");
if (IDOK == fileDlg.DoModal())
{
	LPWSTR lpPathName = fileDlg.m_ofn.lpstrFile;
	AfxMessageBox(lpPathName);//显示文件路径到编辑框
}