/**
 * Further modify Fig. 2.3 so that it sorts elements of an arbitrary type T. You may assume, however, that 
 * there is a function key that takes an element of type T as argument and returns the key for that element, 
 * of some arbitrary type K. Also assume that there is a function lt that takes two elements of type K as arguments 
 * and returns TRUE if the first is “less than” the second, and FALSE otherwise.
*/
#define  MAX 12

typedef T TARRAY[MAX];
TARRAY arr;

void selection_sort(TARRAY arr, int num){
    int i, j, small;
    T temp;

    for(i = 0; i < num - 1; i++){
        small = i;
            /* the function key(x) returns the key of the type k  for the element x */
        for(j = i + 1; j < num; j++)
            if(lt(key(arr[j]), key(arr[small])))
                small = j;

        temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;     
        
    }   
}