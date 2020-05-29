package com.kwon.boj2606;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static ArrayList<ArrayList<Integer>> map = new ArrayList<>();
    static boolean check[];

    public static void dfs (int node) {
        check[node] = true;

        for (int i = 0; i < map.get(node).size(); i++) {
            int next = map.get(node).get(i);
            if (!check[next]) {
                dfs(next);
            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        for (int i = 0; i <= n; i++) {
            map.add(new ArrayList<>());
        }

        check = new boolean[n + 1];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            map.get(u).add(v);
            map.get(v).add(u);
        }

        dfs(1);
        int cnt = -1;
        for (int i = 1; i <= n; i++) {
            if (check[i]) cnt++;
        }
        System.out.println(cnt);

    }
}
