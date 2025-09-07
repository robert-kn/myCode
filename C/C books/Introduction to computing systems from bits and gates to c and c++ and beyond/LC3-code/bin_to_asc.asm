; this subroutine converts a 2's complement integer within the range -999 to +999 (located in R0) into an ascii 
; character string consisting of a sign digit, followed by three decimal digits, and stores the character string
; into the four memory locations starting at ASCIIBUFF see figure 10.4

BinarytoASCII       ST      R0, BtoA_Save0
                    ST      R1, BtoA_Save1
                    ST      R2, BtoA_Save2
                    ST      R3, BtoA_Save3
                    LD      R1, BtoA_ASCIIBUFF      ; R1 keeps track of output string
                    ADD     R0, R0, #0              ; R0 contains the binary value
                    BRn     NegSign
                    LD      R2, ASCIIplus           ; First store the ASCII plus sign
                    STR     R2, R1, #0
                    BRnzp   Begin100
NegSign             LD      R2, ASCIIminus          ; first store ASCII minus sign
                    STR     R2, R1, #0
                    NOT     R0, R0                  ; convert the number to absolute
                    ADD     R0, R0, #1              ; value; it is easier to work with 

Begin100            LD      R2, ASCIIoffset         ; prepare for "hundreds" digit

                    LD      R3, Neg100              ; determine the hundreds digit
Loop100             ADD     R0, R0, R3
                    BRn     End100
                    ADD     R2, R2, #1
                    BRnzp   Loop100

End100              STR     R2, R1, #1              ; store ascii code for hundreds digit
                    LD      R3, Pos100
                    ADD     R0, R0, R3              ; correct R0 for one too many subtracts

                    LD      R2, ASCIIoffset         ; prepare for "tens" digit

Loop10              ADD     R0, R0, #-10            ; Determine the tens digit
                    BRn     End10 
                    ADD     R2, R2, #1
                    BRnzp   Loop10

End10               STR     R2, R1, #2              ; store ascii code for tens digit
                    ADD     R0, R0, #10             ; correct R0 for one too many subtracts

Begin1              LD      R2, ASCIIoffset         ; prepare for "ones" digit
                    ADD     R2, R2, R0
                    STR     R2, R1, #3
                    LD      R0, BtoA_Save0    
                    LD      R1, BtoA_Save1
                    LD      R2, BtoA_Save2
                    LD      R3, BtoA_Save3
                    RET

ASCIIplus           .FILL   x002B
ASCIIminus          .FILL   x002D
ASCIIoffset         .FILL   x0030
Neg100              .FILL   #-100
Pos100              .FILL   #100
BtoA_Save0          .BLKW   #1
BtoA_Save1          .BLKW   #1
BtoA_Save2          .BLKW   #1
BtoA_Save3          .BLKW   #1 
BtoA_ASCIIBUFF      .FILL   ASCIIBUFF   


