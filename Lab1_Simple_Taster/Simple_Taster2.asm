
_InitMCU:
;Simple_Taster2.c,6 :: 		void InitMCU()
;Simple_Taster2.c,9 :: 		P0 = 0x00;
	MOV P0+0, #0
;Simple_Taster2.c,11 :: 		TASTER = 1;
	SETB C
	MOV A, P3_2_bit+0
	MOV #224, C
	MOV P3_2_bit+0, A
;Simple_Taster2.c,13 :: 		buttonPress = 0;
	CLR C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster2.c,14 :: 		delay_option = 0;
	MOV _delay_option+0, #0
	MOV _delay_option+1, #0
;Simple_Taster2.c,15 :: 		}
	RET
; end of _InitMCU

_main:
	MOV SP+0, #128
;Simple_Taster2.c,17 :: 		void main()
;Simple_Taster2.c,20 :: 		InitMCU();
	LCALL _InitMCU+0
;Simple_Taster2.c,21 :: 		while(1)
L_main0:
;Simple_Taster2.c,23 :: 		if(TASTER == 0)
	MOV A, P3_2_bit+0
	JB 224, L_main2
	NOP
;Simple_Taster2.c,25 :: 		if (buttonPress == 0)
	MOV A, _buttonPress+0
	JB 224, L_main3
	NOP
;Simple_Taster2.c,27 :: 		delay_option = (delay_option++)%2;
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
;Simple_Taster2.c,28 :: 		buttonPress = 1;
	SETB C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster2.c,29 :: 		}
L_main3:
;Simple_Taster2.c,30 :: 		}
	SJMP L_main4
L_main2:
;Simple_Taster2.c,33 :: 		buttonPress = 0;
	CLR C
	MOV A, _buttonPress+0
	MOV #224, C
	MOV _buttonPress+0, A
;Simple_Taster2.c,34 :: 		}
L_main4:
;Simple_Taster2.c,35 :: 		LED = ~LED;
	MOV C, P0_0_bit+0
	CPL C
	MOV P0_0_bit+0, C
;Simple_Taster2.c,36 :: 		switch(delay_option)
	SJMP L_main5
;Simple_Taster2.c,38 :: 		case 0 : Delay_MS(250);
L_main7:
	MOV R5, 2
	MOV R6, 150
	MOV R7, 77
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Taster2.c,39 :: 		break;
	SJMP L_main6
;Simple_Taster2.c,40 :: 		case 1 : Delay_MS(500);
L_main8:
	MOV R5, 4
	MOV R6, 43
	MOV R7, 157
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Taster2.c,41 :: 		break;
	SJMP L_main6
;Simple_Taster2.c,42 :: 		case 2 : Delay_MS(1000);
L_main9:
	MOV R5, 7
	MOV R6, 86
	MOV R7, 60
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Taster2.c,43 :: 		break;
	SJMP L_main6
;Simple_Taster2.c,44 :: 		}
L_main5:
	MOV A, _delay_option+0
	ORL A, _delay_option+1
	JZ L_main7
	MOV A, #1
	XRL A, _delay_option+0
	JNZ L__main10
	MOV A, #0
	XRL A, _delay_option+1
L__main10:
	JZ L_main8
	MOV A, #2
	XRL A, _delay_option+0
	JNZ L__main11
	MOV A, #0
	XRL A, _delay_option+1
L__main11:
	JZ L_main9
L_main6:
;Simple_Taster2.c,45 :: 		}
	LJMP L_main0
;Simple_Taster2.c,46 :: 		}
	SJMP #254
; end of _main
