/**
 * Обработка загруженных модулей (перемещение и проч.)
 */
#include <string.h>
#include "so.h"

#define onloadFuncSize	0x03

void* soReloc ( void* load_adr ) {
	uint8_t* code = ( uint8_t* ) load_adr;
	soHeader* h = ( soHeader* ) load_adr;
	uint16_t* reloc = ( uint16_t* ) ( code + h->reloctbl_offset );
	uint16_t len = * ( reloc++ );
	void ( *init ) () = ( void* ) ( code +sizeof ( soHeader ) );

	while ( len-- ) {
		uint8_t* w= code + * ( reloc++ );
		*w = *w + ( ( ( uint16_t ) load_adr ) >> 8 );
	}

	init();

	// Заголовок тоже привязывается к абсолютным адресам
	return h->reloctbl_offset;
}

extern const uint8_t _shared_links_begin[];
extern const uint8_t _shared_links_end[];

void* get_shared_links_area() {
	return _shared_links_begin;
}

void* get_shared_links_area_end() {
	return _shared_links_end;
}

void* tune_shared_obj ( soHeader* lib ) {
	const char*	name = lib->name;
	shared_link*	l=get_shared_links_area();
	
	// Empty library space
	if(!( ((uint16_t)(_shared_links_end)) - ((uint16_t)(_shared_links_begin)) )) {
		return NULL;
	}
	
	// Find
	while( l ){
		if( !strcmp(name, l->name) ){
			// Find!
			l->flags = 0; // @TODO@ - дорботка при переключении страниц
			l->page  = 0; // 
			//
			l->load_adr = lib;
			//
			return l;
		}
		// Continue
		l = l->next_link;
	}
	
	return(NULL);
}

soFuncDsc* getSoFuncDsc (soHeader* h, uint16_t n) {
	soFuncDsc* r=NULL;
	if( n >= h->nfunc ){
		return r;
	}
	
	return (( soFuncDsc*)(((uint8_t*)h) + sizeof(soHeader) + onloadFuncSize)) + n;
}

soFuncDsc* getSoFuncName(soHeader* h, const char* fname) {
	uint16_t n=h->nfunc;	// Количество функций
	soFuncDsc* sofunc=getSoFuncDsc(h, 0); // Адрес первой функции
	
	while( n ){
		
		if( !strcmp(fname, sofunc->name) ){
			// Имя совпало с искомым
			break;
		}
		// Следующая функция или выход
		n--;
		sofunc++;
	}
	
	return n?sofunc:NULL;
}


static void soPageJumper() __naked {
	__asm;
	.globl soPagedJumper
	soPagedJumper:
	jp	( hl )
	__endasm;
}


