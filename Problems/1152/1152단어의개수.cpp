#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<utility>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);

	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			if (i == 0 || i == str.size() - 1) // �� �� �Ǵ� �� �� �����̸� �ǳʶ�
				continue;
			else
				ans++;
		}
	}
	if (str == " ") // ���鸸 �ԷµǴ� ��� ����ó��
		cout << 0 << '\n';
	else
		cout << ans + 1 << '\n'; // �� ��, �� �ڰ� �ƴ� ������ �� + 1�� �ܾ��� ����
}