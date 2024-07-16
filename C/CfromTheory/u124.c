/* Modify C.12.3 so that the program reads a string of less than 100 characters
and uses binary_search() to display its position in the array, if found. Use the follow-
ing sorted array and the new prototype to modify the function. */

int binary_search(char *arr[], int size, char *str);

int main(void)
{
    char str[100], *arr[] = {"alpha", "beta", "camma", "delta", "epsilon", "ita", "omega"};
    int pos;
    ...
}