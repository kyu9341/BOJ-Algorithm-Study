#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void)
{
	int a, b; // a����, b����
	cin >> a >> b;
	int n; // a���� �ڸ���
	cin >> n;
	int result = 0; // a���� -> 10����
	while (n--) // a���� -> 10���� ��ȯ
	{
		int num; // �� �ڸ����� ��
		cin >> num;
		
		result = result * a + num;  // �ڸ�����ŭ a�� ���ϰ� ������ �ڸ� num�� ����
	}
	stack<int> s;
	while (result > 0) // 10���� -> b���� ��ȯ
	{
		int r = result % b;
		s.push(r);
		result /= b;
	}
	// ���� �ڸ����� ������ ������ ���ÿ� �׾� ������ ���
	while (!s.empty())
	{
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
}