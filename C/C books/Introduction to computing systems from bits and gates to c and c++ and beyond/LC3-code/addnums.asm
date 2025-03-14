        .ORIG x3000         ; start the program at location x3000
        AND R1, R1, x0      ; clear R1, to be used for returning the sum
        AND R4, R4, x0      ; clear R4, to be used as a counter
        ADD R4, R4, #10     ; load R4 with #10, the number of items to add
        LEA R2, x0FC        ; load the starting address of the data
LOOP    LDR R3, R2, x0      ; load the next number to be added
        ADD R2, R2, #1      ; increment the memory address pointer
        ADD R1, R1, R3      ; add the current number to the running sum
        ADD R4, R4, #-1     ; decrement the counter
        BRp LOOP            ; if counter is not zero, repeat loop
        HALT                
        .END

; you still need to change your program to a real binary file (addnums.obj)
; this process is called assembling

.ORIG x3100 ; start the data at location x3100
.FILL #1    ; the value of the first data element
.FILL #2
.FILL #3
.FILL #4
.FILL #5
.FILL #6
.FILL #7
.FILL #8
.FILL #9
.FILL #10
.END