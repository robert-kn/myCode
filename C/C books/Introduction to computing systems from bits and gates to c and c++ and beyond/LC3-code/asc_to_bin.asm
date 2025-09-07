; This subroutine takes an ascii string up to 3 decimal digits and converts it into a binary number. R0 is used to
; collect the result. R1 keeps track of how many digits are left to process. ASCIIBUFF contains the most significant
; digit in the ASCII string.

ASCIItoBinary   ST      R1, AtoB_Save1
                ST      R2, AtoB_Save2
                ST      R3, AtoB_Save3
                ST      R4, AtoB_Save4
                AND     R0, R0, #0      ; R0 will be used for our result
                ADD     R1, R1, #0      ; test number of digits
                BRz     AtoB_Done       ; there are no digits result is 0

                LD      R2, AtoB_ASCIIBUFF    ; R2 points to ASCIIBUFF
                ADD     R2, R2, R1
                ADD     R2, R2, #-1           ; R2 now points to "ones" digit

                LDR     R4, R2, #0            ; R4 <-- "ones" digit
                AND     R4, R4, 0x000F        ; strip off the ASCII template
                ADD     R0, R0, R4            ; add ones contribution

                ADD     R1, R1, #-1
                BRz     AtoB_Done             ; The original number had one digit
                ADD     R2, R2, #-1           ; R2 now points to "tens" digit

                LDR     R4, R2, #0            ; R4 <-- "tens" digit
                AND     R4, R4, x000F         ; strip off ASCII template
                LEA     R3, LookUp10          ; LookUp10 is BASE of tens values
                ADD     R3, R3, R4            ; R3 points to the right tens value 
                LDR     R4, R3, #0            
                ADD     R0, R0, R4            ; Add tens contribution total

                ADD     R1, R1, #-1
                BRz     AtoB_Done             ; The original number had two digits
                ADD     R2, R2, #-1           ; R2 now points to "hundreds" digit

                LDR     R4, R2, #0            ; R4 <-- "hundreds" digit
                AND     R4, R4, 0x000F         ; Strip off ASCII template
                LEA     R3, LookUp100         ; LookUp100 is hundreds BASE
                ADD     R3, R3, R4            ; R3 points to hundreds value
                LDR     R4, R3, #0
                ADD     R0, R0, R4            ; Add hundreds contribution to total

AtoB_Done       LD      R1, AtoB_Save1        
                LD      R2, AtoB_Save2
                LD      R3, AtoB_Save3
                LD      R4, AtoB_Save4
                RET

AtoB_ASCIIBUFF  .FILL   ASCIIBUFF
AtoB_Save1      .BLKW   #1
AtoB_Save2      .BLKW   #1
AtoB_Save3      .BLKW   #1
AtoB_Save4      .BLKW   #1
LookUp10        .FILL   #0
                .FILL   #10
                .FILL   #20
                .FILL   #30
                .FILL   #40
                .FILL   #50
                .FILL   #60
                .FILL   #70
                .FILL   #80
                .FILL   #90

LookUp100       .FILL   #0
                .FILL   #100
                .FILL   #200
                .FILL   #300
                .FILL   #400
                .FILL   #500
                .FILL   #600
                .FILL   #700
                .FILL   #800
                .FILL   #900
                
