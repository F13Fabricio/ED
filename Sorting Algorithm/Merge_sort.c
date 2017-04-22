#include <stdio.h>
#include <stdlib.h>

void mergeSort(int* v, int p, int q);
void merge(int* v, int p, int m, int q);
void printVect(int* v, int length);

int main() {
	int length, i = 0;
	scanf("%d", &length);
	int v[length];
	if (length > 0) {
		while (i < length)
			scanf("%d", &v[i++]);
		printVect(v, length);
		mergeSort(v, 0, length - 1);
		printVect(v, length);
	}
	return 0;
}

void mergeSort(int* v, int p, int q) {
	if (p < q) {
		int m = (p + q) / 2; //posicao do meio
		mergeSort(v, p, m); //ordenar o primeiro pedaço
		mergeSort(v, m + 1, q); //ordenar o segundo pedaço
		merge(v, p, m, q); //fazer o merge entre os dois pedaços
	}
}

void merge(int* v, int p, int m, int q) {
	int* vAux, i = 0, j, p1 = p, p2 = m + 1;
	vAux = (int*) malloc((q - p + 1) * sizeof(int)); //aloca vetor auxiliar
	
	while (p1 <= m && p2 <= q) {
		if (v[p1] <= v[p2])
			vAux[i++] = v[p1++];
		else
			vAux[i++] = v[p2++];
	}

	while (p1 <= m) //copiar possiveis elementos restantes do primeiro pedaço
		vAux[i++] = v[p1++];
	
	while (p2 <= q) //copiar possiveis elementos restantes do segundo pedaço
		vAux[i++] = v[p2++];
	
	for (i = 0, j = p; j <= q; i++, j++) //copiar vetor ordenado para o inicial
		v[j] = vAux[i];
	free(vAux);
}

void printVect(int* v, int length) {
	if (!length)
		return;
	int i;
	for (i = 0; i < length - 1; i++)
		printf("%d, ", v[i]);
	printf("%d\n", v[length - 1]);
}
