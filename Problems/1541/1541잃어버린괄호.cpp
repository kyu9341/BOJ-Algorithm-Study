#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);
	vector<int> iv;
	vector<char> cv;

	bool isnum = false;
	int tmp = 0;
	for (int i = 0; i < str.size(); i++) // ���ڿ� �����ڸ� ������ ���Ϳ� ����
	{
		if (str[i] >= '0' && str[i] <= '9') // ������ ���
		{
			if (isnum)
				tmp *= 10;
			tmp += int(str[i] - '0');
			isnum = true; // ���� �ε����� �������� ����
		}
		else // �������� ���
		{
			if (isnum) iv.push_back(tmp); // ���� �ε����� ���ڶ��
			isnum = false;
			tmp = 0; // ���ڸ� �����ϴ� ���� �ʱ�ȭ
			cv.push_back(str[i]);
		}
		if(i == str.size() - 1) iv.push_back(tmp); // ������ ���� �߰�
	}
	
	int ans = iv[0]; // �� �� ���ڷ� �ʱ�ȭ
	bool minus = false; // - ���� ������ +�� ��� ��ȣ�� ���� ���� �Ǻ�
	int mtmp = 0; // -( ) �� ���̴� ���� ��

	for (int i = 0; i < cv.size(); i++)
	{
		if (cv[i] == '-') // -�� ���
		{
			if (minus) // - ��ȣ�� ���̴� �� -�� ���� ���
			{
				ans -= mtmp; // �տ� ���� �� ó��
				mtmp = 0;
			}
			mtmp += iv[i + 1]; // - () ����
			minus = true;
		}
		else // + �� ���
		{
			if (!minus) // -�� ���̴� +�� �ƴϸ�
				ans += iv[i + 1]; // �ٷ� ������
			else
			{
				mtmp += iv[i + 1]; // -�� ���̴� ��� ����
			}
		}
	}
	ans -= mtmp; // �������� ���� - () ���� ó��
	cout << ans << '\n';
}