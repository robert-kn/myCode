/* Figure 13.5 depicts the status register of a printer (16 bits). Use bit felds and defne the structure print_reg with the fve felds 
of Figure 13.5. Write a program that uses a structure of that type to simulate a printing job of 20 pages, as follows: 

1. The low ink feld is set to 3, when the 9th page is print and up to the end of the printing job.
2. The error code feld is set to 10, only when the 13th page is print.
3. The paper jam feld is set to 1, only when the 15th page is print.
4. The clean feld is set to 1, only when the last page is print.

Use a loop of 20 iterations to simulate the printing job. Each iteration corresponds to the print of one page. For each 
printing page, the program should display the value of the status register.

see figure in exercise on book pg 466*/