#include<stdlib.h>
#include<stdio.h>
#include<math.h>

typedef struct {
	int arr[4]; // n x y z
}norm;
typedef struct{
	int endind;
	norm* n;
} polynominal;

void init(polynominal* P) {
	P->n = (norm*)malloc(sizeof(norm));
	P->endind = 0;
}
void push(polynominal* P, char* arr, int v) {
	P->n = (norm*)realloc(P->n, sizeof(norm) * ((P->endind) + 1));
	P->n[P->endind].arr[0] = v;
	for (int i = 1; i < 4; i++)
		P->n[P->endind].arr[i] = ((int)arr[i-1] - '0');
	P->endind++;
}
void multyPoly(int FPol, int SPol, int TPol, polynominal* Parr) {
	for (int i = FPol; i < SPol; i++) {
		for (int j = SPol; j < TPol; j++) {
			int tmpv = Parr->n[i].arr[0] * Parr->n[j].arr[0];
			int tmpx = Parr->n[i].arr[1] + Parr->n[j].arr[1];
			int tmpy = Parr->n[i].arr[2] + Parr->n[j].arr[2];
			int tmpz = Parr->n[i].arr[3] + Parr->n[j].arr[3];
			int key = 1;
			for (int k = TPol; k < Parr->endind; k++) {
				if (tmpx == Parr->n[k].arr[1] && tmpy == Parr->n[k].arr[2] && tmpz == Parr->n[k].arr[3]) {
					key = 0;
					Parr->n[k].arr[0] += tmpv;
					break;
				}
			}
			if (key) {
				char arr[4];
				arr[0] = tmpx + '0';
				arr[1] = tmpy + '0';
				arr[2] = tmpz + '0';
				arr[3] = 0;
				push(Parr, arr, tmpv);
			}
		}
	}
}
int static compare(const void* x, const void* y) {
	if (((norm*)x)->arr[2] != ((norm*)y)->arr[2])
		return -(((norm*)x)->arr[2] - ((norm*)y)->arr[2]);
	else if (((norm*)x)->arr[1] != ((norm*)y)->arr[1])
		return -(((norm*)x)->arr[1] - ((norm*)y)->arr[1]);
	else if (((norm*)x)->arr[3] != ((norm*)y)->arr[3])
		return -(((norm*)x)->arr[3] - ((norm*)y)->arr[3]);
	else
		return 0;
}
void printfunc(int s, polynominal* P) {
	for (int i = s; i < P->endind; i++) {
		if (P->n[i].arr[0]==0)continue;

		if (i != s && P->n[i].arr[0] > 0)
			printf(" + %d", P->n[i].arr[0]);
		else if (i != s && P->n[i].arr[0] < 0)
			printf(" - %d", P->n[i].arr[0]*-1);
		else
			printf("%d", P->n[i].arr[0]);

		int key = 0;

		if (P->n[i].arr[1]) {
			if (key)printf("*");
			printf("x^%d", P->n[i].arr[1]);
			key = 1;
		}
		if (P->n[i].arr[2]) {
			if (key)printf("*");
			printf("y^%d", P->n[i].arr[2]);
			key = 1;
		}
		if (P->n[i].arr[3]) {
			if (key)printf("*");
			printf("z^%d", P->n[i].arr[3]);
			key = 1;
		}
	}
	printf("\n");
}

int main(void) {
	polynominal Parr;
	//1st
	init(&Parr);
	int FPol = 0;
	int SPol = 3;
	int TPol = 6;
	push(&Parr, "070", 3);
	push(&Parr, "400", 4);
	push(&Parr, "000", -1);
	push(&Parr, "400", 5);
	push(&Parr, "020", -3);
	push(&Parr, "000", 7);
	qsort(Parr.n + FPol, SPol - FPol, sizeof(norm), compare);
	qsort(Parr.n + SPol, TPol - SPol, sizeof(norm), compare);
	multyPoly(FPol, SPol, TPol, &Parr);
	qsort(Parr.n + TPol, Parr.endind - TPol, sizeof(norm), compare);
	printf("#1\n");
	printfunc(TPol, &Parr);
	free(Parr.n);
	
	//2nd
	init(&Parr);
	FPol = 0;
	SPol = 3;
	TPol = 6;
	push(&Parr, "070", 4);
	push(&Parr, "400", -4);
	push(&Parr, "000", -1);
	push(&Parr, "070", 2);
	push(&Parr, "100", -3);
	push(&Parr, "000", 1);
	qsort(Parr.n + FPol, SPol - FPol, sizeof(norm), compare);
	qsort(Parr.n + SPol, TPol - SPol, sizeof(norm), compare);
	multyPoly(FPol, SPol, TPol, &Parr);
	qsort(Parr.n + TPol, Parr.endind - TPol, sizeof(norm), compare);
	printf("#2\n");
	printfunc(TPol, &Parr);
	free(Parr.n);

	//3rd
	init(&Parr);
	FPol = 0;
	SPol = 4;
	TPol = 8;
	push(&Parr, "470", 15);
	push(&Parr, "090", -9);
	push(&Parr, "070", 21);
	push(&Parr, "800", 20);
	push(&Parr, "420", -12);
	push(&Parr, "400", 23);
	push(&Parr, "020", 3);
	push(&Parr, "000", -7);
	qsort(Parr.n + FPol, SPol - FPol, sizeof(norm), compare);
	qsort(Parr.n + SPol, TPol - SPol, sizeof(norm), compare);
	multyPoly(FPol, SPol, TPol, &Parr);
	qsort(Parr.n + TPol, Parr.endind - TPol, sizeof(norm), compare);
	printf("#3\n");
	printfunc(TPol, &Parr);
	free(Parr.n);

	//4th
	init(&Parr);
	FPol = 0;
	SPol = 4;
	TPol = 8;
	push(&Parr, "473", 90);
	push(&Parr, "092", -9);
	push(&Parr, "070", 21);
	push(&Parr, "800", 20);
	push(&Parr, "422", -12);
	push(&Parr, "400", 23);
	push(&Parr, "020", 3);
	push(&Parr, "000", -7);
	qsort(Parr.n + FPol, SPol - FPol, sizeof(norm), compare);
	qsort(Parr.n + SPol, TPol - SPol, sizeof(norm), compare);
	multyPoly(FPol, SPol, TPol, &Parr);
	qsort(Parr.n + TPol, Parr.endind - TPol, sizeof(norm), compare);
	printf("#4\n");
	printfunc(TPol, &Parr);
	free(Parr.n);

	
	/*for (int i = TPol; i < Parr.endind; i++) {
		printf("%d %d %d %d \n", Parr.n[i].arr[0], Parr.n[i].arr[1], Parr.n[i].arr[2], Parr.n[i].arr[3]);
	}*/
}
