void mergesort(int vet[], int n){
    int aux [n];
    m_sort(vet, aux, 0, n-1);
}
void m_sort(int vet[], int aux[], int esq, int dir){
    int meio;
    if(dir > esq){
        meio = (dir + esq)/2;
        m_sort(vet,aux, esq, meio);
        m_sort(vet,aux, meio+1, dir);
        merge(vet, aux, esq, meio+1, dir);
    }
}

void merge(int vet[], int aux[],int esq, int meio ,int dir){
    int i, esq_fim, n;

    esq_fim = meio-1;
    n = dir - esq +1;

    while(esq<= esq_fim && meio<=dir){
        if(vet[esq]<= vet[meio])
            aux[i++] = vet[esq++];
        else
            aux[i++] = vet[meio++];
    }
    while(esq<=esq_fim) aux[i++] = vet[esq++];
    while(esq<=dir) aux[i++] = vet[meio++];

    for(i=0; i < n; i++){
        vet[dir] = aux[dir];
        dir--;
    }
}
