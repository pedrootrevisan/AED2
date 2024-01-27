void selectionSort(int v[], int n){
    int temp, menor, i, j;
    for(i=0;i<n-1;i++){
        menor = i;
        for(j=i+1;j<n;j++){
            if(v[j]<v[menor]) menor = j;
        }
        temp = v[i];
        v[i] = v[menor];
        v[menor] = temp;
    }
}
int main(){
    int i;
    int v[8]={25,48,53,37,13,86,33,96};
    selectionSort(v,8);
    printf("vetor ordenado: \n");
    for(i=0;i<8;i++){
        printf("%d \n", v[i]);
    }
    return 0;
}

