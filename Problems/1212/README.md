# Problem 1373

## 8진수 2진수

### 문제
8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.

### 입력
첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 넘지 않는다.

### 출력
첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.

### 문제 링크
<https://www.acmicpc.net/problem/1212>

### 예제 입력 1
314

### 예제 출력 1
11001100

### solve
- 8진수 1자리 입력 시 2진수 3자리로 변환될 문자열 배열 정의
- 8진수 첫 번째 수가 4보다 작은 경우 2자리 이하이며 맨 앞에 0은 출력하지 않으므로
- 첫 번째 입력을 판별하여 따로 처리
	- 이때, 8진수 첫 자리가 0이 입력되면 다른 수가 나올때까지 무시
- 첫 번째 입력이 아니라면 위에서 정의해둔 2진수 3자리로 변환하여 출력
- <https://m.blog.naver.com/javrin4/220956809081>

### 코드 설명
```C++
#include<iostream>
#include<string>

using namespace std;
string eight[8] = { "000", "001", "010", "011", "100", "101", "110", "111" }; // 8진수 0~7 의 각가 출력될 2진수

int main(void)
{
	string n;
	cin >> n;

	int size = n.size();
	bool start = true; // 첫 번째 수 인지 판별

	if (n[0] - '0' == 0 && size == 1) // 입력이 0 인경우 0출력 후 종료
	{
		cout << "0";
		return 0;
	}

	for (int i = 0; i < size; i++)
	{
		int position = n[i] - '0'; // 현재 자리의 8진수
		if (start == true && position < 4) // 첫 번째 수 && 4보다 작은 (2진수)2자리인 경우 처리
		{
			if (position == 0) // 맨 앞에 0이 입력된 경우 무시
				continue;
			else if (position == 1)
				cout << "1";
			else if (position == 2)
				cout << "10";
			else if (position == 3)
				cout << "11";
			start = false;
		}
		else
		{
			cout << eight[position];
			start = false;
		}

	}
	cout << '\n';
}
```
