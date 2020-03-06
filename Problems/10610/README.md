# Problem 10610

## 30

### 문제
어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 미르코는 30이란 수를 존경하기 때문에, 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.

미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

### 입력
N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.

### 출력
미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.

### 문제 링크
<https://www.acmicpc.net/problem/10610>

### 예제 입력 1
30

### 예제 출력 1
30

### 예제 입력 2
102

### 예제 출력 2
210

### 예제 입력 3
2931

### 예제 출력 3
-1

### solve
- 문자열로 입력받아 문자열을 내림차순으로 정렬한다.
- 최댓값을 구해야 하므로 내림차순으로 정렬된 문자열의 이전 순열을 찾아 30의 배수가 나오면 종료한다.
- 30의 배수가 나오지 않는 경우 -1 을 출력한다.
- 위와 같이 하니 런타임 에러가 난다. 다시 생각해보니 n이 너무 커서 정수로 변환이 안된다.

- 정수로 변환하여 30의 배수인지 확인할 수 없으니 30 = 2 * 5 * 3 이므로
	- 30의 배수의 마지막 수는 항상 0이 될 것이고, 3의 배수이다. 3의 배수라는 것은 각 자릿수를 모두 더한 값이 3의 배수이다.
	- 이 조건을 활용하여 먼저 오름차순 정렬 후 첫 번째 인덱스의 수가 0이고, 각 자릿수의 합이 3으로 나누어 떨어진다면, 정렬된 수를 뒤집어 출력한다.
	- 아니라면 -1을 출력한다.


### 코드 설명
- 런타임 에러
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{
	string num;
	cin >> num;

	sort(num.begin(), num.end(), [](int a, int b) { // 내림차순 정렬
		return a > b;
		});

	do
	{
		int tmp = stoi(num); // 정수로 변환
		if (tmp % 30 == 0) // 30의 배수이면
		{
			cout << tmp << '\n'; // 출력 후 종료
			exit(0);
		}
		// 가장 먼저 나오는 30의 배수가 최대
	} while (prev_permutation(num.begin(), num.end())); // 이전 순열

	cout << -1 << '\n'; // 30의 배수가 없는 경우
}

```
- 정답 코드
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string num;
	cin >> num;

	int sum = 0;
	for (int i = 0; i < num.size(); i++)
		sum += num[i] - '0'; // 각 자릿수의 합을 구함

	sort(num.begin(), num.end());
	// 30의 배수이려면 마지막 수가 0이고, 각 자릿수의 합이 3의 배수여야 한다.
	if (num[0] == '0' && sum % 3 == 0) // 정렬한 첫 수가 0이면 마지막 수가 0이 될 수 있음
	{
		reverse(num.begin(), num.end());
		cout << num << '\n';
	}
	else
	{
		cout << -1 << '\n'; // 30의 배수가 없는 경우
	}


}
```
