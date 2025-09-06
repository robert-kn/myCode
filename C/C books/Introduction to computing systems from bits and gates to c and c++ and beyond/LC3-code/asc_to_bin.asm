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

                

;The inner loop
AGAIN           ADD     R3, R3, R2
                ADD     R1, R1, #-1     ; R1 keeps track of the iterations
                BRp     AGAIN
;
                HALT
;
NUMBER          .BLKW   1
SIX             .FILL   x0006
;
                .END