#include <stdio.h>
#include <stdlib.h>

int *ReverseInGroup(int *arr, int size, int groupOf) {
    for (int i = 0; i <= size - 1; i += groupOf) {
    }
}

int main() {
    int Tc;
    scanf("%d", &Tc);
    while (Tc--) {
        int size, GroupSize;
        scanf("%d", &size);
        int arr[size];
        int i;
        for (i = 0; i < size; i++) {
            scanf("%d ", &arr[i]);
        }        

        scanf("%d", &GroupSize);
        
        int TheOdd1Out = size % GroupSize;
        i = 0;
        while (i < size - TheOdd1Out) {
            for (int j = GroupSize + i; j > i; j--) {
                printf("%d ", arr[j - 1]);
            }
            i = i + GroupSize;
        }

        for (i = size - 1; i >= size - TheOdd1Out; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    return 0;
}