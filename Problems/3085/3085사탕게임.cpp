#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int check(vector<string>& v) // ���� �� ������ ���� �κ��� ����
{
	int n = v.size();
	int ans = 1;
	// ���� ���� �κ��� üũ
	for (int i = 0; i < n; i++)
	{
		int cnt = 1; // �ʱⰪ
		for (int j = 1; j < n; j++)
		{
			if (v[i][j] == v[i][j - 1])
				cnt++;
			else
				cnt = 1;
			if (ans < cnt) // �񱳸� �ݺ��� �ȿ��� �����ؾ� ��
				ans = cnt;
		}
		cnt = 1;
		// ���� ���� �κ� üũ
		for (int j = 1; j < n; j++)
		{
			if (v[j][i] == v[j - 1][i])
				cnt++;
			else
				cnt = 1;
			if (ans < cnt) 
				ans = cnt;
		}
	}
	return ans;
}

int main(void)
{
	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ans = check(v);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	// ���η� �ٲپ� ���� �ִ��� ���Ѵ�.
			if (j + 1 < n) // ���� ������ ���� �ʴ� �ѿ���
			{
				swap(v[i][j], v[i][j + 1]); // ������ �ִ� ���� ��ȯ
				int temp = check(v);
				swap(v[i][j], v[i][j + 1]); // �ٽ� �ǵ��� ���´�.
				if (ans < temp)
					ans = temp;
			}
			// ���η� �ٲپ� ���� �ִ��� ���Ѵ�.
			if (i + 1 < n) // ���� ������ ���� �ʴ� �ѿ���
			{
				swap(v[i][j], v[i + 1][j]);
				int temp = check(v);
				swap(v[i][j], v[i + 1][j]);
				if (ans < temp)
					ans = temp;
			}
		}

	}

	cout << ans << '\n';

}