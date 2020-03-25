#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
const int MAX = 100;
int n, l;
int a[MAX][MAX];
bool check_row[MAX];
bool check_col[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	for (int i = 0; i < n; i++)
	{
		int cnt = 1; // ������ ��
		check_row[i] = true; // �ʱⰪ true (������ �� �ִ� ����)
		bool check_d = false; // �������� ���θ� ��ģ ���¶�� true

		for (int j = 0; j < n - 1; j++)
		{
			int gap = a[i][j + 1] - a[i][j];
			if (gap > 1 || gap < -1) // �������� 2 �̻��̸� �Ұ����� ���
			{
				check_row[i] = false;
				break;
			}
			if (gap == 0) // ���� ������ ���
			{
				cnt++; // ���� ������ ����
				if (l != 1 && check_d && cnt >= l) // �������� ���θ� ���� �� �ִ� ���
				{  // ������ ���̰� 1�� ���� ����
					check_d = false; // ������ �ν�
					cnt = 0;
				}
			}
			else if (gap == 1) // ���̰� ������ ���
			{
				if (l != 1 && check_d) // ���ΰ� �������ٰ� �ٷ� �ö󰡴� ��� �Ұ���
				{
					check_row[i] = false;
					break;
				}
				if (l == 1 && check_d && cnt == 1)
				{  // ������ ���̰� 1�� ��, �������ٰ� �ٷ� �ö���� ��� �Ұ���
					check_row[i] = false;
					break;
				} // l = 1�� ��, �������� ���θ� ���� �ٽ� �ö󰡴� ���θ� ���� �� �ִ� ���
				else if(l == 1 && check_d && cnt > 1) check_d = false;

				if (cnt < l) // �ö󰡴� ���θ� ���� �� ���� ��� �Ұ���
				{
					check_row[i] = false;
					break;
				}
				cnt = 1; // ���̰� �ٲ�����Ƿ� �ʱ�ȭ
			}
			else if (gap == -1) // ���̰� �������ٸ�
			{
				if (l != 1 && check_d) // �������� �������� ���θ� �� �� ���� �� ����
				{ // 1�� ����
					check_row[i] = false;
					break;
				}
				check_d = true; // ���� ���̿��� ������ ���̸� üũ
				cnt = 1;
			}

			if (l != 1 && j == n - 2 && check_d) check_row[i] = false; // ������ �������� ������ �� ���θ� ������ ���ϴ� ���
		}
	}


	for (int j = 0; j < n; j++)
	{
		int cnt = 1; // ������ �� 
		check_col[j] = true; // �ʱⰪ true (������ �� �ִ� ����)
		bool check_d = false; // �������� ���θ� ��ģ ���¶�� true

		for (int i = 0; i < n - 1; i++)
		{
			int gap = a[i + 1][j] - a[i][j];
			if (gap > 1 || gap < -1) // �������� 2 �̻��̸� �Ұ����� ���
			{
				check_col[j] = false;
				break;
			}
			if (gap == 0) // ���� ������ ���
			{
				cnt++; // ���� ������ ����
				if (l != 1 && check_d && cnt >= l)  // �������� ���θ� ���� �� �ִ� ���
				{ // ������ ���̰� 1�� ���� ����
					check_d = false; // �ٽ� ������ �ν�
					cnt = 0;
				}
			}
			else if (gap == 1) // ���̰� ������ ���
			{
				if (l != 1 && check_d)  // ���ΰ� �������ٰ� �ٷ� �ö󰡴� ��� �Ұ���
				{
					check_col[j] = false;
					break;
				}
				if (l == 1 && check_d && cnt == 1)
				{ // ������ ���̰� 1�� ��, �������ٰ� �ٷ� �ö���� ��� �Ұ���
					check_col[j] = false;
					break;
				} //l = 1�� ��, �������� ���θ� ���� �ٽ� �ö󰡴� ���θ� ���� �� �ִ� ���
				else if (l == 1 && check_d && cnt > 1) check_d = false;

				if (cnt < l) // �ö󰡴� ���θ� ���� �� ���� ��� �Ұ���
				{
					check_col[j] = false;
					break;
				}
				cnt = 1; // ���̰� �ٲ�����Ƿ� �ʱ�ȭ
			}
			else if (gap == -1) // ���̰� �������ٸ�
			{
				if (l != 1 && check_d) // �������� �������� ���θ� �� �� ���� �� ����
				{ // 1�� ����
					check_col[j] = false;
					break;
				}
				check_d = true; // ���� ���̿��� ������ ���̸� üũ
				cnt = 1;
			}

			if (l != 1 && i == n - 2 && check_d) check_col[j] = false; // ������ �������� ������ �� ���θ� ������ ���ϴ� ���
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) // �� ��, �� ���� ������ �� �ִ� ���� �� üũ
	{
		if (check_row[i])
		{
			ans++;
			//cout << "row : " << i << '\n'; // ������
		}
		if (check_col[i])
		{
			ans++;
			//cout << "col : " << i << '\n'; // ������
		}
	}

	cout << ans << '\n';
}