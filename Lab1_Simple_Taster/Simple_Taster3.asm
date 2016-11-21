
_InitMCU:
;Simple_Taster3.c,7 :: 		void InitMCU()
;Simple_Taster3.c,10 :: 		P0 = 0x01;
	MOV P0+0, #1
;Simple_Taster3.c,12 :: 		TASTER = 1;
	SETB C
	MOV A, P3_2_bit+0
	MOV #224, C
	MOV P3_2_bit+0, A
;Simple_Taster3.c,14 :: 		buttonPress = 0;
	CLR C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster3.c,15 :: 		delay_option = 0;
	MOV _delay_option+0, #0
	MOV _delay_option+1, #0
;Simple_Taster3.c,16 :: 		directionFlag = 1;
	SETB C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
;Simple_Taster3.c,17 :: 		}
	RET
; end of _InitMCU

_main:
	MOV SP+0, #128
;Simple_Taster3.c,19 :: 		void main()
;Simple_Taster3.c,22 :: 		InitMCU();
	LCALL _InitMCU+0
;Simple_Taster3.c,23 :: 		while(1)
L_main0:
;Simple_Taster3.c,25 :: 		if(TASTER == 0)
	MOV A, P3_2_bit+0
	JB 224, L_main2
	NOP
;Simple_Taster3.c,27 :: 		if (buttonPress == 0)
	MOV A, _buttonPress+0
	JB 224, L_main3
	NOP
;Simple_Taster3.c,29 :: 		delay_option = (delay_option++)%2;
	MOV R4, #2
	MOV R5, #0
	MOV R0, _delay_option+0
	MOV R1, _delay_option+1
	LCALL _Div_16x16_S+0
	MOV R0, 4
	MOV R1, 5
	MOV _delay_option+0, 0
	MOV _delay_option+1, 1
	MOV A, #1
	ADD A, R0
	MOV _delay_option+0, A
	MOV A, #0
	ADDC A, R1
	MOV _delay_option+1, A
;Simple_Taster3.c,30 :: 		buttonPress = 1;
	SETB C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster3.c,31 :: 		}
L_main3:
;Simple_Taster3.c,32 :: 		}
	SJMP L_main4
L_main2:
;Simple_Taster3.c,35 :: 		buttonPress = 0;
	CLR C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster3.c,36 :: 		}
L_main4:
;Simple_Taster3.c,38 :: 		if (directionFlag)
	MOV A, _directionFlag+0
	JNB 224, L_main5
	NOP
;Simple_Taster3.c,40 :: 		LEDS = LEDS << 1;
	MOV R0, #1
	MOV A, P0+0
	INC R0
	SJMP L__main14
L__main15:
	CLR C
	RLC A
L__main14:
	DJNZ R0, L__main15
	MOV P0+0, A
;Simple_Taster3.c,41 :: 		}
	SJMP L_main6
L_main5:
;Simple_Taster3.c,44 :: 		LEDS = LEDS >> 1;
	MOV R0, #1
	MOV A, P0+0
	INC R0
	SJMP L__main16
L__main17:
	CLR C
	RRC A
L__main16:
	DJNZ R0, L__main17
	MOV P0+0, A
;Simple_Taster3.c,45 :: 		}
L_main6:
;Simple_Taster3.c,47 :: 		switch(delay_option)
	SJMP L_main7
;Simple_Taster3.c,49 :: 		case 0 : Delay_MS(250);
L_main9:
	MOV R5, 2
	MOV R6, 150
	MOV R7, 77
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Taster3.c,50 :: 		break;
	SJMP L_main8
;Simple_Taster3.c,51 :: 		case 1 : Delay_MS(500);
L_main10:
	MOV R5, 4
	MOV R6, 43
	MOV R7, 157
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Taster3.c,52 :: 		break;
	SJMP L_main8
;Simple_Taster3.c,53 :: 		case 2 : Delay_MS(1000);
L_main11:
	MOV R5, 7
	MOV R6, 86
	MOV R7, 60
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Taster3.c,54 :: 		break;
	SJMP L_main8
;Simple_Taster3.c,55 :: 		}
L_main7:
	MOV A, _delay_option+0
	ORL A, _delay_option+1
	JZ L_main9
	MOV A, #1
	XRL A, _delay_option+0
	JNZ L__main18
	MOV A, #0
	XRL A, _delay_option+1
L__main18:
	JZ L_main10
	MOV A, #2
	XRL A, _delay_option+0
	JNZ L__main19
	MOV A, #0
	XRL A, _delay_option+1
L__main19:
	JZ L_main11
L_main8:
;Simple_Taster3.c,57 :: 		if (LEDS == 0x80)
	MOV A, P0+0
	XRL A, #128
	JNZ L_main12
;Simple_Taster3.c,59 :: 		directionFlag = 0;
	CLR C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
;Simple_Taster3.c,60 :: 		}
L_main12:
;Simple_Taster3.c,61 :: 		if (LEDS == 0x01)
	MOV A, P0+0
	XRL A, #1
	JNZ L_main13
;Simple_Taster3.c,63 :: 		directionFlag = 1;
	SETB C
	MOV A, _directionFlag+0
	MOV #224, C
	MOV _directionFlag+0, A
;Simple_Taster3.c,64 :: 		}
L_main13:
;Simple_Taster3.c,66 :: 		}
	LJMP L_main0
;Simple_Taster3.c,67 :: 		}
	SJMP #254
; end of _main
