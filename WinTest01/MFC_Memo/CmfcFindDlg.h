#pragma once
#include <afxdialogex.h>
class CmfcFindDlg :
    public CDialogEx
{
public:
    CString mStr = "";
<<<<<<< HEAD
<<<<<<< HEAD
    CString mStr2 = "";
    CmfcFindDlg();
    
#ifdef AFX_DESIGN_TIME
    enum { IDO = IDO_FIND_DIALOG };
#endif

    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    virtual BOOL OnInitDialog();
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

    virtual BOOL PreTranslateMessage(MSG* pMsg);
=======
=======
    CString mStr2 = "";
    CmfcFindDlg();
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
    
#ifdef AFX_DESIGN_TIME
    enum { IDO = IDO_FIND_DIALOG };
#endif

    afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    virtual BOOL OnInitDialog();
<<<<<<< HEAD
>>>>>>> MFC 2일차
=======
    virtual void DoDataExchange(CDataExchange* pDX);

    DECLARE_MESSAGE_MAP()

    virtual BOOL PreTranslateMessage(MSG* pMsg);
>>>>>>> 2024 01 04 메모장 찾기 바꾸기 구현
};

