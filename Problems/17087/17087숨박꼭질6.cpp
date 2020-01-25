#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long gcd(long long a, long long b) // ��Ŭ���� ȣ���� (�ִ�����)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, s; // n : ���� ��, s : �������� ��ġ
	cin >> n >> s;
	vector<long long> v(n); // �������� ��ġ�� ������ ��ġ�� ���� ����
	for (long long i = 0; i < n; i++)
		cin >> v[i];
	v.push_back(s); // �������� ��ġ �߰�

	sort(v.begin(), v.end()); // �������� ����

	long long res = v[1] - v[0]; // �ʱⰪ ����

	for (long long i = 1, j = i + 1; j < v.size(); i++, j++)
	{
		res = gcd(res, v[j] - v[i]); // ���� ���ҿ��� ������ �ִ�����(��� ���� ���� �ִ�����)
	}
		
	cout << res << '\n';
}