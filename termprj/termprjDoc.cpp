// termprjDoc.cpp : implementation of the CTermprjDoc class
//

#include "stdafx.h"
#include "termprj.h"

#include "termprjDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTermprjDoc

IMPLEMENT_DYNCREATE(CTermprjDoc, CDocument)

BEGIN_MESSAGE_MAP(CTermprjDoc, CDocument)
	//{{AFX_MSG_MAP(CTermprjDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTermprjDoc construction/destruction

CTermprjDoc::CTermprjDoc()
{
	// TODO: add one-time construction code here

}

CTermprjDoc::~CTermprjDoc()
{
}

BOOL CTermprjDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTermprjDoc serialization

void CTermprjDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTermprjDoc diagnostics

#ifdef _DEBUG
void CTermprjDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTermprjDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTermprjDoc commands
