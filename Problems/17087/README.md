# Problem 17087

## 숨박꼭질 6

### 문제
수빈이는 동생 N명과 숨바꼭질을 하고 있다. 수빈이는 현재 점 S에 있고, 동생은 A1, A2, ..., AN에 있다.

수빈이는 걸어서 이동을 할 수 있다. 수빈이의 위치가 X일때 걷는다면 1초 후에 X+D나 X-D로 이동할 수 있다. 수빈이의 위치가 동생이 있는 위치와 같으면, 동생을 찾았다고 한다.

모든 동생을 찾기위해 D의 값을 정하려고 한다. 가능한 D의 최댓값을 구해보자.

### 입력
첫째 줄에 N(1 ≤ N ≤ 105)과 S(1 ≤ S ≤ 109)가 주어진다. 둘째 줄에 동생의 위치 Ai(1 ≤ Ai ≤ 109)가 주어진다. 동생의 위치는 모두 다르며, 수빈이의 위치와 같지 않다.

### 출력
가능한 D값의 최댓값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/17087>

### 예제 입력 1
3 3
1 7 11

### 예제 출력 1
2

### 예제 입력 2
3 81
33 105 57

### 예제 출력 2
24

### 예제 입력 3
1 1
1000000000

### 예제 출력 3
999999999


### solve
- 수빈이의 위치와 동생의 위치를 모두 하나의 벡터에 오름차순으로 담는다.
- 이후 벡터의 인덱스를 i라고 하면 모든 v[i+1] - v[i] 의 최대공약수를 구한다.


### 코드 설명
```C++

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b) // 유클리드 호제법 (최대공약수)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, s; // n : 동생 수, s : 수빈이의 위치
	cin >> n >> s;
	vector<long long> v(n); // 수빈이의 위치와 동생의 위치를 담을 벡터
	for (long long i = 0; i < n; i++)
		cin >> v[i];
	v.push_back(s); // 수빈이의 위치 추가

	sort(v.begin(), v.end()); // 오름차순 정렬

	long long res = v[1] - v[0]; // 초기값 설정

	for (long long i = 1, j = i + 1; j < v.size(); i++, j++)
	{
		res = gcd(res, v[j] - v[i]); // 다음 원소와의 차이의 최대공약수(모든 차이 값의 최대공약수)
	}

	cout << res << '\n';
}

```
