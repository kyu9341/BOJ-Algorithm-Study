#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;
int n;
int a, b;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int round = 0;

	cin >> n >> a >> b;

	if (n < a || n < b) {
		round = -1;
		cout << round << '\n';
		return 0;
	}

	while (a != b) {
		a = a / 2 + a % 2; // ��ʸ�Ʈ�� �������� ��ȣ�� ����
		b = b / 2 + b % 2;
		round++; // ���� ����
	}

	cout << round << '\n';

}