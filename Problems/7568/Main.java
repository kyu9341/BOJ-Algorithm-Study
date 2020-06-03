package com.kwon.boj7568;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static class Size {
        int height;
        int weight;

        public Size(int height, int weight) {
            this.height = height;
            this.weight = weight;
        }
        public Size (){}

        public boolean compare(Size s){
            if (this.weight < s.weight && this.height < s.height)
                return true;
            return false;
        }
    }

    static int n;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        StringTokenizer st;
        ArrayList<Size> sizeList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int weight = Integer.parseInt(st.nextToken());
            int height = Integer.parseInt(st.nextToken());
            sizeList.add(new Size(weight, height));
        }

        for (int i = 0; i < sizeList.size(); i++) {
            int cnt = 1;
            for (int j = 0; j < sizeList.size(); j++) {
                if (i == j) continue;
                if (sizeList.get(i).compare(sizeList.get(j))) {
                    cnt++;
                }
            }
            System.out.println(cnt);
        }
    }
}
