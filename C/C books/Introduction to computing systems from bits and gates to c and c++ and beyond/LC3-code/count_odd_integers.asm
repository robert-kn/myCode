; Memory locations x5000 to x5FFF contain 2’s complement integers. What does the following program do?
; The program counts the number of odd integers in the array            
            
            
            .ORIG x3000 
            LD R1, ARRAY              ; zero out R2
            LD R2, LENGTH
            AND R3, R3, #0
AGAIN       LDR R0, R1, #0
            AND R0, R0, #1
            BRz SKIP
            ADD R3, R3, #1
SKIP        ADD R1, R1, #1
            ADD R2, R2, #-1
            BRp AGAIN
            HALT
ARRAY       .FILL x5000
LENGTH      .FILL x1000
            .END