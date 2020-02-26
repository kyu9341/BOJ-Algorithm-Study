# Problem 1541

## 잃어버린 괄호

### 문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 길이가 최대 50인 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

### 입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.

### 출력
첫째 줄에 답을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1541>

### 예제 입력 1
55-50+40

### 예제 출력 1
-35

### solve
- 먼저 숫자와 연산자를 나누어 벡터에 저장한다.
- '-'가 나오는 경우 그 뒤에 이어지는 '+'들을 모두 묶어야 최솟값을 구할 수 있다.
	- 앞에 '-'가 있다면 그 뒤에 나오는 '+'를 모두 누적하여 빼준다.
- 쓸데없이 복잡하게 구현했는데 생각해보니 그냥 첫 번째로 나오는 '-'이후의 모든 값을 누적하여 빼버리면 그만이었는데 멍청했다.


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);
	vector<int> iv;
	vector<char> cv;

	bool isnum = false;
	int tmp = 0;
	for (int i = 0; i < str.size(); i++) // 숫자와 연산자를 나누어 벡터에 저장
	{
		if (str[i] >= '0' && str[i] <= '9') // 숫자인 경우
		{
			if (isnum)
				tmp * = 10;
			tmp += int(str[i] - '0');
			isnum = true; // 이전 인덱스가 숫자임을 저장
		}
		else // 연산자인 경우
		{
			if (isnum) iv.push_back(tmp); // 이전 인덱스가 숫자라면
			isnum = false;
			tmp = 0; // 숫자를 누적하던 변수 초기화
			cv.push_back(str[i]);
		}
		if(i == str.size() - 1) iv.push_back(tmp); // 마지막 숫자 추가
	}

	int ans = iv[0]; // 맨 앞 숫자로 초기화
	bool minus = false; // - 이후 나오는 +는 모두 괄호에 묶기 위해 판별
	int mtmp = 0; // -( ) 에 묶이는 누적 값

	for (int i = 0; i < cv.size(); i++)
	{
		if (cv[i] == '-') // -인 경우
		{
			if (minus) // - 괄호에 묶이던 중 -가 나온 경우
			{
				ans -= mtmp; // 앞에 묶인 값 처리
				mtmp = 0;
			}
			mtmp += iv[i + 1]; // - () 누적
			minus = true;
		}
		else // + 인 경우
		{
			if (!minus) // -에 묶이는 +가 아니면
				ans += iv[i + 1]; // 바로 더해줌
			else
			{
				mtmp += iv[i + 1]; // -에 묶이는 경우 누적
			}
		}
	}
	ans -= mtmp; // 마지막에 남는 - () 묶음 처리
	cout << ans << '\n';
}

```
