#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int s[21][21]; // �ο� �� �ɷ�ġ
int n; // ��ü �ο� ��
int go(int index, vector<int>& first, vector<int>& second) // index : ���� �ε���, first : ù��° ��, second : �ι�° ��
{
	if (index == n) // ���� ���� ���
	{
		if (first.size() != n / 2) return -1; // �߸��� ����� -1 ����
		if (second.size() != n / 2) return -1;
		int t1 = 0; // �� �� �ɷ�ġ �հ�
		int t2 = 0; 
		for(int i = 0; i < n / 2; i++)
			for (int j = 0; j < n / 2; j++)
			{
				if (i == j) continue;
				t1 += s[first[i]][first[j]]; // ù��° ���� s[i][j], s[j][i]�� ��� ����
				t2 += s[second[i]][second[j]];
			}
		int diff = t1 - t2;
		if (diff < 0) diff = -diff;
		
		return diff;
	}
	int ans = -1;
	first.push_back(index); // index��° ����� ù ��° ���� ���� ���
	int t1 = go(index + 1, first, second);
	if (ans == -1 || (t1 != -1 && t1 < ans))
	{
		ans = t1;
	}
	first.pop_back();
	second.push_back(index); // �� ��° ���� ���� ���
	int t2 = go(index + 1, first, second);
	if (ans == -1 || (t2 != -1 && t2 < ans))
	{
		ans = t2;
	}
	second.pop_back();
	return ans;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	vector<int> first, second;
	cout << go(0, first, second) << '\n';
}