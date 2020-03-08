#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>

using namespace std;

int alpha[26]; // 알파벳에 해당하는 숫자를 저장할 배열
int calc(vector<string>& a, vector<char>& letters, vector<int>& d) {
	int m = letters.size(); // 중복없는 알파벳의 수
	int sum = 0;
	for (int i = 0; i < m; i++) {
		alpha[letters[i] - 'A'] = d[i]; // A : 0 부터 해당하는 알파벳의 숫자 저장
	}
	for (string s : a) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x - 'A']; // 알파벳에 해당하는 숫자를 가져와 계산
		}
		sum += now; // 한 문자열 누적
	}
	return sum;
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	vector<string> a(n);
	vector<char> letters;

	while (n--)
	{
		string str;
		getline(cin, str);
		a.push_back(str);		
		for (int i = 0; i < str.size(); i++)
			letters.push_back(str[i]); // 문자열의 모든 문자를 저장
	}
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end()); // 벡터의 중복 원소 제거
	// 중복을 제거한 후 벡터의 크기는 입력된 문자의 총 개수
	int m = letters.size();
	vector<int> d; // 각 문자에 대입할 숫자를 저장
	for (int i = 9; i > 9 - m; i--) // 합을 최대로 만들기 위해 가장 큰 수부터 벡터의 크기만큼 추가
		d.push_back(i);

	int ans = 0;
	do
	{
		int now = calc(a, letters, d);
		if (ans < now) ans = now;
	} while (prev_permutation(d.begin(), d.end())); // 9부터 삽입했으므로 이전 순열을 확인

	cout << ans << '\n';
}