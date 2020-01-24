#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// 팩토리얼의 0의 개수는 n!을 소인수분해하여 나온 2와 5의 개수로 얻을 수 있다.
	// n!에서는 2의 개수가 항상 5의 개수보다 많으므로 5의 개수만 세어준다.
	int n;
	cin >> n;
	int count = 0;
	
	for (int i = n; i > 0; i--)
	{
		int tmp = i;
		while (tmp % 5 == 0) // 5의 개수 count
		{
			tmp /= 5; // 5를 하나 이상 인자로 가지는 수 처리
			count++;
		}
	}
	cout << count << '\n';
}