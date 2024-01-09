#include "pch.h"
#include "CmfcFindDlg.h"
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2024 01 04 ë©”ëª¨ìž¥ ì°¾ê¸° ë°”ê¾¸ê¸° êµ¬í˜„
#include "framework.h"
#include "MFC_Memo.h"
#include "MFC_MemoDlg.h"
#include "afxdialogex.h"
<<<<<<< HEAD
=======
>>>>>>> MFC 2ì¼ì°¨
=======
>>>>>>> 2024 01 04 ë©”ëª¨ìž¥ ì°¾ê¸° ë°”ê¾¸ê¸° êµ¬í˜„


BEGIN_MESSAGE_MAP(CmfcFindDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2024 01 04 ë©”ëª¨ìž¥ ì°¾ê¸° ë°”ê¾¸ê¸° êµ¬í˜„
CmfcFindDlg::CmfcFindDlg() : CDialogEx(IDD_FIND_DIALOG)
{

}

<<<<<<< HEAD
=======
>>>>>>> MFC 2ì¼ì°¨
=======
>>>>>>> 2024 01 04 ë©”ëª¨ìž¥ ì°¾ê¸° ë°”ê¾¸ê¸° êµ¬í˜„

void CmfcFindDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ¿©±â¿¡ ¸Þ½ÃÁö Ã³¸®±â ÄÚµå¸¦ Ãß°¡ ¹×/¶Ç´Â ±âº»°ªÀ» È£ÃâÇÕ´Ï´Ù.
	switch (nChar)
	{
	case VK_RETURN:
		GetDlgItem(ID_EDIT_FIND)->GetWindowText(mStr);
<<<<<<< HEAD
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
>>>>>>> MFC 2ì¼ì°¨
=======
		GetDlgItem(ID_EDIT_REPLACE)->GetWindowText(mStr2);
		break;
	case VK_ESCAPE:
		mStr = "";
		mStr2 = "";
>>>>>>> 2024 01 04 ë©”ëª¨ìž¥ ì°¾ê¸° ë°”ê¾¸ê¸° êµ¬í˜„
		break;
	default:
		break;
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CmfcFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ¿©±â¿¡ Ãß°¡ ÃÊ±âÈ­ ÀÛ¾÷À» Ãß°¡ÇÕ´Ï´Ù.
<<<<<<< HEAD
<<<<<<< HEAD
	mStr = "";
	mStr2 = "";
=======
>>>>>>> MFC 2ì¼ì°¨
=======
	mStr = "";
	mStr2 = "";
>>>>>>> 2024 01 04 ë©”ëª¨ìž¥ ì°¾ê¸° ë°”ê¾¸ê¸° êµ¬í˜„

	return TRUE;  // return TRUE unless you set the focus to a control
	// ¿¹¿Ü: OCX ¼Ó¼º ÆäÀÌÁö´Â FALSE¸¦ ¹ÝÈ¯ÇØ¾ß ÇÕ´Ï´Ù.
}
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 2024 01 04 ë©”ëª¨ìž¥ ì°¾ê¸° ë°”ê¾¸ê¸° êµ¬í˜„


void CmfcFindDlg::DoDataExchange(CDataExchange* pDX)
{
	// TODO: ¿©±â¿¡ Æ¯¼öÈ­µÈ ÄÚµå¸¦ Ãß°¡ ¹×/¶Ç´Â ±âº» Å¬·¡½º¸¦ È£ÃâÇÕ´Ï´Ù.

	CDialogEx::DoDataExchange(pDX);
}


BOOL CmfcFindDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ¿©±â¿¡ Æ¯¼öÈ­µÈ ÄÚµå¸¦ Ãß°¡ ¹×/¶Ç´Â ±âº» Å¬·¡½º¸¦ È£ÃâÇÕ´Ï´Ù.
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
<<<<<<< HEAD
=======
>>>>>>> MFC 2ì¼ì°¨
=======
>>>>>>> 2024 01 04 ë©”ëª¨ìž¥ ì°¾ê¸° ë°”ê¾¸ê¸° êµ¬í˜„
