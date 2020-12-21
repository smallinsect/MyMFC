CFileDialog dlg(TRUE,//这个参数为TRUE就是“打开”对话框，为FALSE就是“保存”对话框
	NULL,//默认文件类型
	NULL,//默认文件名
	OFN_HIDEREADONLY,//样式，这里设置为“隐藏只读”
	_T("所有文件(*.*)|*.*||"),//文件类型列表
	NULL,
	NULL,
	FALSE);//指定文件打开对话框是否为Vista样式
if (dlg.DoModal() == IDOK)//如果用户在文件对话框中点击了“确定”按钮
{
	CString strPathName = dlg.GetPathName();//获取文件路径到strPathName
	AfxMessageBox(strPathName);//显示文件路径到编辑框
}