#include "multimenu.h"

// ������� ����
static window mm_win, info_win;
// 4 ����
static menuv  m1,m2,m3;

// ������� �������� ����
static const window* mm_win_childs[] = {&(m1.win), &(m2.win), &(m3.win), &info_win , 0 };

// �������� ���� 1
static const wRect	m1rect= {{2,2},{12,8}};
static const menu_item	m1items[]= {
	{"���� 1.1",0},
	{"���� 1.2",0 },
	{"���� 1.3",0},
	{"���� 1.4",0},
	{"���� 1.5",0 },
	{"���� 1.6",0},
	//
	{0,0},
};

// �������� ���� 2
static const wRect	m2rect= {{18,2},{12,8}};
static const menu_item	m2items[]= {
	{"���� 2.1",0},
	{"���� 2.2",0 },
	{"���� 2.3",0},
	{"���� 2.4",0},
	{"���� 2.5",0 },
	{"���� 2.6",0},
	//
	{0,0},
};

// �������� ���� 3
static const wRect	m3rect= {{2,14},{12,8}};
static const menu_item	m3items[]= {
	{"���� 3.1",0},
	{"���� 3.2",0 },
	{"���� 3.3",0},
	{"���� 3.4",0},
	{"���� 3.5",0 },
	{"���� 3.6",0},
	//
	{0,0},
};
// ���� � �����������
static const wRect	info_win_rect= {{18,14},{12,8}};

static void info_win__draw(window* this) {
	window_draw(this);
	this->at(this, 3, 0 );
	this->puts(this, "������.");
	this->at(this, 2, 2 );
	this->puts(this, "��� ����");
	this->at(this, 4, 3 );
	this->puts(this, "��");
	this->at(this, 2, 4 );
	this->puts(this, "�������!");
}

void multiMenuExec(struct menuv* m) {
	//
	menuv_init(&m1,m1items,&m1rect);
	window_set_color(&m1.win,0130,000);
	m1.header = "[ ���� 1 ]";
	
	menuv_init(&m2,m2items,&m2rect);
	window_set_color(&m2.win,0160,001);
	m2.header = "[ ���� 2 ]";
	
	menuv_init(&m3,m3items,&m3rect);
	window_set_color(&m3.win,0120,0107);
	m3.header = "[ ���� 3 ]";
	//
	window_init(&info_win);
	window_setsize(&info_win,&info_win_rect);
	window_set_color(&info_win,040,000);
	info_win.border = btSingl;
	info_win.winFlags&=~wflagActivate; // ��� �� ����� ���� ��������
	info_win.draw = info_win__draw;
	//
	window_init(&mm_win);
	window_set_color(&mm_win,000,050);
	// ��������� �������� � ������ �������� ������� �� ���
	mm_win.childs=mm_win_childs;
	mm_win.cur_child=0;
	//
	window_exec(&mm_win);
}
