# Problem 1339

## 단어 수학

### 문제
민식이는 수학학원에서 단어 수학 문제를 푸는 숙제를 받았다.

단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져 있다. 이때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다. 같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개 이상의 알파벳이 같은 숫자로 바뀌어지면 안 된다.

예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 두 수의 합은 99437이 되어서 최대가 될 것이다.

N개의 단어가 주어졌을 때, 그 수의 합을 최대로 만드는 프로그램을 작성하시오.

### 입력
첫째 줄에 단어의 개수 N(1 ≤ N ≤ 10)이 주어진다. 둘째 줄부터 N개의 줄에 단어가 한 줄에 하나씩 주어진다. 단어는 알파벳 대문자로만 이루어져있다. 모든 단어에 포함되어 있는 알파벳은 최대 10개이고, 수의 최대 길이는 8이다. 서로 다른 문자는 서로 다른 숫자를 나타낸다.

### 출력
첫째 줄에 주어진 단어의 합의 최댓값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1339>

### 예제 입력 1
2
AAA
AAA

### 예제 출력 1
1998

### 예제 입력 2
2
GCF
ACDEB

### 예제 출력 2
99437

### 예제 입력 3
10
A
B
C
D
E
F
G
H
I
J

### 예제 출력 3
45

### 예제 입력 3
2
AB
BA

### 예제 출력 3
187

### solve
- 입력받은 문자열에 존재하는 모든 문자를 letters라는 char형 벡터에 저장하여 중복 원소를 제거한다.
- 각 문자에 대입할 숫자를 저장할 벡터(d)에 합을 최대로 만들기 위해 가장 큰 수(9)부터 벡터의 크기만큼 추가한다.
- 9부터 내림차순으로 저장되어있으므로 이전순열을 확인하며 모든 경우를 탐색한다.
- 다음과 같이 하나의 경우를 확인한다.
  - 알파벳에 해당하는 숫자를 저장할 배열(alpha)에 다음과 같이 해당 숫자를 저장한다.
    - alpha[letters[i] - 'A'] = d[i]; // A : 0 부터 해당하는 알파벳의 숫자 저장
  - 알파벳에 해당하는 숫자를 가져와 입력 문자열에 대입하여 계산한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>

using namespace std;

int alpha[26]; // 알파벳에 해당하는 숫자를 저장할 배열
int calc(vector<string>& a, vector<char>& letters, vector<int>& d) {
	int m = letters.size(); // 중복없는 알파벳의 수
	int sum = 0;
	for (int i = 0; i < m; i++) {
		alpha[letters[i] - 'A'] = d[i]; // A : 0 부터 해당하는 알파벳의 숫자 저장
	}
	for (string s : a) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x - 'A']; // 알파벳에 해당하는 숫자를 가져와 계산
		}
		sum += now; // 한 문자열 누적
	}
	return sum;
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	vector<string> a(n);
	vector<char> letters;

	while (n--)
	{
		string str;
		getline(cin, str);
		a.push_back(str);		
		for (int i = 0; i < str.size(); i++)
			letters.push_back(str[i]); // 문자열의 모든 문자를 저장
	}
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end()); // 벡터의 중복 원소 제거
	// 중복을 제거한 후 벡터의 크기는 입력된 문자의 총 개수
	int m = letters.size();
	vector<int> d; // 각 문자에 대입할 숫자를 저장
	for (int i = 9; i > 9 - m; i--) // 합을 최대로 만들기 위해 가장 큰 수부터 벡터의 크기만큼 추가
		d.push_back(i);

	int ans = 0;
	do
	{
		int now = calc(a, letters, d);
		if (ans < now) ans = now;
	} while (prev_permutation(d.begin(), d.end())); // 9부터 삽입했으므로 이전 순열을 확인

	cout << ans << '\n';
}

```
