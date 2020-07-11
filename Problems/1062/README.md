# Problem 1062

## 가르침

### 문제
남극에 사는 김지민 선생님은 학생들이 되도록이면 많은 단어를 읽을 수 있도록 하려고 한다. 그러나 지구온난화로 인해 얼음이 녹아서 곧 학교가 무너지기 때문에, 김지민은 K개의 글자를 가르칠 시간 밖에 없다. 김지민이 가르치고 난 후에는, 학생들은 그 K개의 글자로만 이루어진 단어만을 읽을 수 있다. 김지민은 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지 고민에 빠졌다.

남극언어의 모든 단어는 "anta"로 시작되고, "tica"로 끝난다. 남극언어에 단어는 N개 밖에 없다고 가정한다. 학생들이 읽을 수 있는 단어의 최댓값을 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 단어의 개수 N과 K가 주어진다. N은 50보다 작거나 같은 자연수이고, K는 26보다 작거나 같은 자연수 또는 0이다. 둘째 줄부터 N개의 줄에 남극 언어의 단어가 주어진다. 단어는 영어 소문자로만 이루어져 있고, 길이가 8보다 크거나 같고, 15보다 작거나 같다. 모든 단어는 중복되지 않는다.

### 출력
첫째 줄에 김지민이 K개의 글자를 가르칠 때, 학생들이 읽을 수 있는 단어 개수의 최댓값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1062>

### 예제 입력 1
3 6
antarctica
antahellotica
antacartica

### 예제 출력 1
2

### solve
- 기본적으로 ['a', 'n', 't', 'i', 'c'] 의 5개의 문자를 알지 못하면 읽을 수 있는 단어의 개수는 0이된다.
- 각각의 단어에 위의 5가지 문자를 제외한 문자만 set의 벡터를 만들어 각각의 set에 추가한다.
- k가 5 이상인 경우 5개 문자 외의 k - 5 개의 문자의 조합을 구하여 해당 조합의 문자로 읽을 수 있는 단어의 최댓값을 구하면 된다.
- 이 때, 기본 5개의 문자 외에 다른 문자가 없이 중복된 문자로 추가되는 경우를 체크하기 위해 벡터의 현재 set이 비어있는 경우에도 갯수를 증가시킨다.

### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<set>

using namespace std;
int n, k;
set<char> s;
vector<set<char>> v;
int ans = 0;

void dfs(int index, char start) {
	// k - 5 개를 뽑아서 해당 문자로 몇 개를 만들 수 있는지 확인
	if (index == k - 5) {
		int cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			bool ok = true;
			for (auto it = v[i].begin(); it != v[i].end(); it++) {
				if (s.find(*it) == s.end()) {
					ok = false;
					break;
				}
			}
			// 포함되지 않은 다른 문자가 없는 경우
			if (ok || v[i].empty()) cnt++;
		}
		if (ans < cnt) ans = cnt;
		return;
	}

	for (char i = start; i <= 'z'; i++) {
		if (s.find(i) != s.end()) continue;
		s.insert(i);
		dfs(index + 1, i);
		s.erase(i);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// 5개의 문자를 먼저 입력
	s.insert('a');
	s.insert('n');
	s.insert('t');
	s.insert('i');
	s.insert('c');

	cin >> n >> k;
	cin.ignore();
	v.resize(n);
	// 각각 단어의 기본 5개의 문자를 외의 문자만 각각의 set에 추가
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 4; j < input.size() - 4; j++) {
			if (s.find(input[j]) == s.end()) {
				v[i].insert(input[j]);
			}
		}
	}
	// 5개 미만의 수를 가르치면 읽을 수 있는 단어가 없음
	if(k >= 5) dfs(0, 'a');

	cout << ans << '\n';
}
```
