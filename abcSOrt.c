void abcSort(int A[], i, j){
    int temp;
    if(A[i]>A[j]){
        temp = A[j];
        A[j]=A[i];
        A[i]=temp;
    }
    if(i+1 >= j) return;
    k = (j - i + 1) / 3;
    abcSort(A, i, j-k);
    abcSort(A, i+k, j);
    abcSort(A, i, j -k);
}
