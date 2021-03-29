import sys

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
check = {}
answer = 0


def isIn(x, y):
    return 0 <= x < 5 and 0 <= y < 5


def DFS(x, y, num):
    if len(num) >= 6:
        if num not in check:
            check[num] = True
            global answer
            answer = answer + 1
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if isIn(nx, ny):
            DFS(nx, ny, num + board[nx][ny])


# 숫자판 입력
board = [list(map(str, sys.stdin.readline().split())) for _ in range(5)]

# 각 위치에서 가능한 숫자 탐색
for i in range(5):
    for j in range(5):
        DFS(i, j, "")

# 정답 출력
print(answer)