/* Write a program that reads the name of a text fle and the number of a line and replaces that line with a new input text. If the line has more characters than the new text, the extra characters until the 
end of line should be replaced with the space character. If it has fewer, the replacement should be done until the end of line. It is mandatory to use getc() and putc() to read and write to the fle and 
getchar() to read the new text. For example, if the fle content is: 

First
Second
Third

and the user enters as line number 2 and the text New, the fle becomes:

First
New
Third

if the users enters 1 and Introduction, it becomes:

Intro 
Second 
Third
*/