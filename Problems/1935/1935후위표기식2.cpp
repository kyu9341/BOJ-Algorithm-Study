#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;
double cal(double a, double b, char op);

int main()
{
	string str; // �Է� ���ڿ�
	int n; // �ǿ����� ��
	stack<double> s; // �ǿ����ڸ� ���� ����
	double alphabet[26]; // �ǿ����ڿ� �ش��ϴ� ���ڸ� ������ �迭

	cin >> n;
	cin.ignore();
	getline(cin, str);

	for (int i = 0; i < n; i++)
		cin >> alphabet[i]; 

	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z') // �ǿ������� ��� ���ڷ� ��ȯ�Ͽ� ���ÿ� push
		{
			s.push(alphabet[str[i] - 'A']);
		}
		else // �������� ��� ������ ���� �� ���� �̾� ������ ������ ���� �� �ٽ� push
		{
			double a = s.top();
			s.pop();
			double b = s.top();
			s.pop();
			s.push(cal(a, b, str[i]));
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << s.top() << '\n';

	return 0;
}

double cal(double a, double b, char op)
{
	double res = 0.;
	switch (op)
	{
	case '+':
		res = b + a;
		break;
	case '-':
		res = b - a;
		break;
	case '*':
		res = b * a;
		break;
	case '/':
		res = b / a;
		break;
	}
	return res;
}