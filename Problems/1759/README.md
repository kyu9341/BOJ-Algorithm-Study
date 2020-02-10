# Problem 1759

## 암호 만들기

### 문제
바로 어제 최백준 조교가 방 열쇠를 주머니에 넣은 채 깜빡하고 서울로 가 버리는 황당한 상황에 직면한 조교들은, 702호에 새로운 보안 시스템을 설치하기로 하였다. 이 보안 시스템은 열쇠가 아닌 암호로 동작하게 되어 있는 시스템이다.

암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다. 또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다. 즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다. 이 알파벳을 입수한 민식, 영식 형제는 조교들의 방에 침투하기 위해 암호를 추측해 보려고 한다. C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 두 정수 L, C가 주어진다. (3 ≤ L ≤ C ≤ 15) 다음 줄에는 C개의 문자들이 공백으로 구분되어 주어진다. 주어지는 문자들은 알파벳 소문자이며, 중복되는 것은 없다.

### 출력
각 줄에 하나씩, 사전식으로 가능성 있는 암호를 모두 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1759>

### 예제 입력 1
4 6
a t c i s w

### 예제 출력 1
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw

### solve
- 순열을 사용하여 풀 수 있고 재귀를 사용하여 풀 수 있다.
- 순열
	- 선택을 하는 문제를 순열을 이용하여 풀기 위해
	- 000111의 모든 순열을 구한다고 하면 이것은 6개의 수 중 3개를 뽑는 경우와 같아진다.
	- 4개의 암호를 뽑는 것이므로 벡터 d에 1을 4번 삽입하고 나머지는 0을 삽입한다.
	- a, e, i, o, u의 모음인 경우 vowel변수에 true를 넣어 모음이 하나 이상 들어갔음을 판별하고
	- 자음인 경우 자음 개수를 카운트하여 2개 이상 자음이 포함되었는지 판별하여 두 조건을 모두 만족하는 경우 벡터에 추가한다.

- 재귀
	- 암호 알파벳 수와 암호 후보 알파벳이 있는 벡터, 결과 암호, 인덱스를 인자로 하는 재귀함수를 작성
	- 암호 알파벳 수가 다 채워진 경우 암호에 모음 하나, 자음 두개가 포함되었는지 검사하는 함수를 통해 정상적인 암호라면 출력한다.
	- 정답을 구할 수 없는 경우 리턴(모든 a의 알파벳을 사용했는데 비밀번호를 만들지 못한 경우)
	- i번째 인덱스의 알파벳을 사용하는 경우와 사용하지 않는 경우 각각 재귀함수를 호출

### 코드 설명
- 순열 이용
```C++
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int l, c;
	cin >> l >> c;
	vector<char> a(c);
	for (int i = 0; i < c; i++) // 후보 문자 입력
		cin >> a[i];
	sort(a.begin(), a.end());

	vector<int> d;
	for (int i = 0; i < c - l; i++) // 0과 1의 순열을 이용해 선택의 경우를 구함
		d.push_back(0);
	for (int i = 0; i < l; i++)
		d.push_back(1);

	vector<vector<char>> ans;

	do {
		vector<char> now;
		int vowel = false; // 모음 포함 여부
		int consonant = 0; // 자음 개수 카운트
		for (int i = 0; i < c; i++)
		{
			if (d[i] == 1)
			{
				if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') // 모음일 경우
				{
					vowel = true;
					now.push_back(a[i]);
				}
				else
				{
					consonant++; // 자음 개수
					now.push_back(a[i]);
				}

			}
		}
		if (vowel && consonant >= 2) // 모음이 있고 자음이 2개 이상인 경우에만 추가
			ans.push_back(now);
	} while (next_permutation(d.begin(), d.end()));

	sort(ans.begin(), ans.end()); // 사전순 출력
	for (auto &v : ans)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
		cout << '\n';
	}
}

```

- 재귀 함수 이용
```cpp

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool check(string password) // 만들어진 암호가 자음 두개 모음 하나 이상을 포함하는 암호인지 확인하는 함수
{
	int ja = 0;
	int mo = 0;

	for (auto x : password)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		{
			mo++;
		}
		else
		{
			ja++;
		}
	}
	if (ja >= 2 && mo >= 1)
		return true;
	else
		return false;
}

void go(int n, vector<char>& a, string password, int i) // n : 암호알파벳 수, a는 사용할 수 있는 알파벳 벡터, password : 결과 암호, i : 인덱스
{
	if (password.length() == n) // 암호 알파벳 수가 다 채워진 경우
	{
		if (check(password))
		{
			cout << password << '\n';
		}
		return;
	}
	if (i >= a.size()) return; // 모든 a의 알파벳을 사용했는데 비밀번호를 만들지 못한 경우
	go(n, a, password + a[i], i + 1); // a[i] 알파벳을 사용하는 경우
	go(n, a, password, i + 1); // a[i] 알파벳을 사용하지 않는 경우
}


int main(void)
{
	int l, c;
	cin >> l >> c;
	vector<char> a(c);
	for (int i = 0; i < c; i++) // 후보 문자 입력
		cin >> a[i];
	sort(a.begin(), a.end());

	string password = "";

	go(l, a, password, 0);

}

```
