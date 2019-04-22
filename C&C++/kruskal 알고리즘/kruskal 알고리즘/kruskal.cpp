#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;

const int SIZE = 10000;
const int DOT_NUM = 100;

void input_quiz(int(*quiz)[3], const char *fileDir);
struct EDGE {
	int from, to, w;
};
class UnionFind {
public:
	int sz;
	vector<int> p;
	UnionFind(int n) {
		int sz = n + 1;
		p.resize(sz);
		for (int i = 0; i < sz; ++i)
			p[i] = i;
	}
	int Find(int x) {
		if (x == p[x]) return x;
		return p[x] = Find(p[x]);
	}
	bool Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x != y) {
			p[y] = x;
			return 1;
		}
		return 0;
	}
};
void main()
{
	char fileDir[] = "./quiz_4.csv";
	int quiz[SIZE][3];
	int weight_sum = 0;

	// write your var
	input_quiz(quiz, fileDir);

	vector<EDGE> adj, ans;
	UnionFind u(SIZE);
	int costSum = 0, cnt = 0;
	for (int i = 0; i < SIZE; ++i)
		adj.push_back({ quiz[i][0], quiz[i][1], quiz[i][2] });

	//STL Quick Sort(Unstable)
 /*   sort(adj.begin(), adj.end(), [](EDGE e1, EDGE e2) {
	   return e1.w < e2.w;
	});
 */
 //STL Stable sort
//   stable_sort(adj.begin(), adj.end(), [](EDGE e1, EDGE e2) {
//      return e1.w < e2.w;
//   });   

   // write bubble sorting code
	for (int i = adj.size() - 1; i > 0; --i) {
		for (int j = 0; j < i; ++j) {
			if (adj[j].w > adj[j + 1].w)
				swap(adj[j], adj[j + 1]);
		}
	}


	// print 6712th weight
	printf("6712th dot's weight : %d\n", adj[6711].w);

	// write kruskal MST code
	reverse(adj.begin(), adj.end());
	while (adj.size() && ans.size() < DOT_NUM - 1) {
		++cnt;
		EDGE cur = adj.back(); adj.pop_back();
		if (u.Union(cur.from, cur.to)) {
			ans.push_back(cur);
			costSum += cur.w;
		}
	}
	printf("%d th ", cnt);
	printf("cost_sum = %d", costSum);
}

void input_quiz(int(*quiz)[3], const char *fileDir)
{
	FILE *fp;
	char buffer[SIZE * 3];
	char *ptr;
	int i = 0, j = 0;

	fp = fopen(fileDir, "r");

	if (fp == NULL)
	{
		puts("quiz file open failed!!");

		return;
	}

	for (i = 0; i < SIZE; i++)
	{
		fgets(buffer, SIZE * 3, fp);
		ptr = strtok(buffer, ",");
		j = 0;

		while (ptr != NULL)
		{
			quiz[i][j] = atof(ptr);
			ptr = strtok(NULL, ",");
			j++;
		}
	}

	fclose(fp);
}