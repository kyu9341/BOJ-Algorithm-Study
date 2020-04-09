package com.kwon.algorithm;

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