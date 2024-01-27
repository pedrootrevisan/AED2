shellSort(int v[], int n){
    int i, j, h=1;
    int temp;

    do{h=h*3+1;}while(h<n);
    do{
        h/= 3;
        for(i = h; i < n; i++){
            temp = v[i];
            j = i;
            while(v[j-h]>temp){
                v[j] = v[j-h];
                j-=h;
                if(j<h) break;
            }
            v[j] = temp;
        }
    }while(h!=1);
}
int main(){
    int i;
    int v[8]={25,48,53,37,13,86,33,96};
    shellSort(v,8);
    printf("vetor ordenado: \n");
    for(i=0;i<8;i++){
        printf("%d \n", v[i]);
    }
    return 0;
}
