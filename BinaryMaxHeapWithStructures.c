#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NMAX 15
int c = 0;
void swap(int A[][NMAX], int i, int j)
{
	int temp;
	temp = A[1][i];
	A[1][i] = A[1][j];
	A[1][j] = temp;
	temp = A[0][i];
	A[0][i] = A[0][j];
	A[0][j] = temp;
}

void movedown(int A[][NMAX], int n, int i)
{
	int max = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l < n && A[1][l] > A[1][max])
		max = l;
	if(r < n && A[1][r] > A[1][max])
		max = r;
	if(max != i) {
		swap(A, i, max);
		movedown(A, n, max);
	}
}

void moveup(int A[][NMAX], int i)
{
	int p = (i-1)/2;
	if(p >= 0 && A[1][i] > A[1][p]) 
	{
		swap(A, i, p);
		moveup(A, p);
	}
}

void makeHeap(int A[][NMAX], int n)
{
	for(int i = (n-2)/2; i >= 0; i--)
		movedown(A, n, i);
}

void initIndex(int A[][NMAX], int IDX[NMAX])
{
	for(int i = 0; i < c; i++)
	{
		IDX[A[0][i]] = i;
	}
}

void Upvote(int A[][NMAX], int IDX[NMAX], int z)
{
	A[1][IDX[z]]++;
	moveup(A, IDX[z]);
	initIndex(A, IDX);
}

void Downvote(int A[][NMAX], int IDX[NMAX], int z, int n)
{
	if(A[1][IDX[z]]>0)
	{
		A[1][IDX[z]]--;
		movedown(A, n, IDX[z]);
		initIndex(A, IDX);
	}
}

void Insert(int A[][NMAX], int IDX[NMAX], int* n, int key)
{
	if(c!=NMAX)
	{
		A[0][(*n)] = c;
		A[1][(*n)] = key;
		(*n)++;
		c++;
		moveup(A, (*n)-1);
		initIndex(A, IDX);
	}
}

void Delete(int A[][NMAX], int IDX[NMAX],int* n, int z)
{
	swap(A, (*n)-1, IDX[z]);
	(*n)--;
	movedown(A, *n, IDX[z]);
	initIndex(A, IDX);
	IDX[z] = -1;
}

int main()
{
	int ninit,A[2][NMAX];
	printf("ninit(< %d): ",NMAX);
	scanf("%d",&ninit);
	c += ninit;
/*filling A with ninit elements*/
	srand(time(0));
	for(int i = 0; i < ninit; i++)
	{
		A[0][i] = i;
		A[1][i] = rand()%NMAX+1;
	}
	printf("Array:   ");
	for(int i = 0; i < ninit; i++)
	{
		printf("(%d,%d) ",A[0][i],A[1][i]);
	}
	printf("\n");
/*making the array a max heap*/
	makeHeap(A,ninit);
	printf("maxHeap: ");
	for(int i = 0; i < ninit; i++)
	{
		printf("(%d,%d) ",A[0][i],A[1][i]);
	}
	printf("\n");
/*preparing the IDX array*/
	int IDX[NMAX];
	for(int i = 0; i < c; i++)
	{
		IDX[i] = -1;
	}
	initIndex(A,IDX);
	printf("IDX array: ");
	for(int i = 0; i < c; i++)
	{
		printf("%d->%d ",i,IDX[i]);
	}
	printf("\n");
	while(1)
	{
		int key;
		printf("Enter '1' for 'Insertion'.\nEnter '2' for 'Upvoting'.\nEnter '3' for 'Downvoting'.\nEnter '4' for 'Deletion'\nEnter '5' to 'Quit'\n");
		printf("Response: ");
		scanf("%d",&key);
		if(key==5)
			break;
		else if(key==4)
		{
			int z;
			printf("Enter ID: ");
			scanf("%d",&z);
			Delete(A, IDX, &ninit, z);
		}
		else if(key==3)
		{
			int z;
			printf("Enter ID: ");
			scanf("%d",&z);
			Downvote(A, IDX, z, ninit);
		}
		else if(key==2)
		{
			int z;
			printf("Enter ID: ");
			scanf("%d",&z);
			Upvote(A, IDX, z);
		}
		else if(key==1)
		{
			int z;
			printf("Enter the Element: ");
			scanf("%d",&z);
			Insert(A, IDX, &ninit, z);
		}
		printf("Current Array:   ");
		for(int i = 0; i < ninit; i++)
		{
			printf("(%d,%d) ",A[0][i],A[1][i]);
		}
		printf("\n");
		printf("IDX array: ");
		for(int i = 0; i < c; i++)
		{
			printf("%d->%d ",i,IDX[i]);
		}
		printf("\n");
	}
}


















