/**********************************
* PROGRAM ADJACENCY MATRIX
* WCZYTUJE DANE O GRAFIE
* I ZAPISUJE JE W POSTACI
* MACIERZY SASIEDZTWA
***********************************/

#include <stdio.h>
#include <stdlib.h>

void showNeighbors(int,int);

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

	for(j=0;j<n;j++)//wypisywanie sasiadow wszystkich wierzcholkow
	{
		printf("Sasiadami wierzcholka {%d}  sa:\n",j);
		for(i=0;i<n;i++)
			if(A[j][i]==1)
				printf("%3d ",i);
		puts("");
	}

	for(i=0;i<n;i++)//dany wierzcholek jest sasiadem dla
	{
		printf("Wierzcholek {%d} jest sasiadem dla:\n",i);
		for(j=0;j<n;j++)
			if(A[j][i]==1)
				printf("%3d",j);
		puts("");
	}

	for(i=0;i<n;i++)//wynaczanie stopni wchodzacych i wychodzacych
	{
		int indeg=0,outdeg=0;
		for(j=0;j<n;j++)
		{
			if(A[i][j]==1)
				outdeg++;
			if(A[j][i]==1)
				indeg++;
		}
		printf("Dla wierzcholka {%d} stopien wychodzacy to: %d , wchodzacy to: %d\n",i,outdeg,indeg);
		if(indeg==0 && outdeg==0)
			printf("Wierzcholek {%d} jest izolowany!!!\n",i);
	}

	for(i=0;i<n;i++)//wyznaczamy petle
		if(A[i][i]==1)
			printf("Wierzcholek {%d} ma petle\n",i);

	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			if(j!=i && A[j][i]==1 && A[i][j]==1)
				printf("Jest krawedz dwukierunkowa miedzy wierz {%d} a {%d}. \n",i,j);
	return 0;
}


