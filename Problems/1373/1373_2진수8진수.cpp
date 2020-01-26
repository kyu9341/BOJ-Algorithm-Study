#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string n;
	cin >> n;
	int size = n.size();
	if (size % 3 == 1) { // 3으로 나눈 나머지가 1이면 3개씩 묶어 계산 후 1자리가 남음
		cout << n[0]; // 1자리가 남는다는 것은 1이 남는다는 것이므로 맨 앞에 1출력
	}
	else if (size % 3 == 2) { // 3개씩 묶어 계산 후 2자리가 남음
		cout << (n[0] - '0') * 2 + (n[1] - '0'); // 남는 2자리 계산하여 맨 앞에 출력
	}
	for (int i = size % 3; i < size; i += 3) { // 나머지가 남는 경우 처리한 부분 외 3개씩 묶어서 처리
		cout << (n[i] - '0') * 4 + (n[i + 1] - '0') * 2 + (n[i + 2] - '0');
	}
	cout << '\n';
}