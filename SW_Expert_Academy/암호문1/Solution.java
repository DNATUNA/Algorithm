package com.company;

import java.util.ArrayList;
import java.util.Scanner;

class Solution
{
    public static void main(String args[]) throws Exception
    {
        Scanner sc = new Scanner(System.in);

        for(int a=0; a<10; ++a){
            int N;
            N=sc.nextInt();

            ArrayList<Integer> list = new ArrayList<Integer>();

            for(int i=0; i<N; ++i){
                int tmp = sc.nextInt();
                list.add(tmp);
            }

            N=sc.nextInt();

            String tmp;
            for(int i=0; i<N; ++i){
                tmp=sc.next();
                int x = sc.nextInt(), y=sc.nextInt(), s;
                for(int j=0; j<y; ++j){
                    s= sc.nextInt();
                    list.add(x++, s);
                }
            }

            System.out.print("#"+(a+1));
            for(int i=0; i<10; ++i)
                System.out.print(" "+ list.get(i));
            System.out.println();
        }
    }
}