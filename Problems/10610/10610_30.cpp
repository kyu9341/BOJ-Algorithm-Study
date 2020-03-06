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