# Problem 1918

## 후위 표기식

### 문제

수식은 일반적으로 3가지 표기법으로 표현할 수 있다. 연산자가 피연산자 가운데 위치하는 중위 표기법(일반적으로 우리가 쓰는 방법이다), 연산자가 피연산자 앞에 위치하는 전위 표기법(prefix notation), 연산자가 피연산자 뒤에 위치하는 후위 표기법(postfix notation)이 그것이다. 예를 들어 중위 표기법으로 표현된 a+b는 전위 표기법으로는 +ab이고, 후위 표기법으로는 ab+가 된다.

이 문제에서 우리가 다룰 표기법은 후위 표기법이다. 후위 표기법은 위에서 말한 법과 같이 연산자가 피연산자 뒤에 위치하는 방법이다. 이 방법의 장점은 다음과 같다. 우리가 흔히 쓰는 중위 표기식 같은 경우에는 덧셈과 곱셈의 우선순위에 차이가 있어 왼쪽부터 차례로 계산할 수 없지만 후위 표기식을 사용하면 순서를 적절히 조절하여 순서를 정해줄 수 있다. 또한 같은 방법으로 괄호 등도 필요 없게 된다. 예를 들어 a+b*c를 후위 표기식으로 바꾸면 abc*+가 된다.

중위 표기식을 후위 표기식으로 바꾸는 방법을 간단히 설명하면 이렇다. 우선 주어진 중위 표기식을 연산자의 우선순위에 따라 괄호로 묶어준다. 그런 다음에 괄호 안의 연산자를 괄호의 오른쪽으로 옮겨주면 된다.

예를 들어 a+b*c는 (a+(b*c))의 식과 같게 된다. 그 다음에 안에 있는 괄호의 연산자 \*를 괄호 밖으로 꺼내게 되면 (a+bc*)가 된다. 마지막으로 또 +를 괄호의 오른쪽으로 고치면 abc*+가 되게 된다.

다른 예를 들어 그림으로 표현하면 A+B*C-D/E를 완전하게 괄호로 묶고 연산자를 이동시킬 장소를 표시하면 다음과 같이 된다.

이러한 사실을 알고 중위 표기식이 주어졌을 때 후위 표기식으로 고치는 프로그램을 작성하시오

### 입력
첫째 줄에 중위 표기식이 주어진다. 단 이 수식의 피연산자는 A~Z의 문자로 이루어지며 수식에서 한 번씩만 등장한다. 그리고 -A+B와 같이 -가 가장 앞에 오거나 AB와 같이 \*가 생략되는 등의 수식은 주어지지 않는다. 표기식은 알파벳 대문자와 +, -, \*, /, (, )로만 이루어져 있으며, 길이는 100을 넘지 않는다.

### 출력
첫째 줄에 후위 표기식으로 바뀐 식을 출력하시오


### 문제 링크
<https://www.acmicpc.net/problem/1918>

### 예제 입력 1
A*(B+C)

### 예제 출력 1
ABC+*

### solve
- 문자열의 현재 인덱스가 피연산자(영어 대문자)라면 바로 결과 문자열에 추가한다.
- 연산자이며 스택이 비어있을 경우에는 스택에 연산자를 추가하고
- 스택의 top원소와 현재 연산자와 비교하여 우선순위가 현재 연산자가 더 높다면 스택에 넣는다.
- top원소의 우선순위가 더 높다면 스택이 비워질 때까지 연산자를 출력하고 현재 원소를 스택에 push한다.
- '('연산자라면 바로 push
-  ')'연산자가 현재 연산자라면 '('가 나올 때까지 pop하여 출력 문자열에 추가


