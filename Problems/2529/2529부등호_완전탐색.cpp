#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
vector<string> ans; // 정답 후보들을 저장할 벡터
bool check[10];
int n;
char a[20]; // 부등호를 입력받을 배열

bool ok(string num) // 완성된 문자열이 부등호를 만족하는지 판별
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '<')
		{
			if (num[i] > num[i + 1]) return false;
		}
		else if (a[i] == '>')
		{
			if (num[i] < num[i + 1]) return false;
		}
	}
	return true;
}

void go(int index, string num)
{
	if (index == n + 1)
	{
		if(ok(num))
			ans.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (check[i]) continue; // 중복 제거
		check[i] = true;
		go(index + 1, num + to_string(i)); // 문자열에 누적
		check[i] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	go(0, "");

	auto minmax = minmax_element(ans.begin(), ans.end());

	cout << *minmax.second << '\n'; // 최댓값
	cout << *minmax.first << '\n'; // 최솟값

}