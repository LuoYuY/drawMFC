// termprjView.cpp : implementation of the CTermprjView class
//

#include "stdafx.h"
#include "termprj.h"

#include "termprjDoc.h"
#include "termprjView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTermprjView

IMPLEMENT_DYNCREATE(CTermprjView, CView)

BEGIN_MESSAGE_MAP(CTermprjView, CView)
	//{{AFX_MSG_MAP(CTermprjView)
	ON_COMMAND(ID_Drawline, OnDrawline)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTermprjView construction/destruction

CTermprjView::CTermprjView()
{
	// TODO: add construction code here
	//初始化
	m_drawline=false;  
	m_drawarc=false;
	m_capture=false;
	m_inrect=false;
	num = 0;
}

CTermprjView::~CTermprjView()
{
}

BOOL CTermprjView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTermprjView drawing

void CTermprjView::OnDraw(CDC* pDC)
{
	CTermprjDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTermprjView printing

BOOL CTermprjView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTermprjView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTermprjView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTermprjView diagnostics

#ifdef _DEBUG
void CTermprjView::AssertValid() const
{
	CView::AssertValid();
}

void CTermprjView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTermprjDoc* CTermprjView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTermprjDoc)));
	return (CTermprjDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTermprjView message handlers


//画直线
void CTermprjView::OnDrawline() 
{
	// TODO: Add your command handler code here
	m_drawline = true;  //开启画直线模式
	m_capture = false;  //mousemove中的动态画线不生效，点下起点后才生效
}


void CTermprjView::OnMouseMove(UINT nFlags, CPoint point) 
{
	//每次移动都判断是否在自动捕获区域内
	for(int i=0; i<rects.size(); i++)
	{
		BOOL flag = rects[i].PtInRect(point);  //point是否在rect区域内
		if (flag){//点point在构造的矩形区域内;
			//AfxMessageBox(_T("在区域内！"));
			m_inrect = true;
			temp = rects[i];
			HCURSOR cursor = LoadCursor(NULL,IDC_CROSS);
			::SetCursor(cursor);//将光标设置成十字
			SetClassLong(this->GetSafeHwnd(),GCL_HCURSOR,(LONG)LoadCursor(NULL, IDC_CROSS));//使光标在该区域不再闪烁
			break;
		}
		 else
		 {
			 m_inrect = false;
			  //光标离开该区域恢复默认箭头形状
			 SetClassLong(this->GetSafeHwnd(),GCL_HCURSOR,(LONG)LoadCursor(NULL, IDC_ARROW));
		 }

	}

	if (m_capture){  //已经点了第一个点
		
		BOOL bCtrl = GetKeyState(VK_CONTROL) & 0x8000; //判断ctrl是否被按下
		CClientDC  ClientDC(this); //this = 本窗口
		CPen pen;
		pen.CreatePen(PS_SOLID,3,0x00ffffff-RGB(0,0,255));    //创建线条颜色（测试用蓝色）的反色画笔
		ClientDC.SelectObject(&pen);	
		ClientDC.SetROP2(R2_XORPEN);   //设置模式为画笔的反色
		
		//画旧的线
		ClientDC.MoveTo(beginPt.x,beginPt.y);  
		ClientDC.LineTo(endPt.x,endPt.y); 
		if(bCtrl)   //ctrl被按下
		{
			if(abs(point.x-beginPt.x)>abs(point.y-beginPt.y))  //光标位置与起点连接，小于45，花水平线
			{
				endPt.x = point.x; 
				endPt.y = beginPt.y;
			}
			else   //光标位置与起点连接，大于45，花垂直线
			{
				endPt.y = point.y; 
				endPt.x = beginPt.x;
			}

		}
		else {
			endPt = point;
		}
	//画新的线
	ClientDC.MoveTo(beginPt.x,beginPt.y);  
	ClientDC.LineTo(endPt.x,endPt.y);  
	}

	CView::OnMouseMove(nFlags, point);
}

void CTermprjView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_drawline) {//当前不是绘制直线模式
		if(m_inrect)  //光标在区域内
		{
			//temp
			beginPt = temp.CenterPoint();
			endPt = temp.CenterPoint();
			//AfxMessageBox(_T("捕捉成功"));
		}
		else{
			beginPt = point;
			endPt = point;
		}
		
		m_capture = true;   //mousemove开始生效
		CRect rc(beginPt.x-20,beginPt.y-20,beginPt.x+20,beginPt.y+20); //在这一点创建一个自动捕获区域，40*40
		//AfxMessageBox(_T("111111！"));
		rects.push_back(rc);  //加入到保存所有区域的向量
	}
	CView::OnLButtonDown(nFlags, point);
}

void CTermprjView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	//	m_drawline = false;  //关闭画直线模式
	m_capture = false;  //关闭动态画线
	if(m_inrect)  //如果光标在自动捕获区域内
	{
		CClientDC  ClientDC(this); //this = 本窗口
		CPen pen;
		pen.CreatePen(PS_SOLID,3,0x00ffffff-RGB(0,0,255));    //创建边界色的反色画笔
		ClientDC.SelectObject(&pen);	
		ClientDC.SetROP2(R2_XORPEN);   //设置模式为画笔的反色
		//画旧的线
		ClientDC.MoveTo(beginPt.x,beginPt.y);  
		ClientDC.LineTo(endPt.x,endPt.y); 

		//终点定位到捕获区域的中心
		endPt = temp.CenterPoint();
		endPt = temp.CenterPoint();
		//AfxMessageBox(_T("捕捉成功"));
		ClientDC.MoveTo(beginPt.x,beginPt.y);  
		ClientDC.LineTo(endPt.x,endPt.y);  
	}

	CRect rc(endPt.x-20,endPt.y-20,endPt.x+20,endPt.y+20);   //生成新的捕获区域，添加到向量中
	rects.push_back(rc);
	CView::OnLButtonUp(nFlags, point);
}
