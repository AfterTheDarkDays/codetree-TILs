#include <stdio.h>

int main() {
    int r, c;
    int n, arr[100][100];
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    scanf("%d %d %d", &n, &r, &c);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    r--; c--; 

    printf("%d ", arr[r][c]);
    while (1) {
        int next_x = -1, next_y = -1;
        int max_value = arr[r][c]; 
        for (int i = 0; i < 4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                if (arr[nx][ny] > arr[r][c]) {
                    next_x = nx;
                    next_y = ny;
                    break;
                }
            }
        }
        if (next_x == -1) 
            break;
        r = next_x;
        c = next_y;
        printf("%d ", arr[r][c]);
    }
    return 0;
}