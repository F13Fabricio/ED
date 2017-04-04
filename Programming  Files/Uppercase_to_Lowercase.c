#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Problema: ler um arquivo contendo
um texto em minúsculo e criar outro
aquivo com o texto em maiúsculo*/

int main() {
	File* file1 = fopen("entrada.txt", "r");
	File* file2 = fopen("saida.txt", "w");
	char c;
	if (file1 == NULL || file2 == NULL)
		exit(1);

	while ((c = fgetc(file1) != EOF)
		fputc(toupper(c), file2); 
	fclose(file1);
	fclose(file2);
	return 0;
	
}
