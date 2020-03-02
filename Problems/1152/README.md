# Problem 1152

## 단어의 개수

### 문제
영어 대소문자와 띄어쓰기만으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.

### 입력
첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 띄어쓰기 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다. 또한 문자열의 앞과 뒤에는 공백이 있을 수도 있다.

### 출력
첫째 줄에 단어의 개수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1152>

### 예제 입력 1
The Curious Case of Benjamin Button

### 예제 출력 1
6

### 예제 입력 2
 Mazatneunde Wae Teullyeoyo

### 예제 출력 2
3

### 예제 입력 3
Teullinika Teullyeotzi

### 예제 출력 3
2

### solve
- 단어의 맨 앞 또는 맨 뒤에도 공백이 올 수 있으므로 맨 앞 또는 맨 뒤 공백이면 건너뛰고
- 나머지 경우에 공백을 카운트한다.
- 공백만 입력되는 경우 예외처리를 해주고
- 맨 앞, 맨 뒤가 아닌 공백의 수 + 1이 단어의 개수가 된다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);

	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			if (i == 0 || i == str.size() - 1) // 맨 앞 또는 맨 뒤 공백이면 건너뜀
				continue;
			else
				ans++;
		}
	}
	if (str == " ") // 공백만 입력되는 경우 예외처리
		cout << 0 << '\n';
	else
		cout << ans + 1 << '\n'; // 맨 앞, 맨 뒤가 아닌 공백의 수 + 1이 단어의 개수
}

```
