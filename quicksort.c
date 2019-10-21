#include<stdio.h>
#include<stdlib.h>
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {srand(time(NULL));
    int x=rand()%(high-low+1)+low;swap(&a[x],&a[high]);
        int pivot = partition(a,low,high);
    quicksort(a,low,pivot-1);
    quicksort(a,pivot+1,high);

    }
}
int partition(int a[],int low,int high)
{int i=low-1;int j;
 for(j=low;j<high;j++)
 {if(a[j]<=a[high])
 {i++;
 swap(&a[i],&a[j]);
 }
 }i++;
 swap(&a[i],&a[j]);
 return i;


}
void swap(int *a,int *b)
{int temp;
temp=*a;
*a=*b;
*b=temp;


}
int main()
{int n;scanf("%d",&n);
int a[n],i;
for(i=0;i<n;i++)scanf("%d",&a[i]);
quicksort(a,0,n-1);
for(i=0;i<n;i++)printf("%d",a[i]);
return 0;

}
