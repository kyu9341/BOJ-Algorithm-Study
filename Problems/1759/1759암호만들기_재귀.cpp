#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool check(string password) // 만들어진 암호가 자음 두개 모음 하나 이상을 포함하는 암호인지 확인하는 함수
{
	int ja = 0;
	int mo = 0;

	for (auto x : password)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		{
			mo++;
		}
		else
		{
			ja++;
		}
	}
	if (ja >= 2 && mo >= 1)
		return true;
	else
		return false;
}

void go(int n, vector<char>& a, string password, int i) // n : 암호알파벳 수, a는 사용할 수 있는 알파벳 벡터, password : 결과 암호, i : 인덱스
{
	if (password.length() == n) // 암호 알파벳 수가 다 채워진 경우
	{
		if (check(password))
		{
			cout << password << '\n';
		}
		return;
	}
	if (i >= a.size()) return; // 모든 a의 알파벳을 사용했는데 비밀번호를 만들지 못한 경우
	go(n, a, password + a[i], i + 1); // a[i] 알파벳을 사용하는 경우
	go(n, a, password, i + 1); // a[i] 알파벳을 사용하지 않는 경우
}


int main(void)
{
	int l, c;
	cin >> l >> c;
	vector<char> a(c);
	for (int i = 0; i < c; i++) // 후보 문자 입력
		cin >> a[i];
	sort(a.begin(), a.end());
	
	string password = "";

	go(l, a, password, 0);

}