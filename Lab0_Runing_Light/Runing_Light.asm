
_main:
	MOV SP+0, #128
;Runing_Light.c,4 :: 		void main()
;Runing_Light.c,7 :: 		LEDS = 0x01;
	MOV P0+0, #1
;Runing_Light.c,9 :: 		directionFlag = 1;
	SETB C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
;Runing_Light.c,10 :: 		while(1)
L_main0:
;Runing_Light.c,12 :: 		if (directionFlag)
	MOV A, _directionFlag+0
	JNB 224, L_main2
	NOP
;Runing_Light.c,13 :: 		LEDS = LEDS << 1;
	MOV R0, #1
	MOV A, P0+0
	INC R0
	SJMP L__main6
L__main7:
	CLR C
	RLC A
L__main6:
	DJNZ R0, L__main7
	MOV P0+0, A
	SJMP L_main3
L_main2:
;Runing_Light.c,15 :: 		LEDS = LEDS >> 1;
	MOV R0, #1
	MOV A, P0+0
	INC R0
	SJMP L__main8
L__main9:
	CLR C
	RRC A
L__main8:
	DJNZ R0, L__main9
	MOV P0+0, A
L_main3:
;Runing_Light.c,16 :: 		if (LEDS == 0x80)
	MOV A, P0+0
	XRL A, #128
	JNZ L_main4
;Runing_Light.c,17 :: 		directionFlag = 0;
	CLR C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
L_main4:
;Runing_Light.c,18 :: 		if (LEDS == 0x01)
	MOV A, P0+0
	XRL A, #1
	JNZ L_main5
;Runing_Light.c,19 :: 		directionFlag = 1;
	SETB C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
L_main5:
;Runing_Light.c,20 :: 		Delay_ms(100);
	MOV R6, 163
	MOV R7, 30
	DJNZ R7, 
	DJNZ R6, 
	NOP
;Runing_Light.c,21 :: 		}
	SJMP L_main0
;Runing_Light.c,22 :: 		}
	SJMP #254
; end of _main
