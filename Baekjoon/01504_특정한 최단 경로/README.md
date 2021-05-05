# <img src="https://d2gd6pc034wcta.cloudfront.net/tier/12.svg" width="30">  1504: 특정한 최단 경로

### 문제 링크

> https://www.acmicpc.net/problem/1504



### 알고리즘 분류

>- 그래프 이론
>- 다익스트라



### 문제 및 해결

>- ⏱ 풀이시간 47분
>
>- 플로이드 와샬 알고리즘을 이용해 해결
>
> ```c++
> // 자기 자신으로 돌아오는 부분을 INF로 설정해주어서 틀렸었음
> /*
> 플로이드 알고리즘에서 dist[i][i] + dist[i][j] 부분을 업데이트 해줄 수 없기때문
> 따라서 i == j 인 경우 0으로 두어야 제대로 된 값을 구할 수 있음
> */
> for (int i = 0; i <= N; i++) {
> 	for (int j = 0; j <= N; j++) {
> 		dist[i][j] = INF;
> 	}
> }
>
> // 수정 후
> for (int i = 0; i <= N; i++) {
> 	for (int j = 0; j <= N; j++) {
> 		if (i == j) continue;
> 		dist[i][j] = INF;
> 	}
> }
> ```
>
>- 위 방법보다는 다익스트라를 3번 돌릴때 시간복잡도가 훨씬 짧음 (플로이드는 n^3)

