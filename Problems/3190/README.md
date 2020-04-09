# Problem 3190

## 뱀

### 문제
'Dummy' 라는 도스게임이 있다. 이 게임에는 뱀이 나와서 기어다니는데, 사과를 먹으면 뱀 길이가 늘어난다. 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.

게임은 NxN 정사각 보드위에서 진행되고, 몇몇 칸에는 사과가 놓여져 있다. 보드의 상하좌우 끝에 벽이 있다. 게임이 시작할때 뱀은 맨위 맨좌측에 위치하고 뱀의 길이는 1 이다. 뱀은 처음에 오른쪽을 향한다.

뱀은 매 초마다 이동을 하는데 다음과 같은 규칙을 따른다.

먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다. 즉, 몸길이는 변하지 않는다.
사과의 위치와 뱀의 이동경로가 주어질 때 이 게임이 몇 초에 끝나는지 계산하라.

### 입력
첫째 줄에 보드의 크기 N이 주어진다. (2 ≤ N ≤ 100) 다음 줄에 사과의 개수 K가 주어진다. (0 ≤ K ≤ 100)

다음 K개의 줄에는 사과의 위치가 주어지는데, 첫 번째 정수는 행, 두 번째 정수는 열 위치를 의미한다. 사과의 위치는 모두 다르며, 맨 위 맨 좌측 (1행 1열) 에는 사과가 없다.

다음 줄에는 뱀의 방향 변환 횟수 L 이 주어진다. (1 ≤ L ≤ 100)

다음 L개의 줄에는 뱀의 방향 변환 정보가 주어지는데,  정수 X와 문자 C로 이루어져 있으며. 게임 시작 시간으로부터 X초가 끝난 뒤에 왼쪽(C가 'L') 또는 오른쪽(C가 'D')로 90도 방향을 회전시킨다는 뜻이다. X는 10,000 이하의 양의 정수이며, 방향 전환 정보는 X가 증가하는 순으로 주어진다.

### 출력
첫째 줄에 게임이 몇 초에 끝나는지 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/3190>

### 예제 입력 1
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D

### 예제 출력 1
9

### 예제 입력 2
10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L

### 예제 출력 2
21

### 예제 입력 3
10
5
1 5
1 3
1 2
1 6
1 7
4
8 D
10 D
11 D
13 L

### 예제 출력 3
13


### solve
- 뱀의 몸을 2, 사과를 1로 하여 위치를 기록한다.
- 덱을 사용하여 뱀이 몸길이를 늘려 칸을 이동할 때 덱의 맨 앞에 좌표를 삽입하고,
- 다음 칸에 사과가 있다면, 사과가 사라지므로 값을 2로 변경한다.
- 사과가 없다면, 덱의 맨 뒤에 있는 원소(꼬리가 위치한 칸)의 좌표에 값을 0으로 변경하고 덱의 마지막 원소를 제거한다.
- 뱀의 회전은 방향을 동, 남, 서, 북을 각각 0, 1, 2, 3으로 지정하여 D가 입력된 경우 이전 방향의 값에 1을 더하고 4로 나눈 나머지를 넣고, L이 입력된 경우 3을 더하고 4로 나눈 나머지를 넣는다.
	- 이렇게 한다면 다른 조건 없이 네 방향을 회전할 수 있다.
- 변환 횟수만큼 배열에 변환되는 시간과 방향을 기록해 두고 while문 안에서 경과 시간이 변환 시간과 같아질 때 방향을 변경해준다.
- 위 조건을 반복하다가 자신의 몸(map[x][y] = 2인 경우)이나 벽에 부딪힌 경우 반복문을 나가고 경과한 시간을 출력한다.


### 코드 설명
- 자바 코드
```Java
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static class Dot{
        int x;
        int y;

        Dot(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
    static int n, k, l;
    static int map[][];
    static int time[]; // i번째 차례의 시간 저장
    static char dir[]; // i번째 방향 전환 정보

    static Deque<Dot> snake = new ArrayDeque<>();

    final static int dx[] = {0, 1, 0, -1}; // 동 남 서 북
    final static int dy[] = {1, 0, -1, 0};
    final static int MAX = 100;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());

        map = new int[n + 1][n + 1];

        for(int i = 0; i < k; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            map[x][y] = 1;
        }

        l = Integer.parseInt(br.readLine());

        time = new int[l];
        dir = new char[l];

        for(int i = 0; i < l; i++){
            st = new StringTokenizer(br.readLine());
            time[i] = Integer.parseInt(st.nextToken());
            String tmp = st.nextToken();
            dir[i] = tmp.charAt(0);
        }

        // 뱀의 처음 위치
        map[1][1] = 2;
        snake.add(new Dot(1, 1));

        int timeIdx = 0; // 방향 전환 횟수
        int sec = 0; // 전체 시간
        int nowdir = 0; // 이번 방향

        while(true){

            if(timeIdx < l && time[timeIdx] == sec){
                if(dir[timeIdx] == 'D'){
                    nowdir = (nowdir + 1) % 4;
                }else{
                    nowdir = (nowdir + 3) % 4;;
                }
                timeIdx++;
            }

            // 다음 위치로 이동
            int nx = snake.getFirst().x + dx[nowdir];
            int ny = snake.getFirst().y + dy[nowdir];
            // 몸 or 벽에 부딪힌 경우
            if(nx > n || ny > n || nx <= 0 || ny <= 0 ) break;
            if(map[nx][ny] == 2) break;

            snake.addFirst(new Dot(nx, ny));

            if(map[nx][ny] == 1){ // 다음 칸에 사과가 있는 경우
                map[nx][ny] = 2;
            }
            else if(map[nx][ny] == 0){ // 없는 경우
                map[nx][ny] = 2;
                Dot tail = snake.removeLast();
                map[tail.x][tail.y] = 0;
            }
            sec++;

        }

        System.out.println(sec + 1);

    }
}

```
