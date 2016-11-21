
_InitMCU:
;Simple_Interrupts.c,4 :: 		void InitMCU()
;Simple_Interrupts.c,6 :: 		P0 = 0xFF;
	MOV P0+0, #255
;Simple_Interrupts.c,8 :: 		count = 0;
	MOV _count+0, #0
;Simple_Interrupts.c,10 :: 		IT0_bit = 1;
	SETB IT0_bit+0
;Simple_Interrupts.c,11 :: 		IT1_bit = 1;
	SETB IT1_bit+0
;Simple_Interrupts.c,13 :: 		IE = 0x85;
	MOV IE+0, #133
;Simple_Interrupts.c,14 :: 		}
	RET
; end of _InitMCU

_main:
	MOV SP+0, #128
;Simple_Interrupts.c,16 :: 		void main()
;Simple_Interrupts.c,19 :: 		InitMCU();
	LCALL _InitMCU+0
;Simple_Interrupts.c,21 :: 		while(1)
L_main0:
;Simple_Interrupts.c,23 :: 		LEDS = ~LEDS;
	MOV C, P0_0_bit+0
	CPL C
	MOV P0_0_bit+0, C
;Simple_Interrupts.c,24 :: 		switch(count)
	SJMP L_main2
;Simple_Interrupts.c,26 :: 		case 0 : Delay_MS(250);
L_main4:
	MOV R5, 2
	MOV R6, 150
	MOV R7, 77
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Interrupts.c,27 :: 		break;
	SJMP L_main3
;Simple_Interrupts.c,28 :: 		case 1 : Delay_MS(500);
L_main5:
	MOV R5, 4
	MOV R6, 43
	MOV R7, 157
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Interrupts.c,29 :: 		break;
	SJMP L_main3
;Simple_Interrupts.c,30 :: 		case 2 : Delay_MS(1000);
L_main6:
	MOV R5, 7
	MOV R6, 86
	MOV R7, 60
	DJNZ R7, 
	DJNZ R6, 
	DJNZ R5, 
;Simple_Interrupts.c,31 :: 		break;
	SJMP L_main3
;Simple_Interrupts.c,32 :: 		}
L_main2:
	MOV A, _count+0
	JZ L_main4
	MOV A, _count+0
	XRL A, #1
	JZ L_main5
	MOV A, _count+0
	XRL A, #2
	JZ L_main6
L_main3:
;Simple_Interrupts.c,33 :: 		}
	SJMP L_main0
;Simple_Interrupts.c,34 :: 		}
	SJMP #254
; end of _main

_btn_up:
	PUSH PSW+0
	PUSH 224
	PUSH B+0
	PUSH 130
	PUSH 131
;Simple_Interrupts.c,36 :: 		void btn_up() iv IVT_ADDR_EX0
;Simple_Interrupts.c,38 :: 		count++;
	MOV A, _count+0
	ADD A, #1
	MOV R0, A
	MOV _count+0, 0
;Simple_Interrupts.c,39 :: 		if(count > 2)
	SETB C
	MOV A, _count+0
	SUBB A, #2
	JC L_btn_up7
;Simple_Interrupts.c,41 :: 		count = 2;
	MOV _count+0, #2
;Simple_Interrupts.c,42 :: 		}
L_btn_up7:
;Simple_Interrupts.c,43 :: 		}
	POP 131
	POP 130
	POP B+0
	POP 224
	POP PSW+0
	RETI
; end of _btn_up

_btn_down:
	PUSH PSW+0
	PUSH 224
	PUSH B+0
	PUSH 130
	PUSH 131
;Simple_Interrupts.c,45 :: 		void btn_down() iv IVT_ADDR_EX1 {
;Simple_Interrupts.c,46 :: 		count--;
	CLR C
	MOV A, _count+0
	SUBB A, #1
	MOV R0, A
	MOV _count+0, 0
;Simple_Interrupts.c,47 :: 		if(count <= 0)
	SETB C
	MOV A, _count+0
	SUBB A, #0
	JNC L_btn_down8
;Simple_Interrupts.c,49 :: 		count = 0;
	MOV _count+0, #0
;Simple_Interrupts.c,50 :: 		}
L_btn_down8:
;Simple_Interrupts.c,51 :: 		}
	POP 131
	POP 130
	POP B+0
	POP 224
	POP PSW+0
	RETI
; end of _btn_down
