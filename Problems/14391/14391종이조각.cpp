#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
int n, m; // ����, ����
int a[4][4];
bool check[4][4]; 
int xy[4][4]; // 0 : ���η� ��, 1 : ���η� ��
vector<int> ans;

int dfs(int x, int y, int sum) // ���� ��ġ���� ����� ���� �Ǵ� ������ ���� ����
{
	check[x][y] = true;
	if (xy[x][y] == 0) // ���η� Ȯ���ϴ� ���
	{
		if (y + 1 < m && xy[x][y] == xy[x][y + 1] && !check[x][y + 1])
			sum = dfs(x, y + 1, (sum * 10) + a[x][y]); // ���η� ���̸� �̾�ٿ� �ѱ�
		else
			return sum * 10 + a[x][y]; // ������ �� ó��
	}
	if (xy[x][y] == 1) // ���η� Ȯ���ϴ� ���
	{
		if (x + 1 < n && xy[x][y] == xy[x + 1][y]  && !check[x + 1][y])
			sum = dfs(x + 1, y, (sum * 10) + a[x][y]); // ���η� ���̸� �̾�ٿ� �ѱ�
		else
			return sum * 10 + a[x][y]; // ������ �� ó��
	}
	return sum;
}

int makeSum()
{
	int sum = 0;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (!check[i][j])
			{
				sum += dfs(i, j, 0);
			}
		}
	return sum;
}

void go(int index)
{
	if (index == m * n)
	{		
		memset(check, false, sizeof(check));
		ans.push_back(makeSum()); // ���� �ĺ�
		return;
	}
	// 0 ~ 15�� �ε����� ���� ��� ��� Ȯ��
	xy[index / m][index % m] = 1; // 1�� �ִ� ���
	go(index + 1);
	xy[index / m][index % m] = 0; // 0�� �ִ� ���
	go(index + 1);

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
			a[i][j] = str[j] - '0';
	}

	go(0);

	auto max = max_element(ans.begin(), ans.end());
	cout << *max << '\n'; // �ִ� ���
		

}