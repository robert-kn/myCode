Write a loop equivalent to the for loop above without using && or ||.

for(i=0; i < lim - 1 && (c=getchar()) != '\n' && c != EOF; i++)
    s[i] = c;

int i, c;
i = 0;

while(i < lim - 1){
    c= getchar();
    
    if(c != '\n')
        if(c != EOF)
            s[i] = 0;
    i++;
}


