#include <wcplugin.h>
#include <wcpluginsp.h>


uint8_t wcMEZZ(wcWindow* win, uint8_t nmsg, const char* msgtable, uint8_t x, uint8_t y)__naked{
	win;msgtable;x;y;nmsg;
__asm;
	iy_init

	; win
	get_ix
	
	; message number
	get_a
	ex	af,af';'
	
	; text (messages table)
	get_hl
	
	; x y
	get_de
	
	;
	ld	a,#12
	wcentry
	;// o: D - Y (след строка)
	;//    E - X (без изменений)
	ld l,e 
	procret
__endasm;
}
