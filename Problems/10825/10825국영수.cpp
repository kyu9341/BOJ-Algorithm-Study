#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

struct student
{
	string name;
	int kor;
	int eng;
	int math;

	student(string name, int kor, int eng, int math)
	{
		this->name = name;
		this->kor = kor;
		this->eng = eng;
		this->math = math;
	}

};

bool compare(student u, student v)
{
	if (u.kor == v.kor && u.eng == v.eng && u.math == v.math) return u.name < v.name; // 이름 오름차순
	else if (u.kor == v.kor && u.eng == v.eng) return u.math > v.math; // 수학 내림차순
	else if (u.kor == v.kor) return u.eng < v.eng; // 영어 오름차순
	else return u.kor > v.kor; // 국어 점수 내림차순
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<student> s;

	string name;
	int kor, eng, math;
	while (n--)
	{
		cin >> name >> kor >> eng >> math;
		s.push_back(student(name, kor, eng, math));
	}

	sort(s.begin(), s.end(), compare);

	for (auto x : s)
		cout << x.name << '\n';

}