#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int height[9];
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> height[i];
		sum += height[i]; // 먼저 모든 난쟁이의 키를 더한다.
	}

	sort(height, height + 9); // 오름차순으로 출력하기 때문에 먼저 정렬
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - height[i] - height[j] == 100) // 9가지중 2가지를 골라 위에서 sum에서 빼서 100이 나오는지 확인
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j) continue; // 뺀 난쟁이는 출력안함
					cout << height[k] << '\n';
				} 
				return 0; // 출력 후 프로그램 종료
			}

		}
	}

	
}