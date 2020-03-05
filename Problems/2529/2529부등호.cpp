#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
vector<string> ans;
bool check[10];
int n;
char a[20]; // 부등호를 입력받을 배열

bool ok(int x, int y, char op)  // 부등호 관계가 맞는지 판별하는 함수
{
	if (op == '<' && x > y)
		return false;
	if (op == '>' && x < y)
		return false;
	return true;

}

void go(int index, string num)
{
	if (index == n + 1) // 부등호 개수 + 1개까지 확인했다면
	{
		ans.push_back(num); // 정답 후보에 추가
		return;
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (check[i]) continue; // 중복 제거
		if (index == 0 || ok(num[index - 1] - '0', i, a[index - 1]))
		{ // 첫 번째 수는 그냥 넣고, 다음에 올 수가 부등호 관계를 만족하는지 확인
			check[i] = true; // 사용한 수는 체크
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

	auto p = minmax_element(ans.begin(), ans.end()); // 최대 최소 원소 추출

	cout << *p.second << '\n';
	cout << *p.first << '\n';

}