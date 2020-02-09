# Problem 6603

## 로또

### 문제
독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.

로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.

예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])

집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.

### 입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 수는 k (6 < k < 13)이고, 다음 k개 수는 집합 S에 포함되는 수이다. S의 원소는 오름차순으로 주어진다.

입력의 마지막 줄에는 0이 하나 주어진다.

### 출력
각 테스트 케이스마다 수를 고르는 모든 방법을 출력한다. 이때, 사전 순으로 출력한다.

각 테스트 케이스 사이에는 빈 줄을 하나 출력한다.
### 문제 링크
<https://www.acmicpc.net/problem/6603>

### 예제 입력 1
7 1 2 3 4 5 6 7
8 1 2 3 5 8 13 21 34
0

### 예제 출력 1
1 2 3 4 5 6
1 2 3 4 5 7
1 2 3 4 6 7
1 2 3 5 6 7
1 2 4 5 6 7
1 3 4 5 6 7
2 3 4 5 6 7

1 2 3 5 8 13
1 2 3 5 8 21
1 2 3 5 8 34
1 2 3 5 13 21
1 2 3 5 13 34
1 2 3 5 21 34
1 2 3 8 13 21
1 2 3 8 13 34
1 2 3 8 21 34
1 2 3 13 21 34
1 2 5 8 13 21
1 2 5 8 13 34
1 2 5 8 21 34
1 2 5 13 21 34
1 2 8 13 21 34
1 3 5 8 13 21
1 3 5 8 13 34
1 3 5 8 21 34
1 3 5 13 21 34
1 3 8 13 21 34
1 5 8 13 21 34
2 3 5 8 13 21
2 3 5 8 13 34
2 3 5 8 21 34
2 3 5 13 21 34
2 3 8 13 21 34
2 5 8 13 21 34
3 5 8 13 21 34

### solve
- 선택을 하는 문제를 순열을 이용하여 풀기 위해
- 000111의 모든 순열을 구한다고 하면 이것은 6개의 수 중 3개를 뽑는 경우와 같아진다.
- 6개의 번호를 뽑는 것이므로 벡터 d에 1을 6번 삽입하고 나머지는 0을 삽입한다.
- 정답을 출력할 2중 벡터를 생성하여 모든의 벡터를 삽입한다.
	- 이때, d에 1을 먼저 삽입했으므로 1111110 과 같은 형태이다. 즉, 내림차순으로 정렬되어 있기 때문에
	- prev_permutation을 사용하여 이전 순열을 구하여 반복한다.
		- 0을 먼저 삽입하고 next_permutation을 사용한 뒤 ans벡터를 한 번 더 정렬하여도 무방하다.

### 코드 설명
- prev_permutation 사용
```C++
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	while (true)
	{
		int k;
		cin >> k;
		if (k == 0) break;
		vector<int> s(k);

		for (int i = 0; i < k; i++)
			cin >> s[i];
		sort(s.begin(), s.end()); // 입력 수열 정렬

		vector<int> d;
		for (int i = 0; i < 6; i++) // 1은 뽑는 경우 0은 뽑지 않는 경우로하여 해결한다.
			d.push_back(1);	// 6개를 뽑으므로 1을 6번 삽입
		for (int i = 0; i < k - 6; i++)
			d.push_back(0);

		vector<vector<int>> ans; // 출력 벡터

		do {
			vector<int> current;
			for (int i = 0; i < k; i++)
			{
				if (d[i] == 0) continue; // 1인 것만 삽입
				current.push_back(s[i]);
			}
			ans.push_back(current);
		} while (prev_permutation(d.begin(), d.end())); // d에 1을 먼저 삽입했으므로 마지막 순열, 따라서 이전순열을 구하며 반복

		for (auto v : ans) // 2중 벡터 출력
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}

```

- next_permutation 사용
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        vector<int> d;
        for (int i=0; i<n-6; i++) {
            d.push_back(0);
        }
        for (int i=0; i<6; i++) {
            d.push_back(1);
        }
        vector<vector<int>> ans;
        do {
            vector<int> current;
            for (int i=0; i<n; i++) {
                if (d[i] == 1) {
                    current.push_back(a[i]);
                }
            }
            ans.push_back(current);
        } while (next_permutation(d.begin(), d.end()));
        sort(ans.begin(), ans.end());
        for (auto &v : ans) {
            for (int i=0; i<v.size(); i++) {
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}

```
