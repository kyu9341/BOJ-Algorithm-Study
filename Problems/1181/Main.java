package com.kwon.boj1181;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int n;

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        n = Integer.parseInt(br.readLine());

        HashSet<String> set = new HashSet<>();
        for(int i = 0; i < n; i++){
            set.add(br.readLine());
        }

        List<String> wordList = new ArrayList<>(set);

        Collections.sort(wordList, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                if(o1.length() > o2.length()) return 1; // 길이 기준 오름차순
                else if(o1.length() < o2.length()) return -1;
                else return o1.compareTo(o2); // 길이가 같으면 사전순
            }
        });

        for(String s : wordList){
            System.out.println(s);
        }

    }
}
