// termprj.h : main header file for the TERMPRJ application
//

#if !defined(AFX_TERMPRJ_H__3E53CFA1_A37F_4941_B5B3_0DC35A79B858__INCLUDED_)
#define AFX_TERMPRJ_H__3E53CFA1_A37F_4941_B5B3_0DC35A79B858__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTermprjApp:
// See termprj.cpp for the implementation of this class
//

class CTermprjApp : public CWinApp
{
public:
	CTermprjApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTermprjApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTermprjApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERMPRJ_H__3E53CFA1_A37F_4941_B5B3_0DC35A79B858__INCLUDED_)
