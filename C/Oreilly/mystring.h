#if !defined(MYSTRING_H)
#define MYSTRING_H
/**
 * count the number of characters in a string
 * example: my_strlen("foo") should be 3
*/

int my_strlen(const char * str);

/**
 * count the number of occurences of a particular 
 * character in a string
 * example: my_countchar("foo", "o") should be 2
*/

int my_countchar(const char * str, char c);

/**
 * convert a string to uppercase - only alphabetical characters
 * should be converted. All other character should remain 
 * unaffected.
 * example: char * str = "foobar"
 * my_strupper(str) is "FOOBAR"
*/

void my_strupper(char * str);

/**
 * return the pointer to the first occurence of the character.
 * if the character is not in the string, return NULL.
 * example: char * str = "foobar"
 * my_strchr(foobar, 'b') returns str[3]
*/

char * my_strchr(const char * str, char ch);

#endif