package com.kwon.boj1620;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static int n, m;
    static HashMap<String, Integer> hashMap = new HashMap<>();
    static String str[];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
                    m = Integer.parseInt(st.nextToken());

                    str = new String[n + 1];

                    for (int i = 1; i <= n; i++) {
                        String name = br.readLine();
                        hashMap.put(name, i);
                        str[i] = name;
                    }

                    Set<String> keys = hashMap.keySet();

                    for (int i = 0; i < m ; i++) {
                        String input = br.readLine();
                        boolean check = true;
                        for (int j = 0; j < input.length(); j++) {
                            if (!Character.isDigit(input.charAt(j))) {
                    check = false;
                    break;
                }
            }
            if (check) {
                int num = Integer.parseInt(input);
                System.out.println(str[num]);
            }
            else {
                System.out.println(hashMap.get(input));
            }
        }
    }
}
