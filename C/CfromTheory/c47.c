/**
 * The ^ operator is often used in data encryption. For example, write a program that reads an integer that 
 * corresponds to the cipher key and another integer that will be encrypted with that key. The encryption 
 * is performed by applying the ^ operator on them. Then, the program should use once more the ^ operator to 
 * decrypt the encrypted result.
*/

#include <stdio.h>

int main(void){
    unsigned int key, num, encrypted;
    printf("Enter cipher key: ");
    scanf("%d", &key);
    printf("Enter number to encrypt: ");
    scanf("%d", &num);
    encrypted = key ^ num;
    printf("Encrypted number: %d\n", encrypted);
    printf("Decrypted number: %d\n", encrypted ^ key);
    return 0;

}