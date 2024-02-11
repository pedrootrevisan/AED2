#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void bucketSort(int arr[], int n, int max) {
    struct Node* buckets[max];

    // Inicializando cada bucket como uma lista ligada vazia
    for (int i = 0; i < max; ++i)
        buckets[i] = NULL;

    // Distribuindo os elementos do array para os buckets correspondentes
    for (int i = 0; i < n; ++i) {
        int index = (arr[i] * max) / (max + 1);
        insertNode(&buckets[index], arr[i]);
    }

    // Ordenando os elementos em cada bucket individualmente usando insertion sort
    for (int i = 0; i < max; ++i) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            struct Node* temp = current->next;
            struct Node* prev = NULL;
            struct Node* pos = buckets[i];

            while (pos != NULL && pos->data < current->data) {
                prev = pos;
                pos = pos->next;
            }

            if (prev == NULL) {
                current->next = buckets[i];
                buckets[i] = current;
            } else {
                prev->next = current;
                current->next = pos;
            }

            current = temp;
        }
    }

    int index = 0;
    for (int i = 0; i < max; ++i) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->data;
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Array original: \n");
    printArray(arr, n);

    bucketSort(arr, n, max);

    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
