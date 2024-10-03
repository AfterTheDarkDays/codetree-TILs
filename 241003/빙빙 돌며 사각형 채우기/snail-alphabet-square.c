#include <stdio.h>

#define MAX_N 100

char grid[MAX_N][MAX_N];  
int dx[4] = {0, 1, 0, -1}; 
int dy[4] = {1, 0, -1, 0};

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int x = 0, y = 0;  
    int dir = 0;  
    char current_char = 'A';  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n * m; i++) {
        grid[x][y] = current_char;
        current_char = (current_char == 'Z') ? 'A' : current_char + 1;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 0) {
            dir = (dir + 1) % 4; 
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}