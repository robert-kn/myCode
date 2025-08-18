; convert constants in ascii into their appropriate binary values
; For instance, x2A translates into 00101010 and #12 translates into 00001100. 
; reads a decimal or hexadecimal constant from the keyboard (i.e., it is preceded by a # character signifying it 
; is a decimal, or x signifying it is hex) and prints out the binary representation. Assume the constants can be 
; expressed with no more than two decimal or hex digits.

            .ORIG x3000 
            IN                          ; input the first char - either x or #
            AND R3, R3, #0              ; zero out R3
            ADD R3, R3, #9              ; R3 = 9 if we are working with a decimal or 16 if hex
            LD  R4, NASCIID
            LD  R5, NHEXDIF

            LD  R1, NCONSD
            ADD R1, R1, R0              ;  
            BRz GETNUMS
            LD  R1, NCONSX
            ADD R1, R1, R0
            BRnp FAIL
            ADD R3, R3, #6              ; R3 = 15
            
GETNUMS     IN
            ST  R0, CHAR1
            IN
            ST  R0, CHAR2
            LEA R6, CHAR1 
            AND R2, R2, #0  
            ADD R2, R2, #2              ; Loop twice Using R2, R3, R4, R5, R6 here


            AND R0, R0, #0              ; result 
LOOP        ADD R1, R3, #0
            ADD R7, R0, #0

LPCUR       ADD R0, R0, R7
            ADD R1, R1, #-1
            BRp LPCUR

            LDR R1, R6, #0
            ADD R1, R1, R4

            ADD R0, R0, R1

            ADD R1, R1, R5
            BRn DONECUR
            ADD R0, R0, #-7             ; for hex numbers

DONECUR     
            ADD R6, R6, #1
            ADD R2, R2, #-1
            BRp LOOP

            ; R0 has number at this point
            
            AND R2, R2, #0
            ADD R2, R2, #8

            LEA R3, RESEND
            LD  R4, ASCNUM
            AND R5, R5, #0
            ADD R5, R5, #1

STLP        AND R1, R0, R5
            BRp ONENUM
            ADD R1, R4, #0
            BRnzp STORCH


ONENUM      ADD R1, R4, #1
STORCH      ADD R5, R5, R5
            STR R1, R3, #-1
            ADD R3, R3, #-1
            ADD R2, R2, #-1
            BRp STLP
            LEA R0, RES

            PUTS

FAIL        HALT
CHAR1       .FILL x0
CHAR1       .FILL x0
ASCNUM      .FILL x30
NHEXDIF     .FILL xFFEF                 ; -x11
NASCIID     .FILL xFFD0                 ; -x30
NCONSX      .FILL xFF88                 ; -x78
NCONSD      .FILL xFFDD                 ; -x23

RES         .BLKW 8
RESEND      .FILL x0
            .END