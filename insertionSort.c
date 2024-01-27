void insertionSort(int v[], int n){
    int i, j, temp;
    for(int i = 0; i < n; i++){
        temp = v[i];
        //coloca o intem no lugar apropriado
        for(j = i-1; j>=0 && v[j]>temp; j--)
            v[j+1] = v[j];
        v[j+1]=temp;
    }
}
int main(){
    int i;
    //int v[8]={25,48,53,37,13,86,33,96};
    int v[10000]= rand();
    insertionSort(v,8);
    printf("vetor ordenado: \n");
    for(i=0;i<8;i++){
        printf("%d \n", v[i]);
    }
    return 0;
}
