/**********************************
* PROGRAM ADJACENCY MATRIX
* WCZYTUJE DANE O GRAFIE
* I ZAPISUJE JE W POSTACI
* MACIERZY SASIEDZTWA
***********************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m,i,j,a,b;
	char **A;//macierz sasiedztwa

	puts("Podaj liczbe wierzcholkow: ");
	scanf("%d",&n);
	puts("Podaj liczbe krawedzi: ");
	scanf("%d",&m);

	A=(char**)malloc(n*sizeof(char*));//alokacja macierzy nxn
	for(i=0;i<n;i++)
		A[i]=(char*)malloc(n*sizeof(char));

	for(i=0;i<n;i++)//zerowanie macierzy
		for(j=0;j<n;j++)
			A[i][j]=0;

	for(i=0;i<m;i++) //zapisanie krawedzi
	{
		puts("Podaj krawedz: ");
		scanf("%d %d",&a,&b);
		A[a][b]=1;
		A[b][a]=1;
	}
	printf("   ");//wypisywanie macierzy
	for(i=0;i<n;i++)
		printf("%3d",i);
	puts("");
	for(i=0;i<n;i++)
	{
		printf("%3d",i);
		for(j=0;j<n;j++)
			printf("%3d",(int)A[i][j]);
		puts("");
	}

	for(i=0;i<n;i++)//wypisywanie stopnia wierzcholka
	{
		int stopien=0;
		for(j=0;j<n;j++)
			if(A[i][j]==1)
				stopien++;
		if(A[i][i]==1)//przypadek gdy mamy petle
			stopien++;
		printf("Wierzcholek {%d} ma stopien: %d\n",i,stopien);
	}
	return 0;
}


