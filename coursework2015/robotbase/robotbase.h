// ����������� ���� ���� ifdef - ��� ����������� ����� �������� ��������, ���������� ��������� 
// �������� �� ��������� DLL. ��� ����� ������ DLL �������������� � �������������� ������� ROBOTBASE_EXPORTS,
// � ��������� ������. ���� ������ �� ������ ���� ��������� � �����-���� �������
// ������������ ������ DLL. ��������� ����� ����� ������ ������, ��� �������� ����� �������� ������ ����, ����� 
// ������� ROBOTBASE_API ��� ��������������� �� DLL, ����� ��� ������ DLL ����� �������,
// ������������ ������ ��������, ��� ����������������.
<<<<<<< HEAD

#include "robostuff.h"
=======
>>>>>>> origin/master
#ifdef ROBOTBASE_EXPORTS
#define ROBOTBASE_API __declspec(dllexport)
#else
#define ROBOTBASE_API __declspec(dllimport)
#endif

// ���� ����� ������������� �� robotbase.dll
class ROBOTBASE_API Crobotbase {
public:
	Crobotbase(void);
	// TODO: �������� ����� ���� ������.
};

extern ROBOTBASE_API int nrobotbase;

ROBOTBASE_API int fnrobotbase(void);

<<<<<<< HEAD
extern "C" ROBOTBASE_API void DoStep(stepinfo *Info, step *Step);
=======
extern "C" ROBOTBASE_API void DoStep();
>>>>>>> origin/master
