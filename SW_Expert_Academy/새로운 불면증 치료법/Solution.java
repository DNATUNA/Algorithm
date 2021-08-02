package com.company;

import java.util.Scanner;

class Solution
{
    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();

        int check = 0b1111111111;

        for(int test_case = 1; test_case <= T; test_case++)
        {
            int N = sc.nextInt();
            int ans = 0, tmp=0, NN=N;
            while(true){
                int count = NN;
                ans++;
                while(count!=0){
                    tmp |= numberToBit(count%10);
                    count /= 10;
                }
                if(tmp==check) break;
                NN+=N;
            }
            System.out.println("#"+test_case+' '+NN);
        }
    }
    public static int numberToBit(int a){
        int bit;

        switch (a) {
            case 0:
                bit = 0b0000000001;
                break;
            case 1:
                bit = 0b0000000010;
                break;
            case 2:
                bit = 0b0000000100;
                break;
            case 3:
                bit = 0b0000001000;
                break;
            case 4:
                bit = 0b0000010000;
                break;
            case 5:
                bit = 0b0000100000;
                break;
            case 6:
                bit = 0b0001000000;
                break;
            case 7:
                bit = 0b0010000000;
                break;
            case 8:
                bit = 0b0100000000;
                break;
            case 9:
                bit = 0b1000000000;
                break;
            default:
                bit = 0;
        }
        return bit;
    }
}