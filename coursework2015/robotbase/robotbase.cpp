// robotbase.cpp: ���������� ���������������� ������� ��� ���������� DLL.
//

#include "stdafx.h"
#include "robotbase.h"

using namespace std;

extern "C" 
void DoStep()
{
	AfxMessageBox("DLL");
	return;
}
