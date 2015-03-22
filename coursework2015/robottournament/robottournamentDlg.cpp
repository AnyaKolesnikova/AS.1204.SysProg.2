
// robottournamentDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "robottournament.h"
#include "robottournamentDlg.h"
#include "afxdialogex.h"
//#include "CfieldDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// ���������� ���� CrobottournamentDlg



CrobottournamentDlg::CrobottournamentDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CrobottournamentDlg::IDD, pParent)
	, fieldHeight(1000)
	, fieldWidth(1000)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CrobottournamentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, fieldHeight);
	DDX_Text(pDX, IDC_EDIT2, fieldWidth);
}

BEGIN_MESSAGE_MAP(CrobottournamentDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CrobottournamentDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ����������� ��������� CrobottournamentDlg

BOOL CrobottournamentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CrobottournamentDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CrobottournamentDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CrobottournamentDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CrobottournamentDlg::OnBnClickedOk()
{
	// TODO: �������� ���� ��� ����������� �����������
	
	//data *Data = new data;
	UpdateData(TRUE);
	if (fieldHeight < 20 || fieldWidth < 20)
		AfxMessageBox("���� ������� ���������");
	else
	{
		Data.fieldHeight = fieldHeight;
		Data.fieldWidth = fieldWidth;
		Data.rivals=10;
		Field.FieldParameters = Data;

		Field.matrix = new int*[fieldWidth];
		for (int i=0; i<fieldWidth; i++)
			Field.matrix[i] = new int[fieldHeight];
		for (int i=0; i<fieldWidth; i++)
		{
			for (int j=0; j<fieldHeight; j++)
				Field.matrix[i][j] = 0;
		}
		Field.matrix[10][3] = 1;		//TEST!!!!!!!!!!!!!!!!!!!!!!
		Field.matrix[5][8] = 1;		//////////////
		Field.matrix[25][10] = 1;		//////////////right
		Field.matrix[30][8] = 1;		//////////////
		Field.matrix[21][10] = 1;		//////////////
		Field.matrix[10][21] = 1;		//////////////bottom
		Field.matrix[15][30] = 1;		//////////////
		Field.matrix[7][24] = 1;		//////////////

		this->ShowWindow(SW_HIDE);
		Field.DoModal();
		CDialogEx::OnOK();
	}
}
