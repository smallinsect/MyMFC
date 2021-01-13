# MyMFC

# VS项目配置环境
```
输出目录
$(SolutionDir)../bin/$(Platform)/$(Configuration)/
中间目录
$(SolutionDir)../bintemp/$(Platform)/$(ProjectName)/$(Configuration)/
```


_CRT_SECURE_NO_WARNINGS

# 控件

## ListBox列表框

### 1.向列表框空间中添加数据

```c++
m_ListBox.AddString(TEXT("1111"));
m_ListBox.AddString(TEXT("0000"));
m_ListBox.AddString(TEXT("2222"));
```

默认排序，取消排序，选中控件->属性->sort 改为false。

### 自定义位置插入数据

```c++
m_ListBox.InsertString(0, TEXT("aaaa"));
m_ListBox.InsertString(1, TEXT("bbbb"));
m_ListBox.InsertString(2, TEXT("cccc"));
m_ListBox.InsertString(1, TEXT("dddd"));
```

不受sort影响

### 2.获取列表长度

```c++
int iCnt = m_ListBox.GetCount();
```

### 3.删除数据

```c++
m_ListBox.DeleteString(0);// 删除指定索引的数据
m_ListBox.ResetContent();// 删除所有数据
```
### 4.设置列表框中选中某条数据

```c++
m_ListBox.SetCurSel(1);// 选中某条元素
```

### 5.获取当前选中的数据索引

```c++
int idx = m_ListBox.GetCurSel();// 获取当前选中的数据
```

### 6.多选

列表框属性->Selection 改为Multiple

```c++
m_ListBox.SetSel(0);// 选中
m_ListBox.SetSel(1);// 选中
m_ListBox.SetSel(2);// 选中
```
### 7.获取选中的多少个

```c++
int selCnt = m_ListBox.GetSelCount();// 获取选中的个数
if (selCnt > 0) {
	int* pArr = new int(selCnt);
	m_ListBox.GetSelItems(selCnt, pArr);// 获取选中的索引
	// handle ...
	delete[] pArr;
}
```
### 8.获取行中的文本

```c++
CString strText;
m_ListBox.GetText(1, strText);// 获取索引1的内容
```

```c++
int textLen = m_ListBox.GetTextLen(2);// 获取索引2内容的文本长度
TCHAR* pszText = new TCHAR(textLen+1);
m_ListBox.GetText(2, pszText);// 获取索引1的内容
// handle ...
delete[] pszText;
```

### 9.扩展

https://www.codeproject.com/KB/combobox

## ListCtl列表控件

### 选择视图

选中控件->属性->View 选择Report

给控件绑定变量

### 添加标题

```c++
m_List.InsertColumn(0, TEXT("第1列"), LVCFMT_LEFT, 70);//插入标题
m_List.InsertColumn(1, TEXT("第2列"), LVCFMT_LEFT, 70);//插入标题
m_List.InsertColumn(2, TEXT("第3列"), LVCFMT_LEFT, 70);//插入标题
```
### 控件添加样式

```c++
DWORD dwStyle = m_List.GetExtendedStyle();// 获取已有样式
dwStyle |= LVS_EX_GRIDLINES;
m_List.SetExtendedStyle(dwStyle);// 设置样式
```
### 插入行数据

```c++
// 最后一行，第一列插入数据
m_List.InsertItem(m_List.GetItemCount(), TEXT("小昆虫1"));
```
```c++
DWORD dwIdx = m_List.GetItemCount();
m_List.InsertItem(dwIdx, TEXT("小昆虫1"));
m_List.SetItemText(dwIdx, 0, TEXT("小昆虫x"));
m_List.SetItemText(dwIdx, 1, TEXT("小昆虫2"));
m_List.SetItemText(dwIdx, 2, TEXT("小昆虫3"));
```
### 整行选中样式

```c++
LVS_EX_FULLROWSELECT
```

### 列前有选择框

```
LVS_EX_CHECKBOXES
```

### 选中某一行

```c++
m_List.SetFocus();//这句别忘了，不然不能高亮。
m_List.SetItemState(1, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
```
### 取消选中

```
m_List.SetItemState(1, 0, LVIS_SELECTED | LVIS_FOCUSED);
```

### 遍历列表

```c++
// 遍历列表
int iCnt = m_List.GetItemCount();
for (int idx = 0; idx < iCnt; ++idx) {
	CString str = m_List.GetItemText(idx, 0);
	str = m_List.GetItemText(idx, 1);
	str = m_List.GetItemText(idx, 2);
}
```

























