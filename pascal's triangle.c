#include<stdio.h>
int comb(int i,int j);
int fact(int n);
int main()
{
    int n;
    scanf("%d",&n);int key;
    int i,j,a;
    for(i=0;i<n;i++)
    {for(a=n-i-1;a>0;a--)
        {
        printf(" ");
        }
        for(j=0;j<=i;j++)
        {
           key=comb(i,j);printf("%d ",key);
        }
        printf("\n");
    }
    return 0;
}
int comb(int i,int j)
{int ans1=fact(i),ans2=fact(j),ans3=fact(i-j);
    int ans=ans1/(ans2*ans3);
    return ans;
}
int fact(int n)
{if (n==0 || n==1)
  return 1;
  else
  {
    int fac=1,fac1=1;
    while(n>1)
    {
    fac=fac1*n*(n-1);
    fac1=fac;n=n-2;
    }
    return fac;
  }
}








