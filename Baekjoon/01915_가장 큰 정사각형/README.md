# <img src="https://d2gd6pc034wcta.cloudfront.net/tier/11.svg" width="30">  1915: 가장 큰 정사각형

### 문제 링크

> https://www.acmicpc.net/problem/1915



### 알고리즘 분류

>- 다이나믹 프로그래밍



### 문제 및 해결

>- ⏱ 풀이시간 22분
>
>- 간단한 점화식으로 해결할 수 있었음
>  $$
>  DP[i][j] = Min(DP[i - 1][j - 1], Min(DP[i - 1][j], DP[i][j - 1])) + 1
>  $$
>  

