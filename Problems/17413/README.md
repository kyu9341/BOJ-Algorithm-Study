# Problem 17413

## 단어 뒤집기 2

### 문제 
문자열 S가 주어졌을 때, 이 문자열에서 단어만 뒤집으려고 한다.

먼저, 문자열 S는 아래와과 같은 규칙을 지킨다.

알파벳 소문자('a'-'z'), 숫자('0'-'9'), 공백(' '), 특수 문자('<', '>')로만 이루어져 있다.
문자열의 시작과 끝은 공백이 아니다.
'<'와 '>'가 문자열에 있는 경우 번갈아가면서 등장하며, '<'이 먼저 등장한다. 또, 두 문자의 개수는 같다.
태그는 '<'로 시작해서 '>'로 끝나는 길이가 3 이상인 부분 문자열이고, '<'와 '>' 사이에는 알파벳 소문자와 공백만 있다. 단어는 알파벳 소문자와 숫자로 이루어진 부분 문자열이고, 연속하는 두 단어는 공백 하나로 구분한다. 태그는 단어가 아니며, 태그와 단어 사이에는 공백이 없다.

### 입력 
첫째 줄에 문자열 S가 주어진다. S의 길이는 100,000 이하이다.

### 출력 
첫째 줄에 문자열 S의 단어를 뒤집어서 출력한다.


### 문제 링크
<https://www.acmicpc.net/problem/17413>

### 예제 입력 1
baekjoon online judge


### 예제 출력 1 
noojkeab enilno egduj

### 예제 입력 2 
<open>tag<close>

### 예제 출력 2 
<open>gat<close>

### 예제 입력 3 
<ab cd>ef gh<ij kl>

### 예제 출력 3 
<ab cd>fe hg<ij kl>

### 예제 입력 4 
one1 two2 three3 4fourr 5five 6six

### 예제 출력 4 
1eno 2owt 3eerht rruof4 evif5 xis6

### 예제 입력 5 
<int><max>2147483647<long long><max>9223372036854775807

### 예제 출력 5 
<int><max>7463847412<long long><max>7085774586302733229

### 예제 입력 6 
<problem>17413<is hardest>problem ever<end>

### 예제 출력 6 
<problem>31471<is hardest>melborp reve<end>

### 예제 입력 7 
<   space   >space space space<    spa   c e>

### 예제 출력 7 
<   space   >ecaps ecaps ecaps<    spa   c e>


### 코드 설명
```cpp
#include<iostream>
#include<string>
#include<stack>

using namespace std;

void sprint(stack<char>& s) // 스택이 비워질 때까지 출력하는 함수
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	string str; // 입력 문자열
	stack<char> s;

	getline(cin, str);
	bool tag = false; // 태그 내부인지 검사

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<') // '<'를 만나고 스택이 비어있지 않다면 스택을 모두 출력
		{
			sprint(s);
			cout << str[i];
			tag = true; // 태그 내부 판단
		}
		else if (str[i] == '>')
		{
			cout << str[i];
			tag = false;
		}
		else if(tag)
		{
			cout << str[i]; // 태그 내부인 경우 그대로 출력
		}
		else
		{
			if (str[i] == ' ') // 공백을 만난 경우 스택을 비움
			{
				sprint(s);
				cout << str[i]; // 공백 출력
			}
			else
				s.push(str[i]); // 아니라면 스택에 push
		}

	}
	sprint(s); // 스택이 남아있다면 모두 출력
	cout << '\n';

	return 0;
}
```
