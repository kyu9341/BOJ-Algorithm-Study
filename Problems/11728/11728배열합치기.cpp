#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 1000000;
int a[MAX];
int b[MAX];
int res[MAX * 2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int idx_res = 0; // res�� �ε���
	int idx_a = 0, idx_b = 0; // a�� b�� �ε���

	while (idx_a < n && idx_b < m) // a�� b �� �ϳ��� ��� Ȯ���ߴٸ� ���´�.
	{
		if (a[idx_a] < b[idx_b]) // a�� b�� ���� �� ���� ���� ���� res�� ����
			res[idx_res++] = a[idx_a++];
		else
			res[idx_res++] = b[idx_b++];
	}
	
	while (idx_a < n) // ���� a�� b�� ��� ���Ҹ� Ȯ������ ���� �迭�� ������ ���Ҹ� �״�� res�� ����
		res[idx_res++] = a[idx_a++]; // �̹� ���ĵ� a, b�̹Ƿ�
	while (idx_b < m)
		res[idx_res++] = b[idx_b++];

	for (int i = 0; i < idx_res; i++)
		cout << res[i] << ' ';
	cout << '\n';

}