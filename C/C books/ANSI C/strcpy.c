/* copy t to s; array subscript version */

void strcpy(char *s, char *t)
{
    int i = 0;

    while((s[i] = t[i]) != '\0')
        i++;
}

/* copy t to s; pointer version */
void strcpy_pointer(char * s, char * t)
{

    while((*s = *t) != '\0'){
        s++;
        t++;
    }
        
}

/* In practice, strcpy would not be written as we showed it above. Experienced C programmers
would prefer */

void strcpy_pointer2(char * s, char * t)
{

    while((*s++ = *t++) != '\0')
        ;
}

/* As the final abbreviation, observe that a comparison against '\0' is redundant, since the
question is merely whether the expression is zero. So the function would likely be written as */

void strcpy_pointer3(char * s, char * t)
{

    while(*s++ = *t++)
        ;
}