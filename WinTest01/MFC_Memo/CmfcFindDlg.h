#pragma once
#include <afxdialogex.h>
class CmfcFindDlg :
    public CDialogEx
{
public:
    CString mStr = "";
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
};

