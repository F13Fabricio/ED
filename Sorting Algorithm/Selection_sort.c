#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* v, int length);
void printVect(int* v, int length);

int main() {
	int length, i = 0;
	scanf("%d", &length);
	int v[length];
	if (length > 0) {
		while (i < length) {
			scanf("%d", &v[i]);
			i++;
		}
		selectionSort(v, length);
		printVect(v, length);
	}
	return 0;
}

void selectionSort(int* v, int length) {
	if (!v || length < 2)
		return;
	int i, j, min, aux;
	for (i = 0; i < length; i++) {
		min = i;
		for (j = min; j < length; j++) {
			if (v[j] < v[min])
				min = j;
		}
		if (min != i) {
			aux = v[min];
			v[min] = v[i];
			v[i] = aux;
		}
	}
}

void printVect(int* v, int length) {
	if (!length)
		return;
	int i;
	for (i = 0; i < length - 1; i++)
		printf("%d, ", v[i]);
	printf("%d", v[length - 1]);
}
