
// MFC_MemoDlg.h: 헤더 파일
//

#pragma once


// CMFCMemoDlg 대화 상자
class CMFCMemoDlg : public CDialogEx
{
<<<<<<< HEAD
<<<<<<< HEAD
	int mEncoding = 0; // 0 : ANSI , 1 = UTF 8
=======
>>>>>>> MFC 2일차
=======
	int mEncoding = 0; // 0 : ANSI , 1 = UTF 8
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
// 생성입니다.
public:
	CMFCMemoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_MEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;
<<<<<<< HEAD
<<<<<<< HEAD
	HACCEL mAccel;
=======
>>>>>>> MFC 2일차
=======
	HACCEL mAccel;
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnMenuOpen();
	afx_msg void OnMenuAbout();
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
	void AddText(CString s);
	afx_msg void OnMenuFind();
	CEdit mEditMemo;
	afx_msg void OnMenuNextfind();
	CString mSearchString;
	int Start;
	int End;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnMenuUtf8();
	afx_msg void OnMenuAnsi();
	afx_msg void OnMenuReplace();
	afx_msg void OnButton1();
<<<<<<< HEAD
=======
>>>>>>> MFC 2일차
=======
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
};
