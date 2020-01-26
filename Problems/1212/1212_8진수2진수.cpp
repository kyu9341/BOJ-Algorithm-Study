#include<iostream>
#include<string>

using namespace std;
string eight[8] = { "000", "001", "010", "011", "100", "101", "110", "111" }; // 8진수 0~7 의 각가 출력될 2진수

int main(void)
{
	string n;
	cin >> n;
	
	int size = n.size();
	bool start = true; // 첫 번째 수 인지 판별

	if (n[0] - '0' == 0 && size == 1) // 입력이 0 인경우 0출력 후 종료
	{
		cout << "0";
		return 0;
	}

	for (int i = 0; i < size; i++)
	{
		int position = n[i] - '0'; // 현재 자리의 8진수
		if (start == true && position < 4) // 첫 번째 수 && 4보다 작은 (2진수)2자리인 경우 처리
		{
			if (position == 0) // 맨 앞에 0이 입력된 경우 무시
				continue;
			else if (position == 1)
				cout << "1";
			else if (position == 2)
				cout << "10";
			else if (position == 3)
				cout << "11";
			start = false;
		}
		else
		{
			cout << eight[position];
			start = false;
		}
			
	}
	cout << '\n';
}