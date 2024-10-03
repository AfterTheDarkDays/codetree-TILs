#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N); 
    
    int x = 0, y = 0; 
    int total_time = 0; 
    
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1}; 
    
    for (int i = 0; i < N; i++) {
        char direction;
        int distance;
        scanf(" %c %d", &direction, &distance);
        
        int dir_idx; 
        if (direction == 'W') {
            dir_idx = 0;
        } else if (direction == 'S') {
            dir_idx = 1;
        } else if (direction == 'E') {
            dir_idx = 2;
        } else if (direction == 'N') {
            dir_idx = 3;
        }
        
        for (int j = 0; j < distance; j++) {
            x += dx[dir_idx];
            y += dy[dir_idx];
            total_time++;
            
            if (x == 0 && y == 0) {
                printf("%d\n", total_time);
                return 0;
            }
        }
    }

    printf("-1\n");
    
    return 0;
}