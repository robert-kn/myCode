; The following LC-3 program determines whether a character string is a palindrome or not. A palindrome is a 
; string that reads the same backwards as forwards. For example, the string “racecar” is a palindrome. Suppose 
; a string starts at memory location x4000 and is in the .STRINGZ format. If the string is a palindrome, the program 
; terminates with the value 1 in R5. If not, the program terminates with the value 0 in R5. Insert instructions at (a)–(e) 
; that will complete the program.            
            
            
            .ORIG x3000 
            LD R0, PTR                 ; 
            ADD R1, R0, #0             ;        
AGAIN       LDR R2, R1, #0             ; 
            BRZ CONT
            ADD R1, R1, #1
            BRznp AGAIN
CONT        ADD R1, R1, #-1
LOOP        LDR R3, R0, #0
            LDR R4, R1, #0
            NOT R4, R4
            ADD R4, R4, #1
            ADD R3, R3, R4
            BRnp NO
            ADD R0, R0, #1
            ADD R1, R1, #-1
            NOT R2, R0
            ADD R2, R2, #1
            ADD R2, R1, R2
            BRnz YES
            BR LOOP                                       
YES         AND R5, R5, #0             ; load number in current memory address
            ADD R5, R5, #1             ; "mask off" left most bit - will set condition codes 
            BRznp DONE
NO          AND R5, R5, #0
DONE        HALT
PTR         .FILL x4000
            .END