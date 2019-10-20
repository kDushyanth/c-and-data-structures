#include<stdio.h>
void merge(int A[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=0,B[high-low+1];
    while((i!=mid+1)&&(j!=high+1))
    {
        if(A[i]<=A[j])
            B[k++]=A[i++];
        else
            B[k++]=A[j++];
//For inversions add a global variable 'c' and just below the above else add "c += mid-i;"
    }
    while(i!=mid+1)
        B[k++]=A[i++];
    while(j!=high+1)
        B[k++]=A[j++];
    for(i=low;i<=high;i++)
    {
        A[i]=B[i-low];
    }
}
void mergesort(int A[], int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}
int main()
{
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    int i,A[n];
    printf("Enter the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    mergesort(A,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
printf("\n");
}
