; This program counts the number of negative values in memory locations 0x4000 - 0x4009 and stores the result 
; in memory location 0x5000.            
            
            
            .ORIG x3000 
            AND R0, R0, #0              ; zero out R0
            ADD R2, R0, #10             
            LD R1, MASK                ; msb will be used to detect negative number in 2s complement format 
            LD R3, PTR1                ; load starting address of numbers in memory 
LOOP        LDR R4, R3, #0             ; load number in current memory address
            AND R4, R4, R1             ; "mask off" left most bit - will set condition codes 
            BRz Next                   ; if z condition code is set then number is positive which means we do nothing
            ADD R0, R0, #1             ; add one to the count of -ve numbers we have processed so far
Next        ADD R3, R3, #1             ; add 1 to get address of next number
            ADD R2, R2, #-1            ; decrement to keep track of how many numbers we have processed
            BRp LOOP                   ; if +ve condition code set then we still have work to do                
            STI R0, PTR2               ; update -ve number count seen so far
            HALT                    
MASK        .FILL x8000
PTR1        .FILL x4000
PTR2        .FILL x5000