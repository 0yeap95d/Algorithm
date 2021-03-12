import sys

S, N = map(int, sys.stdin.readline().split())
N = str(N)
W = S + 2
H = 2 * S + 3
Line = [
    [1, 1, 1, 0, 1, 1, 1],
    [0, 0, 1, 0, 0, 1, 0],
    [1, 0, 1, 1, 1, 0, 1],
    [1, 0, 1, 1, 0, 1, 1],
    [0, 1, 1, 1, 0, 1, 0],
    [1, 1, 0, 1, 0, 1, 1],
    [1, 1, 0, 1, 1, 1, 1],
    [1, 0, 1, 0, 0, 1, 0],
    [1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 0, 1, 1],
]
Ans = [[]] * H


def setLine(n):
    result = [[" " for _ in range(W + 1)] for _ in range(H)]
    for i in range(len(Line[n])):
        if Line[n][i] == 0:
            continue
        if i == 0:
            for j in range(1, W - 1):
                result[0][j] = "-"
        if i == 1:
            for j in range(1, H // 2):
                result[j][0] = "|"
        if i == 2:
            for j in range(1, H // 2):
                result[j][W - 1] = "|"
        if i == 3:
            for j in range(1, W - 1):
                result[H // 2][j] = "-"
        if i == 4:
            for j in range(H // 2 + 1, H - 1):
                result[j][0] = "|"
        if i == 5:
            for j in range(H // 2 + 1, H - 1):
                result[j][W - 1] = "|"
        if i == 6:
            for j in range(1, W - 1):
                result[H - 1][j] = "-"

    for i in range(len(Ans)):
        Ans[i] = Ans[i] + result[i]


for n in N:
    setLine(int(n))

for ans in Ans:
    print("".join(ans))
