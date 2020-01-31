#include<iostream>
#include<vector>
// LIS 문제
using namespace std;
void go(int);
int a[1001];
int v[1001]; // 역추적을 위한 배열
int d[1001]; // d[i] = a[1], ... a[i] 까지 있을 때, a[i]를 가장 마지막으로 하는 LIS의 길이

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // 수열의 크기
	cin >> n;
	for (int i = 1; i <= n; i++) // 수열 입력
		cin >> a[i];

	int p = 1; // 역추적을 시작할 인덱스
	int max = 1;
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1; // 모든 d[i]의 초기값은 1
		v[i] = -1; // 초기값은 -1
		for (int j = 1; j < i; j++)
		{										// 수열의 마지막 항이 더 크면서
			if (d[i] < d[j] + 1 && a[i] > a[j]) // i보다 작은 LIS중에서 가장 긴 LIS에 1을 더하면 d[i]
			{
				d[i] = d[j] + 1;
				v[i] = j; // 연결되는 인덱스를 저장 / 즉, d의 값이 어느 인덱스에 의해 변하는지 저장
			}
		}
		if (max < d[i]) // 모든 d[i] 중 최댓값이 정답
		{
			max = d[i];
			p = i; // 최댓값을 가지는 인덱스에서 역추적 시작
		}
	}
	cout << max << '\n';
	go(p);
	cout << '\n';
}

void go(int p) // 역추적 함수
{
	if (p == -1)
		return;
	go(v[p]);
	cout << a[p] << ' '; // 역순으로 a값 출력
}