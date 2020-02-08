#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void next_permutation(vector<int> &a, int n)
{
	int i = n - 1; // �迭�� ������ �ε���
	while (i >  0 && a[i] <= a[i - 1]) i--; // ���������� �Ǳ� ������ �ε����� i�� ��.
	if (i == 0)
	{
		cout << -1; // ������ ������ ��� -1
		return;
	}
	int j = n - 1;
	while (a[j] <= a[i - 1]) j--; // a[i] ���� ū ���� ������ a[j]�� ã�´�
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) // i �ڸ� ������������ ����
	{
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}

	for (int k = 0; k < n; k++)
		cout << a[k] << ' ';
	cout << '\n';
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	next_permutation(a, n);
}