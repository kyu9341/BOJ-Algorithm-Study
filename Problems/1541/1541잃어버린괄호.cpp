#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);
	vector<int> iv;
	vector<char> cv;

	bool isnum = false;
	int tmp = 0;
	for (int i = 0; i < str.size(); i++) // 숫자와 연산자를 나누어 벡터에 저장
	{
		if (str[i] >= '0' && str[i] <= '9') // 숫자인 경우
		{
			if (isnum)
				tmp *= 10;
			tmp += int(str[i] - '0');
			isnum = true; // 이전 인덱스가 숫자임을 저장
		}
		else // 연산자인 경우
		{
			if (isnum) iv.push_back(tmp); // 이전 인덱스가 숫자라면
			isnum = false;
			tmp = 0; // 숫자를 누적하던 변수 초기화
			cv.push_back(str[i]);
		}
		if(i == str.size() - 1) iv.push_back(tmp); // 마지막 숫자 추가
	}
	
	int ans = iv[0]; // 맨 앞 숫자로 초기화
	bool minus = false; // - 이후 나오는 +는 모두 괄호에 묶기 위해 판별
	int mtmp = 0; // -( ) 에 묶이는 누적 값

	for (int i = 0; i < cv.size(); i++)
	{
		if (cv[i] == '-') // -인 경우
		{
			if (minus) // - 괄호에 묶이던 중 -가 나온 경우
			{
				ans -= mtmp; // 앞에 묶인 값 처리
				mtmp = 0;
			}
			mtmp += iv[i + 1]; // - () 누적
			minus = true;
		}
		else // + 인 경우
		{
			if (!minus) // -에 묶이는 +가 아니면
				ans += iv[i + 1]; // 바로 더해줌
			else
			{
				mtmp += iv[i + 1]; // -에 묶이는 경우 누적
			}
		}
	}
	ans -= mtmp; // 마지막에 남는 - () 묶음 처리
	cout << ans << '\n';
}