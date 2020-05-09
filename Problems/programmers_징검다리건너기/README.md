# 프로그래머스 - 징검다리 건너기

## 징검다리 건너기

### 문제
[본 문제는 정확성과 효율성 테스트 각각 점수가 있는 문제입니다.]

카카오 초등학교의 니니즈 친구들이 라이언 선생님과 함께 가을 소풍을 가는 중에 징검다리가 있는 개울을 만나서 건너편으로 건너려고 합니다. 라이언 선생님은 니니즈 친구들이 무사히 징검다리를 건널 수 있도록 다음과 같이 규칙을 만들었습니다.

- 징검다리는 일렬로 놓여 있고 각 징검다리의 디딤돌에는 모두 숫자가 적혀 있으며 디딤돌의 숫자는 한 번 밟을 때마다 1씩 줄어듭니다.
- 디딤돌의 숫자가 0이 되면 더 이상 밟을 수 없으며 이때는 그 다음 디딤돌로 한번에 여러 칸을 건너 뛸 수 있습니다.
- 단, 다음으로 밟을 수 있는 디딤돌이 여러 개인 경우 무조건 가장 가까운 디딤돌로만 건너뛸 수 있습니다.
니니즈 친구들은 개울의 왼쪽에 있으며, 개울의 오른쪽 건너편에 도착해야 징검다리를 건넌 것으로 인정합니다.
니니즈 친구들은 한 번에 한 명씩 징검다리를 건너야 하며, 한 친구가 징검다리를 모두 건넌 후에 그 다음 친구가 건너기 시작합니다.

디딤돌에 적힌 숫자가 순서대로 담긴 배열 stones와 한 번에 건너뛸 수 있는 디딤돌의 최대 칸수 k가 매개변수로 주어질 때, 최대 몇 명까지 징검다리를 건널 수 있는지 return 하도록 solution 함수를 완성해주세요.

### [제한사항]
징검다리를 건너야 하는 니니즈 친구들의 수는 무제한 이라고 간주합니다.
stones 배열의 크기는 1 이상 200,000 이하입니다.
stones 배열 각 원소들의 값은 1 이상 200,000,000 이하인 자연수입니다.
k는 1 이상 stones의 길이 이하인 자연수입니다.

### [입출력 예]
stones	k	result
[2, 4, 5, 3, 2, 1, 4, 2, 5, 1]	3	3


### 문제 링크
<https://programmers.co.kr/learn/courses/30/lessons/64062>

### solve
- 다음으로 밟을 수 있는 디딤돌이 여러 개인 경우 무조건 가장 가까운 디딤돌로만 건너뛸 수 있으므로
- 연속되는 k개의 돌의 숫자가 건너려는 인원 수보다 작지 않은 최대의 경우가 정답이 된다.
- 인원 수는 최대 2억이므로 인원 수를 기준으로 이분 탐색을 수행한다.
	- 현재 인원 수가 돌의 숫자보다 더 큰 경우가 k번 이상 연속된다면 불가능하므로 false를 리턴하고
	- 돌의 숫자가 0이되는 경우가 k번 이상 연속되지 않는다면 가능하므로 true를 리턴하도록 함수를 작성한다.
	- true인 경우 더 큰 인원으로 가능한지 확인하고 false인 경우 더 적은 인원인 경우를 확인한다.

### 코드 설명
```C++
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int> stones, int k, int mid) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		// 현재 인원 수가 돌의 숫자보다 더 큰 경우가 k번 이상 연속된다면 불가능
		if (stones[i] < mid) {
			cnt++;
			if (cnt >= k) return false;
		}
		else cnt = 0;
	}
	// 돌의 숫자가 0이되는 경우가 k번 이상 연속되지 않는다면 가능
	return true;
}


int solution(vector<int> stones, int k) {
	int answer = 0;

	int right = * max_element(stones.begin(), stones.end());
	int left = 1;

	// 징검다리를 건너는 인원 수를 기준으로 이분탐색
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(stones, k, mid)) {
			left = mid + 1;
			if (answer < mid) {
				answer = mid;
			}
		}
		else {
			right = mid - 1;
		}
	}

	return answer;
}
```
