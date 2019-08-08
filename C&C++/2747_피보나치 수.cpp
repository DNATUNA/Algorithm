#include<cstdio>

long long int print;
long long int ans[46] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, };

int Fibo(long long int num) {
	if (num == 0) return 0;
	else if (ans[num]) return ans[num];
	else {
		ans[num] = Fibo(num - 1) + Fibo(num - 2);
		return ans[num];
	}
}

int main() {
	long long int num;
	scanf("%lld", &num);
	print = Fibo(num);
	printf("%lld", print);
}