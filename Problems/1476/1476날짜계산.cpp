#include<iostream>

using namespace std;

int main(void)
{
	int e, s, m;
	cin >> e >> s >> m;

	int E, S, M;
	E = S = M = 1; // 1�� �������� �� ����

	int year = 1; // �츮 ����
	while (true)
	{
		if (E == e && S == s && M == m) // ��ġ�ϴ� ���� ���� �⵵�� ��
			break;
		E++;
		S++;
		M++;
		if (E > 15) // 15������ �ʱ�ȭ 1
			E = 1;
		if (S > 28) // 28������ �ʱ�ȭ 1
			S = 1;
		if (M > 19) // 19������ �ʱ�ȭ 1
			M = 1;
		year++;

	}
	cout << year << '\n';
}
