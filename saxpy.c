// Práctica 1
// Laparra Miranda Sandra
// Hernández Hernández Cristian

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

void get_walltime(double* weTime){
	struct timeval tp;
	gettimeofday(&tp, NULL);
	*weTime=(tp.tv_sec + tp.tv_usec/1000000.0);
}

int main(int argc, char* argv[]){
	int i, j, k, n=1000;
	int **matrizA, **matrizB, **matrizC;
	double S1, E1;

	//Inicializando matrices
	matrizA = (int **)malloc(n*sizeof(int *));
	for(i=0; i<n; i++){
		*(matrizA+i) = (int *)malloc(n*sizeof(int));
	}

	matrizB = (int **)malloc(n*sizeof(int *));
	for(i=0; i<n; i++){
		*(matrizB+i) = (int *)malloc(n*sizeof(int));
	}

	matrizC = (int **)malloc(n*sizeof(int *));
	for(i=0; i<n; i++){
		*(matrizC+i) = (int *)malloc(n*sizeof(int));
	}

	//Llenando de matrices
	for(i=0; i<n; ++i)
	{
		for(j=0; j<n; ++j)
		{
			matrizA[i][j] = rand() % 6;
		}
	}

	for(i=0; i<n; ++i)
	{
		for(j=0; j<n; ++j)
		{
			matrizB[i][j] = rand() % 6;
		}
	}

    // Método(1) i j k
	get_walltime(&S1);

	for(i=0; i<n; ++i)
	{
		for(j=0;j<n; ++j)
		{
			for(k=0; k<n; ++k)
			{
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);
        
        printf(" Tamaño de matriz %d*%d",n,n);
	printf("\n Tiempo método ijk: %f s\n", (E1-S1));
	
	
	// Método(2) i k j
	get_walltime(&S1);

	for(i=0; i<n; ++i)
	{
		for(k=0;k<n; ++k)
		{
			for(j=0; j<n; ++j)
			{
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);
        
    printf("\n Tamaño de matriz %d*%d",n,n);
	printf("\n Tiempo método ikj: %f s\n", (E1-S1));
	
	// Método(3) k i j
	get_walltime(&S1);

	for(k=0; k<n; ++k)
	{
		for(i=0;i<n; ++i)
		{
			for(j=0; j<n; ++j)
			{
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);
        
    printf("\n Tamaño de matriz %d*%d",n,n);
	printf("\n Tiempo método kij: %f s\n", (E1-S1));
	
	// Método(4) k j i
	get_walltime(&S1);

	for(k=0; k<n; ++k)
	{
		for(j=0;j<n; ++j)
		{
			for(i=0; i<n; ++i)
			{
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);
        
    printf("\n Tamaño de matriz %d*%d",n,n);
	printf("\n Tiempo método kji: %f s\n", (E1-S1));


	// Método(5) j k i
	get_walltime(&S1);

	for(j=0; j<n; ++j)
	{
		for(k=0;k<n; ++k)
		{
			for(i=0; i<n; ++i)
			{
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);
        
    printf("\n Tamaño de matriz %d*%d",n,n);
	printf("\n Tiempo método jki: %f s\n", (E1-S1));

	// Método(5) j i k
	get_walltime(&S1);

	for(j=0; j<n; ++j)
	{
		for(i=0;i<n; ++i)
		{
			for(k=0; k<n; ++k)
			{
				matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
			}
		}
	}
	get_walltime(&E1);
        
    printf("\n Tamaño de matriz %d*%d",n,n);
	printf("\n Tiempo método jik: %f s\n", (E1-S1));
	
	return 0;
}
