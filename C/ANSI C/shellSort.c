/* shellsort: sort v[0]... v[n-1] into increasing order */

void shellSort(int v[], int n){
    int gap, i, j, temp;

    for(gap = n/2; gap > 0; gap /= 2) /* controls the gap between compared elements */
        for(i = gap; i < n; i++) /* steps along the elements */
            for(j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}