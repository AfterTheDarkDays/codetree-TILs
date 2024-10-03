#include <stdio.h>

#define MAX_NUM 100
#define DIR_NUM 4

int n, m;
int arr[MAX_NUM][MAX_NUM];

int dx[DIR_NUM] = {0, 1, 0, -1};
int dy[DIR_NUM] = {1, 0, -1, 0};

int curr_x = 0, curr_y = 0;  
int dir = 0;       

int InRange(int x, int y){
    return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    scanf("%d %d", &n, &m);
    arr[curr_x][curr_y] = 1;
 
    for(int i = 2; i <= n * m; i++) {
        int next_x = curr_x + dx[dir], next_y = curr_y + dy[dir];

        if(!InRange(next_x, next_y) || arr[next_x][next_y] != 0)
            dir = (dir + 1) % 4;

        curr_x = curr_x + dx[dir];
        curr_y = curr_y + dy[dir];
        arr[curr_x][curr_y] = i;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) 
            printf("%d ", arr[i][j]);
        printf("\n");
    }

    return 0;
}