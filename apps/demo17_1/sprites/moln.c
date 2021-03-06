/**
	@file moln.c

	Spite name: moln*

	W(chars): 3     H(CHARS):2
	PHASES: 4
	Phase's size:  bytes
	Sprite size:   bytes
	Color: 06

*/
#include "moln.h"


// Phase 0
const Sprite0 moln_0 = {
	.sz =  54  + sizeof(Sprite0),
	.w = 3,
	.h = 2,
	.datap ={
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x40,0xc0,0x00,0xa1,0xe3,0x00,
		0x13,0x77,0x00,0x0e,0x3e,0x00,0x04,0x1c,
		0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		06,06,06,06,06,06,}
};

// Phase 1
const Sprite0 moln_1 = {
	.sz =  54  + sizeof(Sprite0),
	.w = 3,
	.h = 2,
	.datap ={
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x80,0x00,0x41,0xc0,0x20,0xe3,0xc0,
		0x11,0x37,0x00,0x0a,0x1e,0x00,0x04,0x0c,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		06,06,06,06,06,06,}
};

// Phase 2
const Sprite0 moln_2 = {
	.sz =  54  + sizeof(Sprite0),
	.w = 3,
	.h = 2,
	.datap ={
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x80,0x00,0x41,0xc0,0x00,0xe3,0xe0,
		0x01,0x37,0x70,0x0a,0x1e,0x30,0x04,0x0c,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		06,06,06,06,06,06,}
};

// Phase 3
const Sprite0 moln_3 = {
	.sz =  54  + sizeof(Sprite0),
	.w = 3,
	.h = 2,
	.datap ={
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x40,0xc0,0x00,0xa1,0xe0,
		0x01,0x13,0x70,0x02,0x0e,0x3c,0x00,0x04,
		0x1c,0x00,0x00,0x08,0x00,0x00,0x00,0x00,
		0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
		06,06,06,06,06,06,}
};

// Sprite phases
const Sprite0* const moln[4]={&moln_0,&moln_1,&moln_2,&moln_3,};
