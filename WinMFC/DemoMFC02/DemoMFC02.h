#pragma once

#include <sdkddkver.h>
#include <afxwin.h>

class MyApp : public CWinApp {
public:
	virtual BOOL InitInstance();
};


class MyFrame : public CFrameWnd {
public:
	MyFrame();

	DECLARE_MESSAGE_MAP()//œ˚œ¢”≥…‰

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPaint();
};