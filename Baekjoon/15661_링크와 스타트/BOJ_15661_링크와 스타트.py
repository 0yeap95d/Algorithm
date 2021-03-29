import sys
import math

# 입력
n = int(sys.stdin.readline())
stats = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
team = [False] * n
answer = math.inf

# 능력치 구하기
def get_score(isTrue):
    result = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            if team[i] == team[j] == isTrue:
                result += stats[i][j] + stats[j][i]
    return result


# 팀 나누기
def divide_team(idx, cnt):
    if idx == n:
        if cnt != 0 and cnt != n:
            global answer
            answer = min(answer, abs(get_score(True) - get_score(False)))
        return

    divide_team(idx + 1, cnt)
    team[idx] = True
    divide_team(idx + 1, cnt + 1)
    team[idx] = False


# solve
divide_team(0, 0)
print(answer)
