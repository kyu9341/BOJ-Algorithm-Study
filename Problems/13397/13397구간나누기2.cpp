#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
int n, m;

int gapMaxMin(vector<int>& k)
{
	auto p = minmax_element(k.begin(), k.end());
	return *p.second - *p.first;
}

bool calc(vector<int>& a, int mid)
{
	vector<int> tmp;
	int cnt = 1; // ������ ����(������ ���� + 1)
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(a[i]);
		int gap = gapMaxMin(tmp); // ���� ������ �ִ�
		if (gap > mid) // ���� ���� �������� ū ���
		{ 
			cnt++; // ���� �� + 1
			tmp.clear(); // ���� �ʱ�ȭ
			tmp.push_back(a[i]);
		}
	}
	return cnt <= m; // m�� ������ �������� ���� �� �ִ���
}

int main(void)
{
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int right = *max_element(a.begin(), a.end()); // �迭�� �ִ�
	int left = 0; 
	int ans = right;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		if (calc(a, mid)) // ������ ��� 
		{
			if(ans > mid)
				ans = mid;
			right = mid - 1; // ������ �ּڰ� Ȯ��
		}
		else
			left = mid + 1;

	}
	cout << ans << '\n';
}