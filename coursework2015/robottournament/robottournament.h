
// robottournament.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CrobottournamentApp:
// � ���������� ������� ������ ��. robottournament.cpp
//

class CrobottournamentApp : public CWinApp
{
public:
	CrobottournamentApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CrobottournamentApp theApp;