#include <stdio.h>

#define MAX_N 100

int grid[MAX_N][MAX_N]; 
int dx[4] = {-1, 1, 0, 0};  
int dy[4] = {0, 0, -1, 1};

int isComfortable(int r, int c, int N) {
    int count = 0;
    
    for (int i = 0; i < 4; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];
        

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && grid[nx][ny]) {
            count++;
        }
    }

    return count == 3;
}

int main() {
    int N, M;

    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        

        r--; c--;
        grid[r][c] = 1;
        
        if (isComfortable(r, c, N)) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }

    return 0;
}