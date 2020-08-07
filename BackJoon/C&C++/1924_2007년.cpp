#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
	int a = 0, b = 0, count = 0;
	scanf("%d%d", &a, &b);

	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 0; i < a-1; ++i) {
		count += day[i];
	}

	switch ((count+b) % 7) {
	case 0: {
		printf("SUN");
		break;
	}
	case 1: {
		printf("MON");
		break;
	}
	case 2: {
		printf("TUE");
		break;
	}
	case 3: {
		printf("WED");
		break;
	}
	case 4: {
		printf("THU");
		break;
	}
	case 5: {
		printf("FRI");
		break;
	}
	case 6: {
		printf("SAT");
		break;
	}
	}
}
