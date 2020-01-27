#include<iostream>

using namespace std;
const int MAX = 1000000;
int prime[MAX]; // 소수를 담을 배열
bool check[MAX + 1]; // 인덱스가 소수이면 false인 배열
int pn = 0; // 소수의 개수
int main(void)
{
	int n; // testcase
	cin >> n;
	check[1] = true; // 1은 소수가 아님

	for (int i = 2; i < MAX; i++) // 에라토스테네스의 체
	{
		if (check[i] == false) // 아직 (소수가 아니라고)판별되지 않았다면
		{
			prime[pn++] = i; // 소수이면 prime에 저장
			for (int j = i + i; j < MAX; j += i) // i*i로 하면 정수 범위를 벗어날 수 있음 
			{
				check[j] = true; // 소수의 배수는 모두 제거
			}
		}
	}

	while (n--)
	{
		int num;
		cin >> num;

		int count = 0; // 파티션 수
		for (int i = 0; prime[i] < num; i++) // 소수가 현재 입력 수 보다 작은동안
		{
			if (!check[num - prime[i]]) // n - b = a(소수)라면
			{
				// cout << num << " = " << num - prime[i] << " + " << prime[i] << '\n';
				count++;
			}
		}
		if (!check[num / 2]) // num / 2 가 소수라면 - 즉, 6 = 3 + 3 과 같이 중복이 발생하지 않는 파티션이 존재하는 경우
			cout << count / 2 + 1 << '\n'; // 중복을 제거하고 1을 더함
		else
			cout << count / 2 << '\n'; // 중복 제거
		
	}
}