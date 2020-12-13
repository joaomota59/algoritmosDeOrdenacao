//Alunos: Francisco Guilherme e João Lucas
#include <stdio.h>//Entrada e Saída
#include <stdlib.h>//Uso do Malloc e free (Alocação Dinâmica) / limpa tela 
#include <time.h>//Uso para o tempo de execução
#include <string.h>

//Funções
void bubbleSort(double A[]);
void insertionSort(double A[]);
void mergeSort(double A[], int p, int r);
void heapSort(double A[]);
void quickSort(double A[], int p, int r);
void crescente(double A[]);
void decrescente(double A[]);
void aleatorio(double A[]);

//var global
int tam_vet;
int tamanhoDoHeap;
long long int cont = 0;

int main(void)
{
	clock_t t; //variável para armazenar tempo
	int comprimentos[9] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000};
	int k, m, selecionado;
	int  flag; //0-false 1-true
	char str1[600];
	while(1)
	{
		system("cls");
		printf("Selecione o algoritmo que deve ser executado!\n[1-BubbleSort 2-InsertionSort 3-MergeSort]\n[4-HeapSort   5-QuickSort     {0-Sair}   ]\n->");
		scanf("%d", &selecionado);
		if (selecionado != 1 && selecionado != 2 && selecionado != 3 && selecionado != 4 && selecionado != 5)
			break;
		printf("Aguarde, Executando!\n");
		FILE *arq, *arq2; // criando a variável ponteiro para o arquivo
		arq = fopen("testes.txt", "a");
		arq2 = fopen("comparacoes.txt", "a");

		if(arq == NULL || arq2 == NULL) //testando se o arquivo foi realmente criado
		{
			printf("Erro na abertura do arquivo!");
			return 1;
		}
		fclose(arq2);
		flag = 0;
		
		arq2 = fopen("comparacoes.txt", "r");
		if(selecionado == 1)
		{
			fprintf(arq, "BUBBLESORT\n");
			char palavra[15] = "BUBBLESORT";
			while((fscanf(arq2, "%s\n", &str1)) != EOF)
			{
					if( (strcmp(palavra, str1)) == 0)
					{
						flag = 1;
						break;
					}
			}
			if(flag == 0)
			{
				fclose(arq2);
				arq2 = fopen("comparacoes.txt", "a");
				fprintf(arq2, "BUBBLESORT\n");

			}
		}
		else if(selecionado == 2)
		{
			fprintf(arq, "INSERTIONSORT\n");
			char palavra[15] = "INSERTIONSORT";
			while((fscanf(arq2, "%s\n", &str1)) != EOF)
			{
				
				if( (strcmp(palavra, str1)) == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				fclose(arq2);
				arq2 = fopen("comparacoes.txt", "a");
				fprintf(arq2, "INSERTIONSORT\n");
			}
		}
		else if(selecionado == 3)
		{
			fprintf(arq, "MERGESORT\n");
			char palavra[15] = "MERGESORT";
			while((fscanf(arq2, "%s\n", &str1)) != EOF)
			{
				
				if( (strcmp(palavra, str1)) == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				fclose(arq2);
				arq2 = fopen("comparacoes.txt", "a");
				fprintf(arq2, "MERGESORT\n");

			}
		}
		else if(selecionado == 4)
		{
			fprintf(arq, "HEAPSORT\n");
			char palavra[15] = "HEAPSORT";
			while((fscanf(arq2, "%s\n", &str1)) != EOF)
			{
				
				if( (strcmp(palavra, str1)) == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				fclose(arq2);
				arq2 = fopen("comparacoes.txt", "a");
				fprintf(arq2, "HEAPSORT\n");
			}
		}
		else
		{
			fprintf(arq, "QUICKSORT\n");
			char palavra[15] = "QUICKSORT";
			while((fscanf(arq2, "%s\n", &str1)) != EOF)
			{
				if((strcmp(palavra, str1)) == 0) //se encontrou
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				fclose(arq2);
				arq2 = fopen("comparacoes.txt", "a");
				fprintf(arq2, "QUICKSORT\n");
			}
		}

		for(m = 0; m < 3; m++)
		{
			for (k = 0; k < 9; k++)
			{
				tam_vet = comprimentos[k];
				double *a = (double *) malloc(tam_vet * sizeof(double));//alocando memória p o vetor
				if (a == NULL)
				{
					printf("Memoria insuficiente.\n");
					exit(1); /* aborta o programa e retorna 1 para o sist. operacional */
				}
				if(m == 0)
					crescente(a);
				else if(m == 1)
					decrescente(a);
				else
					aleatorio(a);
				cont = 0;
				if(selecionado == 1)
				{
					t = clock(); //armazena tempo
					bubbleSort(a);
					t = clock() - t; //tempo final - tempo inicial
					fprintf(arq, "%lf", ((double)t) / ((CLOCKS_PER_SEC)));
					if(flag == 0)
						fprintf(arq2, "%lld", cont);

				}
				else if(selecionado == 2)
				{
					t = clock();
					insertionSort(a);
					t = clock() - t;
					fprintf(arq, "%lf", ((double)t) / ((CLOCKS_PER_SEC)));
					if(flag == 0)
						fprintf(arq2, "%lld", cont);
				}
				else if(selecionado == 3)
				{
					t = clock();
					mergeSort(a, 0, tam_vet - 1);
					t = clock() - t;
					fprintf(arq, "%lf", ((double)t) / ((CLOCKS_PER_SEC)));
					if(flag == 0)
						fprintf(arq2, "%lld", cont);
				}
				else if(selecionado == 4)
				{
					t = clock();
					heapSort(a);
					t = clock() - t;
					fprintf(arq, "%lf", ((double)t) / ((CLOCKS_PER_SEC)));
					if(flag == 0)
						fprintf(arq2, "%lld", cont);
				}
				else
				{
					t = clock();
					quickSort(a, 0, tam_vet - 1);
					t = clock() - t;
					fprintf(arq, "%lf", ((double)t) / ((CLOCKS_PER_SEC)));
					if(flag == 0)
						fprintf(arq2, "%lld", cont);
				}
				fprintf(arq, ";");
				fprintf(arq2, ";");
				free(a);//libera memória
			}
		}
		fprintf(arq, "\n");
		fprintf(arq2, "\n");
		fclose(arq);
		fclose(arq2);
	}
	return 0;
}

//Funções

void trocar(double * a, double * b)
{
	double aux = * a;
	* a = * b;
	* b = aux;
}

void crescente(double A[])
{
	int i;
	for(i = 0; i < tam_vet; i++) //vetor em ordem crescente
		A[i] = i+1;
}
void decrescente(double A[])
{
	int i;
	for (i = 0; i < tam_vet; i++) //vetor em ordem decrescente
		A[i] = tam_vet - i;
}
void aleatorio(double A[])
{
	int i;
	for(i = 0; i < tam_vet; i++) //adiciona elementos aleatórios ao vetor
		A[i] = rand() % 200000;
}


///MergeSort
void merge(double A[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 =  r - q;

	/* criação de arrays temporários */
	double L[n1], R[n2];

	/* Copiando os dados para os arrays temporários L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = A[p + i];
	for (j = 0; j < n2; j++)
		R[j] = A[q + j + 1];

	L[n1] = 2147483647; //valor muito grande corresponde ao infinito
	R[n2] = 2147483647;

	i = 0;// vetor começa do zero ja no livro é 1 porque começa do 1
	j = 0;
	for(k = p; k <= r; k++)
	{
		cont++;
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i = i + 1;
		}
		else
		{
			A[k] = R[j];
			j = j + 1;
		}
	}
}


void mergeSort(double A[], int p, int r)
{
	cont++;
	if (p < r)
	{
		int q = (p + r) / 2;
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);
		merge(A, p, q, r);
	}
}


void insertionSort(double A[])
{
	int i, j;
	double chave;
	for (j = 1; j < tam_vet; j++)
	{
		chave = A[j];
		i = j - 1;
		cont++;
		while (i >= 0 && A[i] > chave)
		{
			A[i + 1] = A[i];
			i = i - 1;
		}
		A[i + 1] = chave;
	}
}


///QUICKSORT
void quickSort(double A[], int p, int r)
{
	int i, j;
	double x;
	i = p;
	j = r;
	x = A[(p + r) / 2];
	while (i <= j)
	{
		cont++;
		while (A[i] < x)
		{
			i = i + 1;
			cont++;
		}
		cont++;
		while (A[j] > x)
		{
			j = j - 1;
			cont++;
		}
		if (i <= j)
		{
			trocar(&A[i], &A[j]);
			i = i + 1;
			j = j - 1;
		}
	}
	if (p < j)
		quickSort(A, p, j);
	if (r > i)
		quickSort(A, i, r);
}

///BUBBLESORT
void bubbleSort(double A[])
{
	int i, j;
	for (i = 0; i < tam_vet; i++)
	{
		for (j = tam_vet - 1; j >= i + 1; j--)
		{	
			cont++;
			if (A[j] < A[j - 1]){
				trocar(&A[j], &A[j - 1]);
				}
		}
	}
}



//HEAPSORT

int parent(int i)
{
	return i / 2;
}
int left(int i)
{
	return 2 * i;
}
int right(int i)
{
	return 2 * i + 1;
}

void maxHeapify(double A[], int i)
{
	int l, r, maior;
	l = left(i);
	r = right(i);
	cont++;
	if ((l < tamanhoDoHeap) && (A[l] > A[i]))
		maior = l;
	else
		maior = i;
	cont++;
	if ((r < tamanhoDoHeap) && (A[r] > A[maior]))
		maior = r;
	cont++;
	if(maior != i)
	{
		trocar(&A[i], &A[maior]);
		maxHeapify(A, maior);
	}

}

void buildMaxHeap(double A[])
{
	int i;
	tamanhoDoHeap = tam_vet;
	for(i = tam_vet / 2; i >= 0; i--)
		maxHeapify(A, i);
}

void heapSort(double A[])
{
	int i;
	buildMaxHeap(A);
	for(i = tam_vet - 1; i >= 1; i--)
	{
		trocar(&A[0], &A[i]);
		tamanhoDoHeap = tamanhoDoHeap - 1;
		maxHeapify(A, 0); //vetor começa do zero!
	}
}

