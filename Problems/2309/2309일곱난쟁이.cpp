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
		sum += height[i]; // ���� ��� �������� Ű�� ���Ѵ�.
	}

	sort(height, height + 9); // ������������ ����ϱ� ������ ���� ����
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - height[i] - height[j] == 100) // 9������ 2������ ��� ������ sum���� ���� 100�� �������� Ȯ��
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j) continue; // �� �����̴� ��¾���
					cout << height[k] << '\n';
				} 
				return 0; // ��� �� ���α׷� ����
			}

		}
	}

	
}