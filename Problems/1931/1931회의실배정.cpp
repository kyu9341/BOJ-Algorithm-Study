#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
struct Meeting
{
	int begin, end;
};
bool compare(Meeting u, Meeting v) // �� �Լ�
{
	if (u.end == v.end) return u.begin < v.begin; // ������ �ð��� ���ٸ� ���� �ð���
	else return u.end < v.end; // ������ �ð��� ���� ������ ����
}

int main(void)
{
	int n;
	cin >> n;
	vector<Meeting> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].begin >> a[i].end;
	}
	sort(a.begin(), a.end(), compare); // ȸ�ǰ� ������ �ð��� ���� ������ ����

	int now = 0; // ȸ�ǰ� ���� �ð�
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (now <= a[i].begin) // ���� ȸ�ǰ� ���� �ð��� ���� ȸ�� ���� �ð� ��
		{
			now = a[i].end; // ȸ�� ���� �ð� ����
			ans++; 
		}
	}
	cout << ans << '\n';
}