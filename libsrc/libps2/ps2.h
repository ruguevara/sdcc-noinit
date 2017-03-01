#ifndef PS2_H_DEFINED
#define PS2_H_DEFINED

#include <types.h>
#include "ps2_const.h"

/**
	�������������.
*/
void InitPS2()__naked;

/**
	�������� ����-��� � �����.
	��������� � �� ����� ������
*/
WORD GetPS2()__naked;

/**
	��������� ������� �������.
	������� ����, ��� 0 (KEXTEND) ���������� -
	������� ������� ��� ��������������. ������� ���� - ��� �������
	� �ޣ��� �������� � ���������. KOI8-R
*/
WORD InKey()__naked;

/**
	�������� - ����� �� CTRL (0-�� �����)
*/
BYTE IsCTRL()__naked;

/**
	�������� - ����� �� ALT (0-�� �����)
*/
BYTE IsALT()__naked;

/**
	�������� - ����� �� SHIFT (0-�� �����)
*/
BYTE IsSHIFT()__naked;

/**
	�������� - �������� (0 - ���., ����� ���.)
*/
BYTE IsRUS()__naked;

/**
	�������� - �������� (0 - ��������, ����� - ���������)
*/
BYTE IsUPPER()__naked;

#endif /* PS2_H_DEFINED */
