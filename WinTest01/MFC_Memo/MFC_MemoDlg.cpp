
// MFC_MemoDlg.cpp: 구현 파일
//


#include "pch.h"
#include "framework.h"
#include "MFC_Memo.h"
#include "MFC_MemoDlg.h"
#include "afxdialogex.h"
<<<<<<< HEAD
<<<<<<< HEAD
#include "CmfcFindDlg.h"
=======
>>>>>>> MFC 2일차
=======
#include "CmfcFindDlg.h"
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <fstream>
#include <cstring>
#include <iostream>

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCMemoDlg 대화 상자



CMFCMemoDlg::CMFCMemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_MEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCMemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
<<<<<<< HEAD
<<<<<<< HEAD
	DDX_Control(pDX, IDC_EDIT_MEMO, mEditMemo);
=======
>>>>>>> MFC 2일차
=======
	DDX_Control(pDX, IDC_EDIT_MEMO, mEditMemo);
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
}

BEGIN_MESSAGE_MAP(CMFCMemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
<<<<<<< HEAD
<<<<<<< HEAD
	ON_EN_CHANGE(IDC_EDIT_MEMO, &CMFCMemoDlg::OnEnChangeEdit1)
	ON_COMMAND(ID_Menu_Open, &CMFCMemoDlg::OnMenuOpen)
	ON_COMMAND(ID_Menu_About, &CMFCMemoDlg::OnMenuAbout)
	ON_COMMAND(ID_Menu_Find, &CMFCMemoDlg::OnMenuFind)
	ON_COMMAND(ID_Menu_NextFind, &CMFCMemoDlg::OnMenuNextfind)
	ON_COMMAND(ID_Menu_UTF8, &CMFCMemoDlg::OnMenuUtf8)
	ON_COMMAND(ID_Menu_ANSI, &CMFCMemoDlg::OnMenuAnsi)
	ON_COMMAND(ID_Menu_Replace, &CMFCMemoDlg::OnMenuReplace)
	ON_COMMAND(IDC_BUTTON1, &CMFCMemoDlg::OnButton1)
=======
	ON_EN_CHANGE(IDC_EDIT1, &CMFCMemoDlg::OnEnChangeEdit1)
	ON_COMMAND(ID_Menu_Open, &CMFCMemoDlg::OnMenuOpen)
	ON_COMMAND(ID_Menu_About, &CMFCMemoDlg::OnMenuAbout)
>>>>>>> MFC 2일차
=======
	ON_EN_CHANGE(IDC_EDIT_MEMO, &CMFCMemoDlg::OnEnChangeEdit1)
	ON_COMMAND(ID_Menu_Open, &CMFCMemoDlg::OnMenuOpen)
	ON_COMMAND(ID_Menu_About, &CMFCMemoDlg::OnMenuAbout)
	ON_COMMAND(ID_Menu_Find, &CMFCMemoDlg::OnMenuFind)
	ON_COMMAND(ID_Menu_NextFind, &CMFCMemoDlg::OnMenuNextfind)
	ON_COMMAND(ID_Menu_UTF8, &CMFCMemoDlg::OnMenuUtf8)
	ON_COMMAND(ID_Menu_ANSI, &CMFCMemoDlg::OnMenuAnsi)
	ON_COMMAND(ID_Menu_Replace, &CMFCMemoDlg::OnMenuReplace)
	ON_COMMAND(IDC_BUTTON1, &CMFCMemoDlg::OnButton1)
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
END_MESSAGE_MAP()


// CMFCMemoDlg 메시지 처리기

BOOL CMFCMemoDlg::OnInitDialog()  // <- main class
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
<<<<<<< HEAD
<<<<<<< HEAD
	mAccel = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCEL1));
=======
>>>>>>> MFC 2일차
=======
	mAccel = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCEL1));
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCMemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCMemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCMemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCMemoDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFCMemoDlg::OnMenuOpen() //file open menu 처리기
{
	char buf[512];
	CString str;

	char fName[100];
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn)); // 메모리 공간 청소
	ZeroMemory(fName, sizeof(fName));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.lpstrFile = fName;
	ofn.nMaxFile = 100;
	ofn.lpstrDefExt = "";

	if (!GetOpenFileName(&ofn)) return;

	str = buf; //CString <== WCHAR, CString <== char
