package com.kwon.boj2468;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pair {
    int x;
    int y;
    Pair (int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {

    public static final int[] dx = {1, -1, 0, 0};
    public static final int[] dy = {0, 0, 1, -1};
    static int n;
    static int map[][];
    static boolean check[][];

    public static void bfs(int sx, int sy, int k) {
        Queue<Pair> q = new LinkedList<>();
        check[sx][sy] = true;
        q.add(new Pair(sx, sy));

        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    if (!check[nx][ny] && map[nx][ny] > k) {
                        check[nx][ny] = true;
                        q.add(new Pair(nx, ny));
                    }
                }
            }

        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        map = new int[n][n];
        check = new boolean[n][n];

        int max = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (max < map[i][j]) max = map[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i <= max; i++) { // 아무 지역도 물에 잠기지 않는 경우는 0 일 때
            int cnt = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    if (!check[x][y] && map[x][y] > i) {
                        bfs(x, y, i);
                        cnt++;
                    }
                }
            }
            if (ans < cnt) ans = cnt;
            check = new boolean[n][n];
        }

        System.out.println(ans);
    }
}
