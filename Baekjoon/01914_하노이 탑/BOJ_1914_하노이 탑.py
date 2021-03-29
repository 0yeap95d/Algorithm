import sys


def hanoi(s, m, t, cnt):
    if cnt == 0:
        return
    hanoi(s, t, m, cnt - 1)
    print(f"{s} {t}")
    hanoi(m, s, t, cnt - 1)


n = int(sys.stdin.readline())
print(pow(2, n) - 1)
if n <= 20:
    hanoi(1, 2, 3, n)
