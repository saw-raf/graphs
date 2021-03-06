#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,m,i,j,a,b;
	int **A;

	puts("Podaj l. wierzcholkow:");
	scanf("%d",&n);
	puts("Podaj l. krawedzi");
	scanf("%d",&m);

	A=(int**)malloc(n*sizeof(int*));
	for(i=0;i<m;i++)
		A[i]=(int*)malloc(m*sizeof(int));

	for(i=0;i<m;i++)//zapisywanie krawedzi
	{
		puts("Podaj krawedz:");
		scanf("%d %d",&a,&b);
		A[a][i]=1;
		A[b][i]=-1;
	}

	printf("\n     ");//wyswietlanie macierzy
	for(i=0;i<m;i++)
		printf("%4d ",i);
	puts("");
	for(i=0;i<n;i++)
	{
		printf("%4d ",i);
		for(j=0;j<m;j++)
			printf("%4d ",A[i][j]);
		puts("");
	}


	for(i=0;i<n;i++)//wyswietlanie sasiadow
	{
		printf("Dla wierzcholka {%d} sasiadami sa: ",i);
		for(j=0;j<m;j++)
		{
			if(A[i][j]==1)
			{
				for(int k=0;k<n;k++)
					if(A[k][j]==-1)
						printf("%d ",k);
			}
		}
		puts("");
	}
	for(i=0;i<n;i++)//wyswietlanie sasiadow
	{
		printf("Podwojne krawedzie to: ");
		for(j=0;j<m;j++)
		{
			if(A[i][j]==1)
			{
				int wiersz;
				for(int k=0;k<n;k++)
					if(A[k][j]==-1)
						wiersz=k;

				for(int l=0;l<m;l++)
					if(A[i][l]==-1)
						if(A[wiersz][l]==1)
							printf("%d %d\n",j,l);
			}
		}
		puts("");
	}


	for(i=0;i<n;i++)//wyswietlanie dla kogo jest sasaidem
	{
		printf("Wierzcholek {%d} jest sasiadem dla: ",i);
		for(j=0;j<m;j++)
		{
			if(A[i][j]==-1)
			{
				for(int k=0;k<n;k++)
					if(A[k][j]==1)
						printf("%d ",k);
			}
		}
		puts("");
	}

	for(i=0;i<n;i++)//czy wierzcholek jest izolowany
	{
		int checker=1;
		j=0;
		while(j<m && checker==1)
		{
			if(A[i][j]!=0)
				checker=0;
			j++;
		}
		if(checker==1)
			printf("!!! Wierzcholek {%d} jest izolowany\n",i);
	}
	return 0;
}
