n, m, t = map(int, input().split())

graph = [list(map(int, input().split())) for _ in range(n)]

marble = []
for _ in range(m):
    r, c = map(int, input().split())
    marble.append((r-1, c-1)) 

dx = [-1, 1, 0, 0] 
dy = [0, 0, -1, 1]

for _ in range(t):
    next_position = {}

    for r, c in marble:
        max_value = -1
        next_r, next_c = r, c
        
        for i in range(4):
            nr, nc = r + dx[i], c + dy[i]
            
            if 0 <= nr < n and 0 <= nc < n:
                if graph[nr][nc] > max_value:
                    max_value = graph[nr][nc]
                    next_r, next_c = nr, nc

        if (next_r, next_c) in next_position:
            next_position[(next_r, next_c)] += 1
        else:
            next_position[(next_r, next_c)] = 1

    new_marble = []
    for position, count in next_position.items():
        if count == 1:
            new_marble.append(position)
    
    marble = new_marble
print(len(marble))