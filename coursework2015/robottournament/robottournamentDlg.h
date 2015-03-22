
// robottournamentDlg.h : ���� ���������
//

#pragma once
#include "FieldParameters.h"
#include "CfieldDlg.h"

// ���������� ���� CrobottournamentDlg
class CrobottournamentDlg : public CDialogEx
{
// ��������
public:
	CrobottournamentDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_ROBOTTOURNAMENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CfieldDlg Field;
	data Data;
	afx_msg void OnBnClickedOk();
	int fieldHeight;
	int fieldWidth;
};


