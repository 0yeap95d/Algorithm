import sys

while True:
    try:
        n = int(sys.stdin.readline())
        temp = 0
        while True:
            temp = temp * 10 + 1
            if temp % n == 0:
                print(len(str(temp)))
                break
    except:
        break
