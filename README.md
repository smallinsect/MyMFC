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

## ListBox控件

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




































