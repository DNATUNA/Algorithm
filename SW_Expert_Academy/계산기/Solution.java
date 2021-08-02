package com.company;

import java.util.Scanner;

class Solution {
    private final static int MAXR  		= 99;
    private final static int MAXC		= 26;

    private final static int MAXL		= 100;

    private final static int INIT		= 100;
    private final static int SET		= 200;
    private final static int UPDATE		= 300;

    private static int R;
    private static int C;

    private static int gethash(int value[][]) {
        int ret = 0;

        for (int r = 0; r < R; ++r)
            for (int c = 0; c < C; ++c)
                ret = (ret * 7 + value[r][c]) & 0x7fffffff;

        return ret;
    }

    private final static UserSolution usersolution = new UserSolution();

    private static boolean run(Scanner sc) {
        int Q = sc.nextInt();
        boolean okay = true;

        char input[] = new char[MAXL];
        int value[][] = new int[MAXR][MAXC];

        int cmd, row, col;
        int userhash, answerhash;
        int k;

        for (int q = 0; q < Q; ++q) {
            cmd = sc.nextInt();

            switch(cmd) {
                case INIT:
                    C = sc.nextInt();
                    R = sc.nextInt();
                    if (okay) usersolution.init(C, R);
                    break;
                case SET:
                    col = sc.nextInt();
                    row = sc.nextInt();
                    String inputStr = sc.next();
                    for (k = 0; k < inputStr.length(); ++k)
                        input[k] = inputStr.charAt(k);
                    input[k] = '\0';
                    if (okay) usersolution.set(col, row, input);
                    break;
                case UPDATE:
                    answerhash = sc.nextInt();
                    if (okay) {
                        usersolution.update(value);
                        userhash = gethash(value);
                        if (answerhash != userhash)
                            okay = false;
                    }
                    break;
                default:
                    break;
            }
        }

        return okay && Q > 0;
    }


    public static void main(String[] args) throws Exception {
        int TC;

        System.setIn(new java.io.FileInputStream("res/sample_input.txt"));
        Scanner sc = new Scanner(System.in);
        TC = sc.nextInt();

        int totalscore = 0;
        for (int testcase = 1; testcase <= TC; ++testcase) {
            int score = run(sc) ? 100 : 0;
            System.out.println("#" + testcase + " " + score);
            totalscore += score;
        }
        System.out.println("total score = " + totalscore / TC);
        sc.close();
    }
}