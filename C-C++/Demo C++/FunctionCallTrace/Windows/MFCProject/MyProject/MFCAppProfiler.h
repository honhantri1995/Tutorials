
// MFCAppProfiler.h : main header file for the MFCAppProfiler application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCAppProfilerApp:
// See MFCAppProfiler.cpp for the implementation of this class
//

class CMFCAppProfilerApp : public CWinAppEx
{
public:
	CMFCAppProfilerApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCAppProfilerApp theApp;
