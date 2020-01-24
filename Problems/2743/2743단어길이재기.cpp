#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str;
	cin >> str;
	int n;
	int i = 0;

	while (str[i] != '\0')
		i++;
	cout << i << '\n';
}