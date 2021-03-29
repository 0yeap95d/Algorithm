# <img src="https://d2gd6pc034wcta.cloudfront.net/tier/8.svg" width="30">  10973: 이전 순열

### 문제 링크

> https://www.acmicpc.net/problem/10973



### 알고리즘 분류

>- 수학



### 문제 및 해결

>- ⏱ 풀이시간 00분
>- prev_permutation 함수가 존재하지만, 순열의 기본 이론대로 해결해보았음
>- 1. 뒤에서부터 오름차순이 아닌 부분을 찾음
>  2. 그 부분에서 부터 뒤에 나오는 숫자들 중 해당 숫자보다 첫번째로 작은 숫자와 자리를 바꿔줌
>  3. 바꾼 자리 뒤에 모든 숫자를 뒤집어줌
