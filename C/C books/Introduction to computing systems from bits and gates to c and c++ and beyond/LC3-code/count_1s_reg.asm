; this program counts the number of 1s in the value stored in R0 and
; stores the result into R1


            .ORIG x3000 
            AND R5, R5, #0              ; zero out R5
            ADD R5, R5, #1              ; the value in R5 will act as a mask 
            AND R1, R1, #0              ; zero out the result register 
            AND R2, R2, #0              ; R2 will act as a counter of how many bits are left to be processed 
            LD  R3, NegSixt             ; load -16 into the register
MskLoop     AND R4, R0, R5              ; "mask off" right most bit - will set condition codes 
            BRz NotOne                  ; if bit is zero then dont increment the result
            ADD R1, R1, #1              ; if the bit is one increment the result 
NotOne      ADD R5, R5, R5              ; shift the right most 1 bit to the left by one
            ADD R2, R2, #1              ; increment the counter - keeps track of where we are in the bit pattern
            ADD R6, R2, R3                
            BRn MskLoop                 ; if R6 contains neg number, we still have more work to do
            HALT                    
NegSixt     .FILL #-16
            .END