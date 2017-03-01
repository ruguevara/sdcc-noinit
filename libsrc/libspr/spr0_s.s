;-------------------------------------------------
; ����������� ����� 256x192, ����������,
; �������� �����������
;-------------------------------------------------
	.globl _spr0_scr_adr

        .module spr0_s
	.area	_CODE
;-------------------------------------------------
; ��������� ���������� ������ �� ������ �� �����������
; ����:
;	L=x, H=y
; �����:
;	HL = ����� �����������
;
.globl sprXYtoHL
sprXYtoHL:
	LD A,H
        AND #7
        RRCA
        RRCA
        RRCA
        OR L
        LD L,A
        LD A,H
        AND #24
        LD H,A
        ld A,(_spr0_scr_adr+1)
        OR H
        LD H,A
	RET
;-------------------------------------------------
; ��������� ���������� ������ �� ������ �� �����������
; ����:
;	L=x, H=y
; �����:
;	HL = ����� ������ ���������
;
.globl sprXYtoHLattr
sprXYtoHLattr:
	; HL = y
	ld	a,l
	ld	l,h
	ld	h,#0
	; HL = y*32
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	; HL = y*32 + x
	add	a,l
	ld	l,a
	; 
	ld	bc,#0x1800
	add	hl,bc
	ld	bc,(_spr0_scr_adr)
	add	hl,bc
	ret
;-------------------------------------------------
