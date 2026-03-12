
// MFCApplication1View.cpp: реализация класса CMFCApplication1View
//

//#include "pch.h"
#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif
#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCApplication1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Создание или уничтожение CMFCApplication1View

CMFCApplication1View::CMFCApplication1View() 
{
	// TODO: добавьте код создания

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

#define Pprt(a) (*(Particle**)a)
int sortOfZ(const void* a, const void* b)
{
    if (Pprt(a)->Z > Pprt(b)->Z) return  1; else
        if (Pprt(a)->Z < Pprt(b)->Z) return -1; else
            return  0;
}

void CMFCApplication1View::OnDraw(CDC* pDC)
{
    double Dzx, Dzy;
    HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 0));
    CMFCApplication1Doc* pDoc = GetDocument();
    ASSERT_VALID(pDoc);

    if (!pDoc) return;
    CRect r;
    GetClientRect(&r);

    HDC hdc = pDC->m_hDC;

    FillRect(hdc, r, hbrush);
    DeleteObject(r);
    DeleteObject(hbrush);
    int i;

    for (i = 0, pDoc->Pi = pDoc->FirstPat; (pDoc->Mp[i++] = pDoc->Pi, pDoc->Pi = pDoc->Pi->next); );
    qsort(pDoc->Mp, pDoc->N, sizeof(Particle*), &sortOfZ);

    if (FrModInCndDlg.m_rd == 1)
    {
        for (i = 0; i < pDoc->N; i++)
        {
            if (pDoc->Mp[i]->agr != 0)
            {
                Agregat XR = pDoc->CMass[pDoc->Mp[i]->agr];
                Agregat YR = pDoc->CMass[pDoc->Mp[i]->agr];
                Dzx = pDoc->Mp[i]->Z * (pDoc->Mp[i]->X - XR.X) / (2 * pDoc->Zmax);
                Dzy = pDoc->Mp[i]->Z * (pDoc->Mp[i]->Y - YR.Y) / (2 * pDoc->Zmax);
            }
            else Dzx = Dzy = 0;


            if (pDoc->Mp[i]->q == 0)
            {
                HPEN hNPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
                HPEN hOPen = (HPEN)SelectObject(hdc, hNPen);
                Arc(hdc, (int)(pDoc->Mp[i]->X + Dzx), (int)(pDoc->Mp[i]->Y + Dzy), (int)(pDoc->Mp[i]->X + Dzx + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)(pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)((pDoc->Mp[i]->X + Dzx)), (int)((pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R) / 2 + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)((pDoc->Mp[i]->X + Dzx)), (int)((pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R) / 2 + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax));
                DeleteObject(hNPen);
                DeleteObject(hOPen);
            }
            else
                if (pDoc->Mp[i]->q > 0)
                {
                    HPEN hNPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
                    HPEN hOPen = (HPEN)SelectObject(hdc, hNPen);
                    Arc(hdc, (int)(pDoc->Mp[i]->X + Dzx), (int)(pDoc->Mp[i]->Y + Dzy), (int)(pDoc->Mp[i]->X + Dzx + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)(pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)((pDoc->Mp[i]->X + Dzx)), (int)((pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R) / 2 + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)((pDoc->Mp[i]->X + Dzx)), (int)((pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R) / 2 + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax)); 
                    DeleteObject(hNPen);
                    DeleteObject(hOPen);
                }
                else
                    if (pDoc->Mp[i]->q < 0)
                    {
                        HPEN hNPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
                        HPEN hOPen = (HPEN)SelectObject(hdc, hNPen);
                        Arc(hdc, (int)(pDoc->Mp[i]->X + Dzx), (int)(pDoc->Mp[i]->Y + Dzy), (int)(pDoc->Mp[i]->X + Dzx + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)(pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)((pDoc->Mp[i]->X + Dzx)), (int)((pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R) / 2 + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)((pDoc->Mp[i]->X + Dzx)), (int)((pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R) / 2 + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax)); 
                        DeleteObject(hNPen);
                        DeleteObject(hOPen);
                    }
        }
    }
    else
    {
        for (i = 0; i < pDoc->N; i++)
        {
            HBRUSH hbrush, hbrushOld;

            if (pDoc->Mp[i]->agr != 0)
            {
                Agregat XR = pDoc->CMass[pDoc->Mp[i]->agr];
                Agregat YR = pDoc->CMass[pDoc->Mp[i]->agr];
                Dzx = pDoc->Mp[i]->Z * (pDoc->Mp[i]->X - XR.X) / (2 * pDoc->Zmax);
                Dzy = pDoc->Mp[i]->Z * (pDoc->Mp[i]->Y - YR.Y) / (2 * pDoc->Zmax);
            }
            else Dzx = Dzy = 0;

            if (pDoc->Mp[i]->q == 0)
            {

                hbrush = CreateSolidBrush(RGB(255, 0, 255));
                hbrushOld = (HBRUSH)SelectObject(hdc, hbrush);
                Ellipse(hdc, (int)(pDoc->Mp[i]->X + Dzx), (int)(pDoc->Mp[i]->Y + Dzy), (int)(pDoc->Mp[i]->X + Dzx + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)(pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax));
                DeleteObject(hbrush);
                DeleteObject(hbrushOld);
            }
            else
                if (pDoc->Mp[i]->q > 0)
                {
                    hbrush = CreateSolidBrush(RGB(255, 0, 0));
                    hbrushOld = (HBRUSH)SelectObject(hdc, hbrush);
                    Ellipse(hdc, (int)(pDoc->Mp[i]->X + Dzx), (int)(pDoc->Mp[i]->Y + Dzy), (int)(pDoc->Mp[i]->X + Dzx + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)(pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax));
                    DeleteObject(hbrush);
                    DeleteObject(hbrushOld);
                }
                else
                    if (pDoc->Mp[i]->q < 0)
                    {
                        hbrush = CreateSolidBrush(RGB(0, 0, 255));
                        hbrushOld = (HBRUSH)SelectObject(hdc, hbrush);
                        Ellipse(hdc, (int)(pDoc->Mp[i]->X + Dzx), (int)(pDoc->Mp[i]->Y + Dzy), (int)(pDoc->Mp[i]->X + Dzx + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax), (int)(pDoc->Mp[i]->Y + Dzy + 5000000 * pDoc->Mp[i]->R + pDoc->Mp[i]->Z * pDoc->Mp[i]->R / pDoc->Zmax));
                        DeleteObject(hbrush);
                        DeleteObject(hbrushOld);
                    }
        }
    }
    DeleteObject(pDoc);
}



// Печать CMFCApplication1View


void CMFCApplication1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}

void CMFCApplication1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCApplication1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Диагностика CMFCApplication1View

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif _DEBUG


// Обработчики сообщений CMFCApplication1View
