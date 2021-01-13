# GDI

## 获取CDC

```c++
CDC* pDC  = GetDC();
//Graphics graphics();
pDC->TextOut(100, 100, TEXT("飞翔的小白菜"));

ReleaseDC(pDC);
```