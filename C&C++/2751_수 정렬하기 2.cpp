#include<cstdio>

int list[1000002];
int sort[1000002];

void merge(int arr[], int left, int mid, int right) {
	int sortPivot = left, leftPivot = left, rightPivot = mid + 1;

	while ((leftPivot <= mid) && (rightPivot <= right)) {
		if (list[leftPivot] < list[rightPivot]) {
			sort[sortPivot] = list[leftPivot];
			leftPivot++;
		}
		else {
			sort[sortPivot] = list[rightPivot];
			rightPivot++;
		}
		sortPivot++;
	}

	while (leftPivot <= mid) {
		sort[sortPivot] = list[leftPivot];
		leftPivot++, sortPivot++;
	}

	while (rightPivot <= right) {
		sort[sortPivot] = list[rightPivot];
		rightPivot++, sortPivot++;
	}

	for (int i = left; i <= right; ++i)
		list[i] = sort[i];
}

void split(int arr[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		split(arr, left, mid);
		split(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	int num = 0;
	scanf("%d", &num);

	for (int i = 0; i < num; ++i)
		scanf("%d", &list[i]);

	split(list, 0, num-1);

	for (int i = 0; i < num; ++i)
		printf("%d", list[i]);
}