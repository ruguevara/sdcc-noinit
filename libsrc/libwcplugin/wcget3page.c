#include <wcplugin.h>
#include <wcpluginsp.h>

uint16_t wcGetW0Page()__naked{
__asm;
	ld	hl,(wcheaderstart+03)
	ld	l,#0
	ret
__endasm;
}
