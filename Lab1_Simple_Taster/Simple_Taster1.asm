
_InitMCU:
;Simple_Taster1.c,5 :: 		void InitMCU()
;Simple_Taster1.c,8 :: 		P0 = 0x00;
	MOV P0+0, #0
;Simple_Taster1.c,10 :: 		TASTER = 1;
	SETB C
	MOV A, P3_2_bit+0
	MOV #224, C
	MOV P3_2_bit+0, A
;Simple_Taster1.c,12 :: 		buttonPress = 0;
	CLR C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster1.c,14 :: 		LEDS = 0x01;
	MOV P0+0, #1
;Simple_Taster1.c,16 :: 		directionFlag = 1;
	SETB C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
;Simple_Taster1.c,17 :: 		}
	RET
; end of _InitMCU

_main:
	MOV SP+0, #128
;Simple_Taster1.c,19 :: 		void main()
;Simple_Taster1.c,22 :: 		InitMCU();
	LCALL _InitMCU+0
;Simple_Taster1.c,23 :: 		while(1)
L_main0:
;Simple_Taster1.c,25 :: 		if(TASTER == 0)
	MOV A, P3_2_bit+0
	JB 224, L_main2
	NOP
;Simple_Taster1.c,27 :: 		if (buttonPress == 0)
	MOV A, _buttonPress+0
	JB 224, L_main3
	NOP
;Simple_Taster1.c,29 :: 		if (directionFlag)
	MOV A, _directionFlag+0
	JNB 224, L_main4
	NOP
;Simple_Taster1.c,30 :: 		LEDS = LEDS << 1;
	MOV R0, #1
	MOV A, P0+0
	INC R0
	SJMP L__main9
L__main10:
	CLR C
	RLC A
L__main9:
	DJNZ R0, L__main10
	MOV P0+0, A
	SJMP L_main5
L_main4:
;Simple_Taster1.c,32 :: 		LEDS = LEDS >> 1;
	MOV R0, #1
	MOV A, P0+0
	INC R0
	SJMP L__main11
L__main12:
	CLR C
	RRC A
L__main11:
	DJNZ R0, L__main12
	MOV P0+0, A
L_main5:
;Simple_Taster1.c,33 :: 		if (LEDS == 0x80)
	MOV A, P0+0
	XRL A, #128
	JNZ L_main6
;Simple_Taster1.c,34 :: 		directionFlag = 0;
	CLR C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
L_main6:
;Simple_Taster1.c,35 :: 		if (LEDS == 0x01)
	MOV A, P0+0
	XRL A, #1
	JNZ L_main7
;Simple_Taster1.c,36 :: 		directionFlag = 1;
	SETB C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
L_main7:
;Simple_Taster1.c,37 :: 		buttonPress = 1;
	SETB C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster1.c,38 :: 		}
L_main3:
;Simple_Taster1.c,39 :: 		}
	SJMP L_main8
L_main2:
;Simple_Taster1.c,42 :: 		buttonPress = 0;
	CLR C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster1.c,43 :: 		}
L_main8:
;Simple_Taster1.c,44 :: 		}
	SJMP L_main0
;Simple_Taster1.c,45 :: 		}
	SJMP #254
; end of _main