<<<<<<< HEAD
<<<<<<< HEAD


	/* C 언어 표준 함수 ANSI encoding 방법*/
	if (mEncoding == 0) {
		FILE* fp = fopen(fName, "rb");
		while (fgets(buf, 512, fp))
		{
			((CEdit*)GetDlgItem(IDC_EDIT_MEMO))->GetWindowText(str);
			GetDlgItem(IDC_EDIT_MEMO)->SetWindowText(str + buf);
		}
	}
	
	/* C++ 언어 Stream 표준 UTF-8 encoding 방법 */
	else if (mEncoding == 1) {
		wchar_t buf1[512];
		std::locale::global(std::locale(".UTF-8"));
		std::wifstream ff(fName);
		//ff.open(fName);
		for (; ff.getline(buf1, 512);)
		{
			str = buf1;
			AddText(str); AddText("\r\n");
			/*((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(str);
			str += buf1; str += "\r\n";
			GetDlgItem(IDC_EDIT1)->SetWindowText(str);*/
		}
=======
	
=======
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현


	/* C 언어 표준 함수 ANSI encoding 방법*/
	if (mEncoding == 0) {
		FILE* fp = fopen(fName, "rb");
		while (fgets(buf, 512, fp))
		{
			((CEdit*)GetDlgItem(IDC_EDIT_MEMO))->GetWindowText(str);
			GetDlgItem(IDC_EDIT_MEMO)->SetWindowText(str + buf);
		}
	}
	
	/* C++ 언어 Stream 표준 UTF-8 encoding 방법 */
<<<<<<< HEAD
	wchar_t buf1[512];
	std::locale::global(std::locale(".UTF-8"));
	std::wifstream ff(fName);
	//ff.open(fName);
	for (; ff.getline(buf1, 512);)
	{
		((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(str);
		str += buf1; str += "\r\n";
		GetDlgItem(IDC_EDIT1)->SetWindowText(str);
>>>>>>> MFC 2일차
=======
	else if (mEncoding == 1) {
		wchar_t buf1[512];
		std::locale::global(std::locale(".UTF-8"));
		std::wifstream ff(fName);
		//ff.open(fName);
		for (; ff.getline(buf1, 512);)
		{
			str = buf1;
			AddText(str); AddText("\r\n");
			/*((CEdit*)GetDlgItem(IDC_EDIT1))->GetWindowText(str);
			str += buf1; str += "\r\n";
			GetDlgItem(IDC_EDIT1)->SetWindowText(str);*/
		}
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
	}
	// 1. open 2. Read / Write 3. close 
	// 표준함수 fopen Func : agument 1. file 경로 2. open Mode (읽기,쓰기)
	// 
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
void CMFCMemoDlg::AddText(CString s) {
	
	CString str;
	((CEdit*)GetDlgItem(IDC_EDIT_MEMO))->GetWindowText(str);
	str += s;
	GetDlgItem(IDC_EDIT_MEMO)->SetWindowText(str);
}
<<<<<<< HEAD
=======

>>>>>>> MFC 2일차
=======
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현


void CMFCMemoDlg::OnMenuAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
}
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현



void CMFCMemoDlg::OnMenuFind()
{
	CmfcFindDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CString s;
		mSearchString = dlg.mStr;
		mEditMemo.GetWindowText(s);
		Start = s.Find(mSearchString);
		End = Start + mSearchString.GetLength();
		mEditMemo.SetSel(Start,End);
		
		//AddText(dlg.mStr);
	}

}

void CMFCMemoDlg::OnMenuNextfind()
{
	CString s;
	mEditMemo.GetWindowText(s);

	Start = s.Find(mSearchString, End);
	End = Start + mSearchString.GetLength();
	mEditMemo.SetSel(Start, End);  
}

void CMFCMemoDlg::OnMenuReplace()
{
	CmfcFindDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CString s;
		mSearchString = dlg.mStr; // 찾을 문자열
		mEditMemo.GetWindowText(s);

		// 현재 선택된 텍스트의 시작과 끝 위치를 가져옴
		int Start, End;
		mEditMemo.GetSel(Start, End);

		Start = s.Find(mSearchString);

		End = Start + mSearchString.GetLength();
		mEditMemo.SetSel(Start, End);

		// dlg.mStr2로 대체
		CString newText = dlg.mStr2; // 대체할 문자열
		mEditMemo.ReplaceSel(newText);

	}

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


BOOL CMFCMemoDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (mAccel)
	{
		if (TranslateAccelerator(m_hWnd, mAccel, pMsg))	return true;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMFCMemoDlg::OnMenuUtf8()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMenu* m = GetMenu();
	m->CheckMenuItem(ID_Menu_UTF8, MF_CHECKED);
	m->CheckMenuItem(ID_Menu_ANSI, MF_UNCHECKED);
	mEncoding = 1;
}

void CMFCMemoDlg::OnMenuAnsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CMenu* m = GetMenu();
	m->CheckMenuItem(ID_Menu_UTF8, MF_UNCHECKED);
	m->CheckMenuItem(ID_Menu_ANSI, MF_CHECKED);
	mEncoding = 0;
}


void CMFCMemoDlg::OnButton1()
{

}
<<<<<<< HEAD
=======
>>>>>>> MFC 2일차
=======
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
