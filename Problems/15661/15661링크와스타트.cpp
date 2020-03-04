#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
const int MAX = 20;
int s[MAX + 1][MAX + 1];

int select(int n, int index, vector<int> &a, vector<int> &b)
{

	if (index == n) // ������ ���� ���
	{
		if (a.size() == 0 || b.size() == 0) // ������ �ּ� �� ���̻� �־�� ��.
			return -1;

		int diff = -1;
		int teamA = 0;
		int teamB = 0;
		if (a.size() == 1)  teamA = a[0]; // ������ �Ѹ��� ���
		else
		{
			for (int i = 0; i < a.size(); i++)
				for(int j = 0; j < a.size(); j++)
				teamA += s[a[i]][a[j]]; // ���� ���� ������ ���� �������� �ɷ�ġ ����
		}
		if (b.size() == 1)  teamB = b[0]; // ������ �Ѹ��� ���
		else
		{
			for (int i = 0; i < b.size(); i++)
				for(int j = 0; j < b.size(); j++)
				teamB += s[b[i]][b[j]]; // ���� ���� ������ ���� �������� �ɷ�ġ ����
		}
		diff = teamA - teamB;
		if (diff < 0) diff = -diff;

		return diff;
	}

	int ans = -1;
	a.push_back(index); // index��° ����� a���� �ִ� ���
	int resA = select(n, index + 1, a, b);
	if (ans == -1 || (resA != -1 && resA < ans)) // �߸��� ��찡 �ƴҶ�, �ּڰ��� ���Ѵ�.
		ans = resA;
	a.pop_back(); // �� ���� ����

	b.push_back(index); // index��° ����� b���� �ִ� ���
	int resB = select(n, index + 1, a, b);
	if (ans == -1 || (resB != -1 && resB < ans))
		ans = resB;
	b.pop_back();

	return ans;
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	vector<int> a;
	vector<int> b;

	int ans = select(n, 0, a, b);
	cout << ans << '\n';
}