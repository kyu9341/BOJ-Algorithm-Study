# Problem 1373

## 2진수 8진수

### 문제
2진수가 주어졌을 때, 8진수로 변환하는 프로그램을 작성하시오.

### 입력
첫째 줄에 2진수가 주어진다. 주어지는 수의 길이는 1,000,000을 넘지 않는다.

### 출력
첫째 줄에 주어진 수를 8진수로 변환하여 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1373>

### 예제 입력 1
11001100

### 예제 출력 1
314

### solve
- 2진수의 숫자를 뒤에서부터 3자리씩 묶는다.
- 3자리로 묶은 숫자에 2진수의 자리값을 곱한다.
- 곱한 값을 더하면 8진수 한 자리가 된다.
- <https://m.blog.naver.com/javrin4/220956809081>

### 코드 설명
처음 아래와 같은 코드로 돌려보니 시간초과가 난다.
```C++
#include<iostream>
#include<string>

using namespace std;

int pow(int a, int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
		result \*= a;
	return result;
}

int main(void)
{
	string n;
	getline(cin, n);

	int eight = 0; // 3자리씩 묶음의 합
	int size = n.size();
	int result = 0, set = 0; // result : 결과, set : 3자리씩 반복 횟수
	while(size > -2)
	{
		for (int i = size - 1, j = 0; j < 3; i--, j++) // 3자리씩 끊어 계산
		{
			if (i < 0)
				eight += 0;
			else
				eight += pow(2, j) * ((int)n[i] - '0');
		}
		result += eight * pow(10, set);
		eight = 0;
		size -= 3;
		set++;
	}
	cout << result << '\n';
}

```

아래는 정답 코드이다. 반복 연산을 최소화 하여 시간복잡도를 줄였다.
```C++
#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string n;
	cin >> n;
	int size = n.size();
	if (size % 3 == 1) { // 3으로 나눈 나머지가 1이면 3개씩 묶어 계산 후 1자리가 남음
		cout << n[0]; // 1자리가 남는다는 것은 1이 남는다는 것이므로 맨 앞에 1출력
	}
	else if (size % 3 == 2) { // 3개씩 묶어 계산 후 2자리가 남음
		cout << (n[0] - '0') * 2 + (n[1] - '0'); // 남는 2자리 계산하여 맨 앞에 출력
	}
	for (int i = size % 3; i < size; i += 3) { // 나머지가 남는 경우 처리한 부분 외 3개씩 묶어서 처리
		cout << (n[i] - '0') * 4 + (n[i + 1] - '0') * 2 + (n[i + 2] - '0');
	}
	cout << '\n';
}
```
