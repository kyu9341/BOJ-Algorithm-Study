#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int l, c;
	cin >> l >> c;
	vector<char> a(c);
	for (int i = 0; i < c; i++) // 후보 문자 입력
		cin >> a[i];
	sort(a.begin(), a.end());

	vector<int> d;
	for (int i = 0; i < c - l; i++) // 0과 1의 순열을 이용해 선택의 경우를 구함
		d.push_back(0);
	for (int i = 0; i < l; i++)
		d.push_back(1);

	vector<vector<char>> ans; 

	do {
		vector<char> now;
		int vowel = false; // 모음 포함 여부
		int consonant = 0; // 자음 개수 카운트
		for (int i = 0; i < c; i++)
		{
			if (d[i] == 1)
			{
				if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') // 모음일 경우
				{
					vowel = true;
					now.push_back(a[i]);
				}
				else
				{
					consonant++; // 자음 개수
					now.push_back(a[i]);
				}
					
			}	
		}
		if (vowel && consonant >= 2) // 모음이 있고 자음이 2개 이상인 경우에만 추가
			ans.push_back(now);
	} while (next_permutation(d.begin(), d.end()));

	sort(ans.begin(), ans.end()); // 사전순 출력
	for (auto &v : ans)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
		cout << '\n';
	}
}