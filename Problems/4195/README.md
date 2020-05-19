# Problem 4195

## 친구 네트워크

### 문제
민혁이는 소셜 네트워크 사이트에서 친구를 만드는 것을 좋아하는 친구이다. 우표를 모으는 취미가 있듯이, 민혁이는 소셜 네트워크 사이트에서 친구를 모으는 것이 취미이다.

어떤 사이트의 친구 관계가 생긴 순서대로 주어졌을 때, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

친구 네트워크란 친구 관계만으로 이동할 수 있는 사이를 말한다.

### 입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스의 첫째 줄에는 친구 관계의 수 F가 주어지며, 이 값은 100,000을 넘지 않는다. 다음 F개의 줄에는 친구 관계가 생긴 순서대로 주어진다. 친구 관계는 두 사용자의 아이디로 이루어져 있으며, 알파벳 대문자 또는 소문자로만 이루어진 길이 20 이하의 문자열이다.

### 출력
친구 관계가 생길 때마다, 두 사람의 친구 네트워크에 몇 명이 있는지 구하는 프로그램을 작성하시오.

### 문제 링크
<https://www.acmicpc.net/problem/5052>

### 예제 입력 1
2
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Betty Wilma
Barney Betty

### 예제 출력 1
2
3
4
2
2
4

### solve
- 맵에 각 이름을 번호를 매겨주고 유니온 파인드를 이용하여 입력된 두 친구의 부모 노드를 구한다.
- 더 작은 번호를 가지는 노드가 부모가 되도록 구성하였고, 두 친구의 다르면 부모를 합치고 다르다면 바로 더 작은 번호를 가지는 부모 노드의 크기를 출력한다.
	- setSize배열에 해당 번호를 부모로 하는 집합의 원소의 수를 기록하고, 부모를 합치는 함수에서 부모가 되는 번호에 집합의 원소 수를 합쳐준다.

### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<map>
#include<cmath>

using namespace std;
const int MAX = 100000 + 1;
int F;
int setSize[MAX]; // 각 원소를 부모로 하는 집합의 원소 수
int parent[MAX]; // 부모를 저장할 배열

int getParent(int x) { // 부모를 찾는 함수
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) { // 부모를 합치며 집합의 원소 수 합침
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
		setSize[a] += setSize[b]; // 집합의 원소 수를 더해줌
	}
	else {
		parent[a] = b;
		setSize[b] += setSize[a];
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> F;
	while (F--) {
		int cnt = 0;
		int t;
		cin >> t;

		map<string, int> m;
		for (int i = 0; i < MAX; i++) {
			parent[i] = i; // 부모 배열 및 집합 크기 초기화
			setSize[i] = 1;
		}

		while (t--) {

			string a, b;
			cin >> a >> b;
			// map을 이용해서
			if (m[a] == 0) m[a] = ++cnt;
			if (m[b] == 0) m[b] = ++cnt;
			int parentA = getParent(m[a]);
			int parentB = getParent(m[b]);
			if (parentA != parentB) { // 부모가 다르면
				unionParent(m[a], m[b]); // 부모를 합친다.
			}
			cout << setSize[min(parentA, parentB)] << '\n';

		}
	}

}
```
