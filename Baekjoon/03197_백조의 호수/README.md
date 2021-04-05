# <img src="https://d2gd6pc034wcta.cloudfront.net/tier/15.svg" width="30">  3197: 백조의 호수

### 문제 링크

> https://www.acmicpc.net/problem/3197



### 알고리즘 분류

>- 그래프 이론
>- 자료 구조
>- 그래프 탐색
>- 너비 우선 탐색
>- 분리 집합



### 문제 및 해결

>- ⏱ 풀이시간 120분 초과
>- 각 구역을 넘버링해주고 빙판이 녹을때마다 연결되는 숫자들을 Union-Find 알고리즘을 이용하여 연결시켜주었음
>- Input 데이터를 char형으로 사용하면서 문제가 발생하였음
>  - 런타임 에러(ArrayIndexOutOfBound)
>  - 구역의 갯수가 char형으로 표현할수 있는 정수의 범위를 넘어가면서 문제가 발생하였음
>  - 비슷한 유형의 문제도 char형으로 처리할때 주의할 것!!!
