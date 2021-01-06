# Disjoint Set (분리 집합)



### DisJoint Set이란?

> - **서로 중복되지 않는 부분 집합**들로 나눠진 원소들에 대한 정보를 저장 및 조작하는 자료구조
> - **서로소 집합 자료구조**



### Union-Find 알고리즘

>- DisJoint Set을 표현할 때 사용하는 알고리즘
>- 배열, 연결리스트, 트리 등 구현가능 (트리가 제일 효율적임)
>
>- 세 가지 연산 MakeSet, Find, Union을 이용하여 구현



### Union-Find 구현

>- #### 기본 구현 방법
>
>```c++
>int root[MAX_SIZE];
>
>void makeSet() {
>	for (int i = 1; i <= N; i++)
>		root[i] = i;
>}
>
>int Find(int x) {
>	if (root[x] == x) return x;
>	return root[x] = Find(root[x]);
>}
>
>void Union(int x, int y) {
>	x = Find(x);
>	y = Find(y);
>	
>    // 두 값의 root가 같으면 이미 같은 트리
>    if (x == y) return;
>    
>    // 두 값이 다르면 합침
>    root[x] = y;
>}
>```



>- #### 최적화 (union-by-rank)
>
>    - 최악의 경우 트리가 한쪽으로만 몰리는 현상 발생
>    - Union 연산할때 높이가 낮은 트리를 높은 트리 밑에 넣어서 해결가능
>    - 상황에 따라 값의 크기를 기준으로 하는 union-by-size도 비슷하게 구현가능
>
>```c++
>int root[MAX_SIZE];
>int height[MAX_SIZE];
>
>void makeSet() {
>	for (int i = 1; i <= N; i++) {
>		root[i] = i;
>		height[i] = 0;
>	}
>}
>
>int Find(int x) {
>	if (root[x] == x) return x;
>	return root[x] = Find(root[x]);
>}
>
>void Union(int x, int y) {
>	x = Find(x);
>	y = Find(y);
>
>	// 두 값의 root가 같으면 이미 같은 트리
>	if (x == y) return;
>
>	// x의 root를 y로 변경
>	if (height[x] < height[y]) root[x] = y;
>	
>	// y의 root를 x로 변경
>	else {
>		root[y] = x;
>
>		// 만약 높이가 같다면 합친 후 (x의 높이 + 1)
>		if (height[x] == height[y]) height[x]++;
>	}
>}
>```
>