##### 션팅 야드 알고리즘 (차량기지 알고리즘)
- 중위 표기법으로 표현된 식을 후위 표기법으로 바꾸는 알고리즘이다.
- 연산자의 우선순위가 스택의 가장 위에 있는 연산자의 우선순위보다 작거나 같은 동안
- 스택에 있는 연산자를 결과에 추가한다
- 괄호가 있는 식의 경우에는
- 여는 괄호는 연산자 스택에 넣고
- 닫는 괄호가 나오면 여는 괄호가 나올 때까지 연산자 스택에서 계속해서 연산자를 꺼낸다

### 코드 설명
아래의 코드는 자꾸 틀리다고 나오는데 아직 뭐가 틀린지는 잘 모르겠다.
```C++

#include<iostream>
#include<stack>
#include<string>
#include<map>

using namespace std;

int main()
{
	string str;
	string res;
	stack<char> s;
	map<char, int> m; // 연산자의 우선순위를 정할 map
	m.insert(make_pair('+', 1));
	m.insert(make_pair('-', 1));
	m.insert(make_pair('*', 2));
	m.insert(make_pair('/', 2));
	m.insert(make_pair('(', 0));
	m.insert(make_pair(')', 0));
	cin >> str;

	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') // 영어 대문자(피연산자)인 경우 바로 출력
			res += str[i];
		else if (s.empty() || str[i] == '(') // 스택이 비었거나 '('를 만나면 push
		{
			s.push(str[i]);
		}
		else if (str[i] == ')') // ')'가 나왔다면 '('가 나올 때까지 pop하여 출력문자열에 추가
		{
			while (!s.empty() && s.top() != '(')
			{
				res += s.top();
				s.pop();
			}
			if(!s.empty()) s.pop(); // '(' 제거
		}
		else if (m[str[i]] > m[s.top()]) // 현재 연산자가 스택의 top원소보다 우선순위가 높다면 push
		{
			s.push(str[i]);
		}
		else if (m[str[i]] <= m[s.top()]) // 현재 연산자가 s.top보다 우선순위가 높지않다면 스택의 연산자 모두 꺼내어 출력하고 현재 연산자 push
		{
			while (!s.empty() && s.top() != '(')
			{
				res += s.top();
				s.pop();
			}
			s.push(str[i]);

		}

	}
	while (!s.empty()) // 스택에 남은 연산자 출력
	{
		res += s.top();
		s.pop();
	}

	cout << res << '\n';


	return 0;
}
```

아래의 코드는 정답처리가 되는 코드이다. switch case문을 이용하였고 map을 사용하지 않았다.

```C++
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;
	stack<char> s;
	string result; // 결과 문자열

	for (int i = 0; i < str.length(); i++) {

		if (str[i] >= 'A' && str[i] <= 'Z') {
			result += str[i];
		}
		else {
			switch (str[i]) {
			case '(':
				s.push(str[i]);
				break;
				// 사칙연산자를 만난 경우 스택에 현재 연산자보다 우선순위가 높거나 같은 기호는 result에 추가
			case '+':
			case '-':
				// +, - 연산자를 만난 경우, 스택에 뭐가 있던 ( 를 제외하고 전부 우선순위가 높거나 같으니 result에 추가
				while (!s.empty() && s.top() != '(') {
					result += s.top();
					s.pop();
				}
				// 스택이 비었거나 ( 이므로 연산자를 스택에 push
				s.push(str[i]);
				break;
			case '*':
			case '/':
				// *, / 연산자를 만난 경우, 스택에 뭐가 있는데 그게 *, /이면 우선 순위가 같으므로 result에 추가
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					result += s.top();
					s.pop();
				}
				// 스택이 비었거나 우선순위가 더 낮은 +, - 이므로 연산자를 스택에 push
				s.push(str[i]);
				break;
			case ')':
				// ) 를 만나면 ( 까지 result에 추가
				while (s.top() != '(') {
					result += s.top();
					s.pop();
				}
				s.pop(); // 괄호 안의 내용을 다 result에 추가했으면 ( 도 pop해서 날려준다.
				break;
			}
		}
	}
	while (!s.empty()) {
		result += s.top();
		s.pop();
	}
	cout << result << "\n";
}

```
