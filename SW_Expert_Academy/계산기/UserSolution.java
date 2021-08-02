package com.company;

class UserSolution {
    private final static int MAXR  = 99;
    private final static int MAXC  = 26;

    public static class Table {
        long digital = 0;
        char method = 'A';
        int fX, fY, sX, sY;
    }

    Table[][] table;
    int[][] visit;
    int C, R;
    public void init(int C, int R) {
        table = new Table[R][C];
        this.C = C; this.R = R;
        for(int i=0; i<C; ++i){
            for(int j=0; j<R; ++j){
                table[j][i] = new Table();
            }
        }
    }

    public long calu(Table data){
        if(data.method == 'D' || data.method == 'B' || data.method == 'L' || data.method == 'V') {
            if(visit[data.fY][data.fX]==0){
                table[data.fY][data.fX].digital = calu(table[data.fY][data.fX]);
                visit[data.fY][data.fX]++;
            }
            if(visit[data.sY][data.sX]==0){
                table[data.sY][data.sX].digital = calu(table[data.sY][data.sX]);
                visit[data.sY][data.sX]++;
            }
            long ans;
            if(data.method == 'D') {        // ADD
                ans = table[data.fY][data.fX].digital + table[data.sY][data.sX].digital;
            } else if(data.method == 'B') { // SUB
                ans = table[data.fY][data.fX].digital - table[data.sY][data.sX].digital;
            } else if(data.method == 'L') { // MUL
                ans = table[data.fY][data.fX].digital * table[data.sY][data.sX].digital;
            } else {                        // DIV
                ans = table[data.fY][data.fX].digital / table[data.sY][data.sX].digital;
            }
            return ans;
        } else {
            long add = 0;
            long max = -1000000000;
            long min = 1000000000;
            for(int x=data.fX; x<=data.sX; ++x){
                for(int y=data.fY; y<=data.sY; ++y){
                    if(visit[y][x]==0){
                        table[y][x].digital = calu(table[y][x]);
                        visit[y][x]++;
                    }
                    if(data.method == 'X') { // MAX
                        max = max > table[y][x].digital ? max : table[y][x].digital;
                    } else if(data.method == 'N') { // MIN
                        min = min < table[y][x].digital ? min : table[y][x].digital;
                    } else if(data.method == 'M') { // SUM
                        add += table[y][x].digital;
                    }
                }
            }
            if(data.method == 'X') { // MAX
                return max;
            } else if(data.method == 'N') { // MIN
                return min;
            } else { // SUM
                return add;
            }
        }
    }

    public void set(int col, int row, char[] input) {
        col--; row--;
        if('0'<=input[0] && input[0]<='9'){
            for(int i=0; input[i]!='\0'; ++i){
                if(i==0) table[row][col].digital = input[i] - '0';
                else table[row][col].digital = table[row][col].digital * 10 + input[i] - '0';
            }
            table[row][col].method='A';
        } else if(input[0] == '-'){
            for(int i=0; input[i]!='\0'; ++i){
                if(input[i]=='-') continue;
                else if(i==1) table[row][col].digital = -(input[i] - '0');
                else table[row][col].digital = table[row][col].digital * 10 -(input[i] - '0');
            }
            table[row][col].method='A';
        } else {
                                                // ADD, SUB, MUL, DIV, MAX, MIN, SUM
            table[row][col].method = input[2];  // 명령어의 맨 뒷 문자열이 다 달라서 그것만 보면 된다
            //ADD(A1,A2)
            //0123456789
            int i=4;
            table[row][col].fX = input[i++] - 'A';
            table[row][col].fY = input[i++] - '0';
            for(;input[i]!=','; ++i){
                table[row][col].fY = table[row][col].fY * 10 + input[i] - '0';
            }
            i++;
            table[row][col].sX = input[i++] - 'A';
            table[row][col].sY = input[i++] - '0';
            for(;input[i]!=')'; ++i){
                table[row][col].sY = table[row][col].sY * 10 + input[i] - '0';
            }
            table[row][col].fY--; table[row][col].sY--;
            table[row][col].digital=0;
        }
    }

    public void update(int value[][]) {
        visit = new int[R][C];
        for(int i=0; i<C; ++i){
            for(int j=0; j<R; ++j){
                if(table[j][i].method=='A'){value[j][i]= (int)table[j][i].digital; visit[j][i]++;}
            }
        }

        for(int i=0; i<C; ++i){
            for(int j=0; j<R; ++j){
                if (visit[j][i] == 0) {
                    table[j][i].digital = calu(table[j][i]);
                    visit[j][i]++;
                }
                value[j][i]=(int)table[j][i].digital;
            }
        }
    }
}
