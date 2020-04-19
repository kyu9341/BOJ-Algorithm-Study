# 프로그래머스 - 카펫

## 카펫

### 문제
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 빨간색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

image.png

Leo는 집으로 돌아와서 아까 본 카펫의 빨간색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 빨간색 격자의 수 red가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

### 제한사항
- 갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
- 빨간색 격자의 수 red는 1 이상 2,000,000 이하인 자연수입니다.
- 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.
### 입출력 예
brown	red	return
10	2	[4, 3]
8	1	[3, 3]
24	24	[8, 6]

### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/42842>

### solve
- 빨간 격자로 만들 수 있는 카펫의 크기를 (가로 * 세로) 라고 한다면 전체 카펫의 크기는 (가로 + 2) * (세로 + 2) 이다.
	- 즉, 갈색 격자의 개수는 (가로 + 2) * (세로 + 2) - (가로 * 세로) 이다.
- 빨간 카펫의 가능한 가로, 세로 상을 벡터에 저장하고, 위의 규칙에 따라 모든 경우를 확인하며 각 경우의 갈색 격자의 수를 구한다.
- 주어진 brown과 이번 경우의 갈색 격자의 수가 일치하다면 답을 구한것이므로 answer벡터에 추가하고 종료한다.



### 코드 설명
```C++
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	vector<pair<int, int>> v;
	// 빨간 카펫의 가능한 가로, 세로 상을 v에 저장
	for (int i = 1; i * i <= red; i++) {
		if (red % i == 0) v.push_back(make_pair(red / i, i));
	}

	for (int i = 0; i < v.size(); i++) {
		// 갈색격자의 개수를 cur에 저장
		int cur = (v[i].first + 2) * (v[i].second + 2) - red;
		// 일치하는 경우 결과 저장
		if (brown == cur) {
			answer.push_back(v[i].first + 2);
			answer.push_back(v[i].second + 2);
			break;
		}
	}


	return answer;
}
```
