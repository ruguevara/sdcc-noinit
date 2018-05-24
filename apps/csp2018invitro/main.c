#include <types.h>
#include <string.h>
#include <stdint.h>
#include <im2.h>
#include <zxkbd.h>
#include <winprocs.h>

#include "equalizer.h"
#include "cspLogo.h"
#include "spr2018.h"
#include "uSctrollText.h"
#include "logos.h"
#include "music.h"

/**
 * -------------------------------- ���������� ------------------------------------------
 */

/*
 * ���������� ���������� 1/50 ���
 */

static void im2userHandler() {
	// ����������, ����������� ��������� ������ ������� ��������
	static volatile uint8_t lock;

	// ������ ��������� ������� ������
	if ( music_im2h ) {
		music_im2h();
	}

	// �����������
	logos_int50();

	// �������� ���������� ������ (��� � ����������!)
	if ( lock ) {
		return;
	}

	// ��������� ��������� ���� � ���� ������� ����
	lock=1;
	// ��������� ����������.
	SEI();

	// ����� ������
	CheckShiftText();

	// ��������� �����������
	equalizer_draw();

	// �������� ������� �����
	candle_flame_animate();

	// ��� �������� ����
	logoAniStep();

	// ����� ���������� (� ����, �.�. ������ �������� 1-6 �����)
	zxKbdScan();
	// �������� - � ����� ���� ������� �������?
	keyMusic ( zxKbdInKey() );

	// ������������ ���� � ���� ������� ����
	CLI();
	lock=0;
	SEI();
}

// ������ BORDER 0
void border0() __naked {
	__asm;
	xor a
	out ( 0xFE ),a
	ret
	__endasm;
}

int main() {
	// ��������� � ���������
	CLI();
	
	// ���� ���������� ����������
	im2Set();
	im2SetHandler ( im2userHandler );
	
	// ������� ������
	border0();
	winSetAtr ( 0, 0, 32, 24, 0x00, 0xFF );
	winClear ( 0,0,32,8 );
	// ����� ��������
	
	// CSP (������� ������ ������)
	logoToScreen ( 3,0 );
	
	// CSP2018 (���������� ����� ������)
	spr2018_put();
	
	// �������� ������
	logos_put();
	
	// ������������� ������ ������
	InitShiftText();

	// ��������� ����������
	SEI();

	// �������� ����
	while ( 1 ) {
		// �������� - �������� �� �� ����� ������
		// � ���� �� ���������� � ��������� �������
		checkMusic();
		
		// �������� � ����� �������� ������ �� �����
		logos_check();
	}

	//
	return 0;
}
