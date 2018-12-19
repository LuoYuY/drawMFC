// termprjDoc.h : interface of the CTermprjDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TERMPRJDOC_H__89FE6DCF_B6B9_4733_BEC2_F0B224B52D07__INCLUDED_)
#define AFX_TERMPRJDOC_H__89FE6DCF_B6B9_4733_BEC2_F0B224B52D07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTermprjDoc : public CDocument
{
protected: // create from serialization only
	CTermprjDoc();
	DECLARE_DYNCREATE(CTermprjDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTermprjDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTermprjDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTermprjDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERMPRJDOC_H__89FE6DCF_B6B9_4733_BEC2_F0B224B52D07__INCLUDED_)
