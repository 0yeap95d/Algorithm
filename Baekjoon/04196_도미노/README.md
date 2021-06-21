# <img src="https://d2gd6pc034wcta.cloudfront.net/tier/17.svg" width="30">  4196: 도미노

### 문제 링크

> https://www.acmicpc.net/problem/4196



### 알고리즘 분류

>- 그래프 이론
>- 강한 연결 요소



### 문제 및 해결

>- ⏱ 풀이시간 128분
>- SCC를 이용하는 문제라는 것을 인지한 후 풀 수 있었음
>- 타잔 알고리즘을 이용하여 SCC를 하나의 정점이라고 생각하여 DAG를 만들어 주었음
>- 모든 간선을 다시 탐색하면서 서로 다른 SCC인 경우 도착지점의 Indegree를 증가시켜주었음
>- Indegree의 값이 0인 개수를 카운트하여 출력

