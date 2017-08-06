#ifndef PS2_H_DEFINED
#define PS2_H_DEFINED

#include <types.h>
#include <stdint.h>
#include "ps2_const.h"

/**
	�������������.
*/
void ps2Init();

/**
	��������� ������� �������.
	������� ����, ��� 0 (KEXTEND) ���������� -
	������� ������� ��� ��������������. ������� ���� - ��� �������
	� �ޣ��� �������� � ���������. KOI8-R
*/
uint16_t ps2InKey();

/**
	�������� - ����� �� CTRL (0-�� �����)
*/
uint8_t ps2IsCTRL();

/**
	�������� - ����� �� ALT (0-�� �����)
*/
uint8_t ps2IsALT();

/**
	�������� - ����� �� SHIFT (0-�� �����)
*/
uint8_t ps2IsSHIFT();

/**
	�������� - �������� (0 - ���., ����� ���.)
*/
uint8_t ps2IsRus();

/**
	�������� - �������� (0 - ��������, ����� - ���������)
*/
//BYTE IsUPPER();
uint8_t ps2IsCaps();

#endif /* PS2_H_DEFINED */
