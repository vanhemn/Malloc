#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* main pour faire des test */
int main(void) {
	int* a = malloc(10);
	free(a);
	int* b = malloc(1250000);
	free(b);
	int* c = malloc(10);
	free(c);
	int* D = malloc(10);
	free(D);
}