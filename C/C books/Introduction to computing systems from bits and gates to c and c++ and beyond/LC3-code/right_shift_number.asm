; The program logical right-shifts the number in R0 by the number in R1 and puts it in RESULT.
; R0 holds the input number to right-shift.   Range = [x0000 to xFFFF] 
; R1 holds the amount to right-shift. Range = [1 to 15]
; R6 holds the right-shifted output. Range = [x0000 to x7FFF]


            .ORIG x3000 
            AND R2, R2, #0              ; zero out R2
            AND R6, R6, #0
            ADD R2, R2, #1
TOP         ADD R3, R2, #0
            ADD R4, R1, #0
SEARCH      ADD R3, R3, R3
            ADD R4, R4, #-1
            BRp SEARCH
            AND R5, R3, R0
            BRz NEXT
            ADD R6, R6, R2
NEXT        ADD R2, R2, R2
            BRzp TOP
END         ST R6, RESULT
            HALT
RESULT      .BLKW 1
            .END            