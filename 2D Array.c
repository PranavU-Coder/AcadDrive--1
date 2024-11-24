#include <stdio.h>
int find_pth_largest(int arr[][100], int N, int P) {
    int temp[N * N];
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[k++] = arr[i][j];
        }
    }
    for (int i = 0; i < N * N - 1; i++) {
        for (int j = i + 1; j < N * N; j++) {
            if (temp[i] > temp[j]) {
                int swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
            }
        }
    }
    return temp[P - 1];
}

void find_indices(int arr[][100], int N, int P, int pth_largest) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == pth_largest) {
                printf("%d %d %d\n", i, j, pth_largest);
                return;
            }
        }
    }
}

int main() {
    int N, P;
    int arr[100][100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    scanf("%d", &P);
    int pth_largest = find_pth_largest(arr, N, P);
    find_indices(arr, N, P, pth_largest);
    return 0;
}
