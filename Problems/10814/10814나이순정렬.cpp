#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct user
{
	int age, order; // 나이, 가입 순서
	string name;
};

bool compare(user u, user v)
{
	if (u.age == v.age) return u.order < v.order;
	else return u.age < v.age;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;

	vector<user> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].age >> a[i].name;
		a[i].order = i; // 가입 순서 저장
	}
	sort(a.begin(), a.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << a[i].age << ' ' << a[i].name;
		cout << '\n';
	}

}