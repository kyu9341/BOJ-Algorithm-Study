#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
const int MAX = 1000 + 1;
int n, l;
int a[MAX][3];

int main(void) {
	cin >> n >> l;
	for (int i = 0; i < n; i++) 
		cin >> a[i][0] >> a[i][1] >> a[i][2]; // d, r, g �Է�

	int sec = 0;
	int dist = 0;
	int i = 0;
	while (true) {
		if (dist == a[i][0]) { // ���� ��ġ�� ��ȣ���� �ִ��� Ȯ��
			int tmp = sec % (a[i][1] + a[i][2]); // ���� ��ȣ ����Ŭ Ȯ��
			if (tmp <= a[i][1]) { // �������� ���
				sec += a[i][1] - tmp; // ���ð� �߰�
			}
			i++;
		}
		sec++;
		dist++;
		if (dist == l) {
			break;
		}
	}

	cout << sec << '\n';

}