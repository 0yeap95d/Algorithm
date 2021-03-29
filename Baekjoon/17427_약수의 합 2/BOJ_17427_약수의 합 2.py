import sys

n = int(sys.stdin.readline())
ans = 0

for a in range(1, n + 1):
    b = n // a
    ans = ans + a * b

print(ans)