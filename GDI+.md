# Graphics

## 添加头文件和导入库

```c++
#include "gdiplus.h"
#pragma comment( lib, "gdiplus.lib" )
using namespace Gdiplus;
```
## 使用之前需要添加下面代码

```c++
GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR           gdiplusToken;
GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
```
## 获取窗口权限

```c++
Graphics graphics(m_hWnd);

Color color(255, 0, 0);
Pen pen(color);
graphics.DrawLine(&pen, 0, 0, 100, 100);
```



































