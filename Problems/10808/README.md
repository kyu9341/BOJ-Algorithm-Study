# Problem 10808

## 알파벳 개수

### 문제
알파벳 소문자로만 이루어진 단어 S가 주어진다. 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

### 출력
단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/10808>

### 예제 입력 1
baekjoon

### 예제 출력 1
1 1 0 0 1 0 0 0 0 1 1 0 0 1 2 0 0 0 0 0 0 0 0 0 0 0

### solve
- 각 알파벳 개수를 담을 배열을 만들고 문자열의 각 인덱스에 접근하여 해당하는 알파벳의 인덱스를 증가시킨다.
- 이때 현재 문자열의 알파벳에 'a'의 아스키 코드 값을 빼주어 해당하는 알파벳의 인덱스를 맞춰준다.


### 코드 설명
```C++
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	int alphabet[26] = {0}; // 각 알파벳 개수를 담을 배열

	cin >> str;
	int size = str.size();

	for (int i = 0; i < size; i++)
	{
		alphabet[str[i] - 'a']++; // 'a'의 아스키 코드 값을 빼주어 해당하는 알파벳의 인덱스를 맞춰줌
	}

	for (auto x : alphabet)
		cout << x << ' ';

	cout << '\n';

	return 0;
}
```
