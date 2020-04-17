# 프로그래머스 - 네트워크

## 네트워크

### 문제
네트워크란 컴퓨터 상호 간에 정보를 교환할 수 있도록 연결된 형태를 의미합니다. 예를 들어, 컴퓨터 A와 컴퓨터 B가 직접적으로 연결되어있고, 컴퓨터 B와 컴퓨터 C가 직접적으로 연결되어 있을 때 컴퓨터 A와 컴퓨터 C도 간접적으로 연결되어 정보를 교환할 수 있습니다. 따라서 컴퓨터 A, B, C는 모두 같은 네트워크 상에 있다고 할 수 있습니다.

컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수로 주어질 때, 네트워크의 개수를 return 하도록 solution 함수를 작성하시오.

### 제한사항
- 컴퓨터의 개수 n은 1 이상 200 이하인 자연수입니다.
- 각 컴퓨터는 0부터 n-1인 정수로 표현합니다.
- i번 컴퓨터와 j번 컴퓨터가 연결되어 있으면 computers[i][j]를 1로 표현합니다.
- computer[i][i]는 항상 1입니다.

### 입출력 예
n	computers	return
3	[[1, 1, 0], [1, 1, 0], [0, 0, 1]]	2
3	[[1, 1, 0], [1, 1, 1], [0, 1, 1]]	1


### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/43162>

### solve
- 백준의 11724번 문제와 거의 똑같은 문제이다.
	- <https://kyu9341.github.io/algorithm/2020/02/26/algorithm11724/>
- dfs 또는 bfs를 사용하여 해결할 수 있다. 여기서는 dfs를 사용하였다.
	- 새로운 벡터에 네트워크의 연결 정보를 새로 담고, dfs를 통해 현재 노드에서 연결된 모든 노드를 체크한다.
	- 체크되지 않은 노드인 경우에만 다시 dfs를 수행하여 dfs가 실행된 횟수를 구하면 그게 네트워크의 개수이다.

### 코드 설명
```C++
#include <string>
#include <vector>

using namespace std;
bool check[200]; // 탐색된 노드인지 판별하기 위한 배열
vector<int> a[200]; // 네트워크 연결 정보를 저장하기 위한 벡터

void dfs(int node, int n) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (!check[next]) {
			dfs(next, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (computers[i][j]) {
				a[i].push_back(j); // 연결
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) { // 아직 연결되지 않은 노드만 탐색
			answer++; // 네트워크의 개수 카운트
			dfs(i, n);
		}
	}

	return answer;
}
```
