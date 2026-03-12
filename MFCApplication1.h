
// fRSH5.h: основной файл заголовка для приложения fRSH5
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif
#include "stdafx.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Resource.h"
//#include "CACTIVEXREPORTVIEWER1.h"
//#include "CCRVIEWER4.h"
//#include "COCX1.h"
#include "ocx1.h"
#include "CACTIVEXREPORTVIEWER1.h"
#define CACTIVEXREPORTVIEWER1_CLASSNAME _T("COcx1")
#define CACTIVEXREPORTVIEWER2_CLASSNAME _T("CACTIVEXREPORTVIEWER1")

//#define CACTIVEXREPORTVIEWER1_CLASSNAME _T("CReportDlg")

class CReportDlg2 : public CDialogEx
{
	// Construction
public:
	DECLARE_DYNAMIC(CReportDlg2);
	CReportDlg2();
	BOOL Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle /*=WS_VISIBLE*/);
	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif
	void OnCrystalDlg2();
	//afx_msg void OnDisplay1();
	BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CReportDlg2)
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedOk();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG

	BOOL RegisterWindowClass();
protected:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReportDlg2)
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL
// Implementation
protected:
		HICON m_hIcon;

	DECLARE_MESSAGE_MAP()
public:

//	CACTIVEXREPORTVIEWER1 mCRView1;

	DECLARE_EVENTSINK_MAP()
//	void CloseButtonClickedCrviewer4(BOOL* UseDefault);
//	CCRVIEWER4 mCView1;
//	void CloseButtonClicked(BOOL* UseDefault);
	void CloseButtonClickedCrviewer4(BOOL* UseDefault);
	CACTIVEXREPORTVIEWER1 mCView1;
};

class CReportDlg : public CDialogEx
{
	// Construction
public:
	DECLARE_DYNAMIC(CReportDlg);
	CReportDlg();
	BOOL Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle /*=WS_VISIBLE*/);
	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif
	void OnCrystalDlg1();
	BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CReportDlg)
	//afx_msg void OnDisplay1();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	BOOL RegisterWindowClass();
protected:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReportDlg)
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL
// Implementation
protected:
		HICON m_hIcon;
	DECLARE_MESSAGE_MAP()
public:
	
	COCX1 pRepDlg2;
};

/////////////////////////////////////////////////////////////////////////////
// CDisplay_CrystalrptDlg dialog

class CDisplay_CrystalrptDlg : public CDialogEx
{
	// Construction
public:
	DECLARE_DYNAMIC(CDisplay_CrystalrptDlg);
	CDisplay_CrystalrptDlg();
	BOOL Create(CWnd* pParentWnd, const RECT& rect, UINT nID, DWORD dwStyle /*=WS_VISIBLE*/);
	// standard constructor

// Dialog Data
	
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif
	void OnCrystalDlg();
	//afx_msg void OnDisplay1();
	BOOL OnInitDialog();
	// Generated message map functions
	//{{AFX_MSG(CDisplay_CrystalrptDlg)
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	BOOL RegisterWindowClass();
protected:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisplay_CrystalrptDlg)
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL
// Implementation
protected:
	HICON m_hIcon;
	
	DECLARE_MESSAGE_MAP()
public:
	CListBox pList;
	CListBox pList2;
	CListBox pList3;
};

class CFrModInCndDlg :public CDialogEx
{
public:
	int m_Npat;
	double m_dt;
	int m_rd;
	CFrModInCndDlg();
	~CFrModInCndDlg();
	void OnFrMod_InCnd();
	BOOL OnInitDialog();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FrModInCnd };
#endif
protected:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrModInCndDlg)
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV
	//}}AFX_VIRTUAL
	// Реализация
protected:

	void OnChangeEdit1();
	void OnChangeEdit2();
/*	void OnBnClickedRadio1();
	void OnBnClickedRadio2();
	*/
	void OnCancel();
	DECLARE_MESSAGE_MAP();
};

// CfRSH5App:
// Сведения о реализации этого класса: fRSH5.cpp
//
class CMFCApplication1App : public CWinAppEx
{
public:
	CMFCApplication1App();
// Переопределение
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CfRSH5App)
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();
	//}}AFX_VIRTUAL
	// Реализация
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;
	
	BOOL CMFCApplication1App::OnIdle(LONG lCount);

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CReportDlg2 cRepDlg2;
extern CReportDlg cRepDlg;
extern CDisplay_CrystalrptDlg CrystalrptDlg;
extern CMFCApplication1App theApp;
extern CFrModInCndDlg FrModInCndDlg;

