package com.kwon.boj4949;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Stack<Character> s = new Stack<>();
        StringBuilder sb = new StringBuilder();


        while (true){
            String line = br.readLine();
            if (line.equals(".")) break;
            boolean check = true;
            for (int i = 0; i < line.length(); i++) {
                if (line.charAt(i) == '(' || line.charAt(i) == '[') {
                    s.push(line.charAt(i));
                }
                else if (line.charAt(i) == ')') {
                    if (!s.empty() && s.peek() == '(')
                        s.pop();
                    else {
                        check = false;
                        break;
                    }
                }
                else if (line.charAt(i) == ']') {
                    if (!s.empty() && s.peek() == '[')
                        s.pop();
                    else {
                        check = false;
                        break;
                    }
                }

            }
            if (check && s.empty()) sb.append("yes\n");
            else sb.append("no\n");
            s.clear();
        }

        System.out.println(sb);

    }
}
