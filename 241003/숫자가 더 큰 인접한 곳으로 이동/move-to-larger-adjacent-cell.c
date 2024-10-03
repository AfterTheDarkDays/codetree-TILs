#include <stdio.h>

int main() {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int n, r, c, found;
    int grd[100][100];

    scanf("%d %d %d", &n, &r, &c);

    for(int i = 0; i < n; i++)
        for (int j = 0; j <n; j++)
             scanf("%d", &grd[i][j]);

    r--;
    c--;

    printf("%d ", grd[r][c]);
    while(1){
        found = 0;

        for(int i =0; i < 4; i++){
            int nx = r + dx[i];
            int ny= c + dy[i];

            if((nx < 0 || nx >= n ) || (ny < 0 || ny >= n))
                continue;
            
            if (grd[nx][ny] > grd[r][c]){
                r = nx;
                c = ny;
                printf("%d ", grd[r][c]);

                found = 1;
                break;
            }
        }
        if (!found) break;
    }

    return 0;
}