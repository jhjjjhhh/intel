#include "pch.h"
#include "CmfcFindDlg.h"
<<<<<<< HEAD
#include "framework.h"
#include "MFC_Memo.h"
#include "MFC_MemoDlg.h"
#include "afxdialogex.h"
=======
>>>>>>> MFC 2ÏùºÏ∞®


BEGIN_MESSAGE_MAP(CmfcFindDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

<<<<<<< HEAD
CmfcFindDlg::CmfcFindDlg() : CDialogEx(IDD_FIND_DIALOG)
{

}

=======
>>>>>>> MFC 2ÏùºÏ∞®

void CmfcFindDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ø©±‚ø° ∏ﬁΩ√¡ˆ √≥∏Æ±‚ ƒ⁄µÂ∏¶ √ﬂ∞° π◊/∂«¥¬ ±‚∫ª∞™¿ª »£√‚«’¥œ¥Ÿ.
	switch (nChar)
	{
	case VK_RETURN:
		GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
<<<<<<< HEAD
		GetDlgItem(ID_EDIT_REPLACE)->GetWindowText(mStr2);
		break;
	case VK_ESCAPE:
		mStr = "";
		mStr2 = "";
=======
		break;
	case VK_ESCAPE:
		mStr = "";
>>>>>>> MFC 2ÏùºÏ∞®
		break;
	default:
		break;
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CmfcFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ø©±‚ø° √ﬂ∞° √ ±‚»≠ ¿€æ˜¿ª √ﬂ∞°«’¥œ¥Ÿ.
<<<<<<< HEAD
	mStr = "";
	mStr2 = "";
=======
>>>>>>> MFC 2ÏùºÏ∞®

	return TRUE;  // return TRUE unless you set the focus to a control
	// øπø‹: OCX º”º∫ ∆‰¿Ã¡ˆ¥¬ FALSE∏¶ π›»Ø«ÿæﬂ «’¥œ¥Ÿ.
}
<<<<<<< HEAD


void CmfcFindDlg::DoDataExchange(CDataExchange* pDX)
{
	// TODO: ø©±‚ø° ∆Øºˆ»≠µ» ƒ⁄µÂ∏¶ √ﬂ∞° π◊/∂«¥¬ ±‚∫ª ≈¨∑°Ω∫∏¶ »£√‚«’¥œ¥Ÿ.

	CDialogEx::DoDataExchange(pDX);
}


BOOL CmfcFindDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ø©±‚ø° ∆Øºˆ»≠µ» ƒ⁄µÂ∏¶ √ﬂ∞° π◊/∂«¥¬ ±‚∫ª ≈¨∑°Ω∫∏¶ »£√‚«’¥œ¥Ÿ.
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
			GetDlgItem(ID_EDIT_REPLACE)->GetWindowText(mStr2);
			EndDialog(IDOK);
			break;
		case VK_ESCAPE:
			mStr = "";
			mStr2 = "";
			EndDialog(IDCANCEL);
			break;
		default:
			break;
		}
	default:
		break;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
=======
>>>>>>> MFC 2ÏùºÏ∞®
