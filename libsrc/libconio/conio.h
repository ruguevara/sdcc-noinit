#ifndef CONIO_H_DEFINED
#define CONIO_H_DEFINED

#include <types.h>
#include <stdio.h>
#include "conio_const.h"

/**
 * ������ ������ (� ������������ ��������� - AT, TAB..)
 */
void print(const char* s)__naked;

/**
 * ������� ������ ������� ������
 */
void cls()__naked;

/**
 * ������� ������ �������� ������
 */
void ccls(BYTE c)__naked;

/**
 * ���������� ���������� �����
 */
void color(BYTE c)__naked;

void conio_setopt_nop()__naked;
void conio_setopt_and()__naked;
void conio_setopt_or()__naked;
void conio_setopt_xor()__naked;

void conio_at(uint8_t x, uint8_t y);

void conio_where(uint8_t* x, uint8_t* y);

#endif /* CONIO_H_DEFINED */
