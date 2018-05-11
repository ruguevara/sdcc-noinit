#include <winprocs.h>
#include <winshifts.h>
#include "printscale.h"

#include "uSctrollText.h"

/**
 * -------------------------------- ������� ������ ------------------------------------------
 * ��� ������� � ������� �� ���-��� �����:)
 */
enum {
	// ��������� ��������.
	// ���� ����������, �� ����� ����� �� ���������
	wshStatDelay=0,
	// ��������� ���������.
	// ����� ��������� �� 8 �������� - ��������� ����� �����
	wshStatShift=1,
};

// ����������, �����. ����� ����� (< 64� )
static char ShiftText[]=
        "������������ ���� �� �̣�� CSP2018!!! "
        "��������� ��� ������� 28-29 ���� 2018 ���� � ������ ������������! "
        "���������� ����, ���� ����� � �� �����, ��������: "
        "AAA, AER, Alex Clap, aturbidflow, Baxter, BlackCat, BlastOff, Buddy, Burst, "
        "Canifol, Cardinal, Connect-2000, Corvax, Creator, Daniel, Debosh, Diamond, "
        "Djoni, dman, Dr.Bars, Fikus, Gibson, Grachev, Hrumer, John Norton Irr, "
        "Kakos_nonos, Kas29, Kowalski, Lzb, Maddev, Marinovsoft, Maxximum, "
        "Misha Pertsovsky, MMCM, Mr.Nick, MV1971, OLN, OTO-man, Quiet, Raider, "
        "RetroDroid, Sambura, Sayman, scalesmann^mc, shuran33, SlackDen, Sobos, "
        "Tiden, T!m0n, Tzerra, Voxon, wbc, wbr, Whitehalt, Xlat, ZeroXor, Zhizh, ZX_NOVOSIB, �����... "
        "� ������!!! ��������, ���� ����-�� �� ���������. ��� �����, � �� ����:) ���������� ��� ��� �����! "
        ;

// ������� ��������� ������
static char* charShiftText=ShiftText;
// ������� ������� ������� (��� �������� 8 - ���� �������� ���������)
static uint8_t symShiftCounter=0;
// �������� ������ (� 1/50)
static int8_t ShiftTextDelay=5;
// ���� ������
static const winShift winShiftText = {0,22,32,2};
// ��������� (�������� ��� �����)
static uint8_t winShiftStatus=wshStatDelay;
// ������� ������� � ��������� ��������
static uint16_t winShiftDelayCounter;

// ������ ��������� ��������� ������ (������ �� ������:)
void InitShiftText() {
	winSetAtr(31, 22, 1, 2, 0x00, 0xFF);
}

// �����
void CheckShiftText() {
	// ��������� ������� ��������
	if ( (--ShiftTextDelay)<=0 ) {
		// ����� �� 1 �������
		shiftLeftPix(&winShiftText);
		ShiftTextDelay=2;
	} else {
		// �����, ������� �������� �� ���� �� ����
		return;
	}

	// ����������� ������� ������.
	// ���� �� ����� 8, �� ���� �������� ��������� ������
	if ( (++symShiftCounter) >= 8 ) {
		// ���� ��������� ��������, �� ���������,
		// ����������� �� ���
		if ( winShiftStatus == wshStatDelay ) {
			winShiftDelayCounter++;
			if (winShiftDelayCounter >= 256 ) {
				winShiftStatus = wshStatShift;
				winSetAtr(0, 22, 31, 2, 0104, 0xFF);
			}
		}
		// ��������� ���������
		else {
			symShiftCounter=0;
			// ���� ����� �� ����� ������,
			// �� ������� � ��������� ��������
			if (!*charShiftText) {
				charShiftText=ShiftText;
				winShiftStatus = wshStatDelay;
				winShiftDelayCounter=0;
			}
			// ����� ����� ���������� �������
			else {
				printScale(31,22,2,*charShiftText);
				charShiftText++;
			}
		}
	}
}
