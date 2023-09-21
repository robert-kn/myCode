/**
 * Show that when small = i, lines (6) through (8) of Fig. 2.2 (the swapping steps) do not have any effect on array A.
*/

void selection_sort(int arr[], int num){
    int i, j, small, temp;

    for(i = 0; i < num - 1; i++){
        small = i;

        for(j = i + 1; j < num; j++)
            if(arr[j] < arr[small])
                small = j;

        temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;     
        
    }
}

/**
 * when small = i, lines 15 through to 17 have no effect on the array because index small and i refer to the same 
 * element in the array therefore the expressions do not permute the state of the array.
*/