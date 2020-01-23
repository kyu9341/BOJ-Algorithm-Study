# Problem 1935

## 후위 표기식 2

### 문제
후위 표기식과 각 피연산자에 대응하는 값들이 주어져 있을 때, 그 식을 계산하는 프로그램을 작성하시오.

### 입력
첫째 줄에 피연산자의 개수(1 ≤ N ≤ 26) 가 주어진다. 그리고 둘째 줄에는 후위 표기식이 주어진다. (여기서 피연산자는 A~Z의 영대문자이며, A부터 순서대로 N개의 영대문자만이 사용되며, 길이는 100을 넘지 않는다) 그리고 셋째 줄부터 N+2번째 줄까지는 각 피연산자에 대응하는 값이 주어진다. (3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B에 해당하는값 , 5번째 줄에는 C ...이 주어진다, 그리고 피연산자에 대응 하는 값은 정수이다)

### 출력
계산 결과를 소숫점 둘째 자리까지 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1935>

### 예제 입력 1
5
ABC*+DE/-
1
2
3
4
5

### 예제 출력 1
6.20

### 예제 입력 2
1
AA+A+
1

### 예제 출력 2
3.00

### solve
- 문자열의 현재 인덱스가 피연산자(영어 대문자)라면 해당 숫자로 변환하여 스택에 push한다.
- 연산자인 경우 스택의 가장 위의 두 수를 뽑아 순서를 뒤집어(아래의 숫자가 더 먼저 들어간 수 이므로) 연산 후 다시 push 한다.
- 위 과정을 반복 후 스택의 top원소를 소수점 둘째 자리까지만 표기하여 출력

### C++ 소수점 조정

- "cout << fixed"라는 표현은 소숫점 아래 값을 고정하는 표현이다.
- 즉, cout << fixed 이후에 precision(6)을 입력하면 소숫점 아래를 6으로 고정한다.
- precision() -> 자릿수를 조정하는 함수이다.


### 코드 설명
아래의 코드는 자꾸 틀리다고 나오는데 아직 뭐가 틀린지는 잘 모르겠다.
```C++
#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;
double cal(double a, double b, char op);

int main()
{
	string str; // 입력 문자열
	int n; // 피연산자 수
	stack<double> s; // 피연산자를 담을 스택
	double alphabet[26]; // 피연산자에 해당하는 숫자를 저장할 배열

	cin >> n;
	cin.ignore();
	getline(cin, str);

	for (int i = 0; i < n; i++)
		cin >> alphabet[i];

	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') // 피연산자일 경우 숫자로 변환하여 스택에 push
		{
			s.push(alphabet[str[i] - 'A']);
		}
		else // 연산자인 경우 스택의 위의 두 수를 뽑아 순서를 뒤집어 연산 후 다시 push
		{
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();
			s.push(cal(a, b, str[i]));
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top() << '\n';

	return 0;
}

double cal(double a, double b, char op)
{
	double res = 0.;
	switch (op)
	{
	case '+':
		res = b + a;
		break;
	case '-':
		res = b - a;
		break;
	case '\*':
		res = b * a;
		break;
	case '/':
		res = b / a;
		break;
	}
	return res;
}
```
