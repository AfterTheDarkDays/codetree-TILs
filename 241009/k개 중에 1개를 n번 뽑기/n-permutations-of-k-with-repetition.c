#include <stdio.h>

int arr[8];

void generate_permutations(int depth, int N, int K) {
    if (depth == N) {
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = 1; i <= K; i++) {
        arr[depth] = i;
        generate_permutations(depth + 1, N, K);
    }
}

int main() {
    int K, N;

    scanf("%d %d", &K, &N);
    generate_permutations(0, N, K);
    
    return 0;
}