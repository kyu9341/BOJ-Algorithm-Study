#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
vector<string> ans;
bool check[10];
int n;
char a[20]; // �ε�ȣ�� �Է¹��� �迭

bool ok(int x, int y, char op)  // �ε�ȣ ���谡 �´��� �Ǻ��ϴ� �Լ�
{
	if (op == '<' && x > y)
		return false;
	if (op == '>' && x < y)
		return false;
	return true;

}

void go(int index, string num)
{
	if (index == n + 1) // �ε�ȣ ���� + 1������ Ȯ���ߴٸ�
	{
		ans.push_back(num); // ���� �ĺ��� �߰�
		return;
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (check[i]) continue; // �ߺ� ����
		if (index == 0 || ok(num[index - 1] - '0', i, a[index - 1]))
		{ // ù ��° ���� �׳� �ְ�, ������ �� ���� �ε�ȣ ���踦 �����ϴ��� Ȯ��
			check[i] = true; // ����� ���� üũ
			go(index + 1, num + to_string(i));
			check[i] = false;
		}

	}

}

int main(void)
{
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++)
		cin >> a[i];

	go(0, "");

	auto p = minmax_element(ans.begin(), ans.end()); // �ִ� �ּ� ���� ����

	cout << *p.second << '\n';
	cout << *p.first << '\n';

}