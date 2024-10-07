n, m, q = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]

def right_wind(r: int):
    row = board[r]
    temp = row[0]
    for i in range(m - 1):
        row[i] = row[i + 1]
    row[-1] = temp
    return row

def left_wind(r: int):
    row = board[r]
    temp = row[-1]
    for i in range(m - 1, 0, -1):
        row[i] = row[i - 1]
    row[0] = temp
    return row

def in_range(cr: int, nr: int):
    if nr < 0 or nr >= n:
        return False

    for i in range(m):
        if board[cr][i] == board[nr][i]:
            return True

    return False

 
def simulate(r:int, d: int):
    if d == 0:
        board[r] = left_wind(r)
    else:
        board[r] = right_wind(r)
        
for _ in range(q):
    r, d = list(input().split())
    r = int(r) - 1
    d = 1 if d == 'R' else 0
    du = dd = d
    simulate(r, d)
 
    for cr in range(r, 0, -1):
        du ^= 1
        if in_range(cr, cr - 1):
            simulate(cr - 1, du)
        else:
            break
    for cr in range(r, n - 1):
        dd ^= 1
        if in_range(cr, cr + 1):
            simulate(cr + 1, dd)
        else:
            break

for row in board:
    print(*row)