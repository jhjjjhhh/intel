#include "pch.h"
#include "CmfcFindDlg.h"
<<<<<<< HEAD
#include "framework.h"
#include "MFC_Memo.h"
#include "MFC_MemoDlg.h"
#include "afxdialogex.h"
=======
>>>>>>> MFC 2일차


BEGIN_MESSAGE_MAP(CmfcFindDlg, CDialogEx)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

<<<<<<< HEAD
CmfcFindDlg::CmfcFindDlg() : CDialogEx(IDD_FIND_DIALOG)
{

}

=======
>>>>>>> MFC 2일차

void CmfcFindDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
>>>>>>> MFC 2일차
		break;
	default:
		break;
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}

BOOL CmfcFindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
<<<<<<< HEAD
	mStr = "";
	mStr2 = "";
=======
>>>>>>> MFC 2일차

	return TRUE;  // return TRUE unless you set the focus to a control
	// ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
<<<<<<< HEAD


void CmfcFindDlg::DoDataExchange(CDataExchange* pDX)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	CDialogEx::DoDataExchange(pDX);
}


BOOL CmfcFindDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
>>>>>>> MFC 2일차
