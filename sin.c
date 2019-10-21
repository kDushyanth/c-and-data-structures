#include<stdio.h>
#include<math.h>
float func(float x,int n)
{int key=fact(n);
    float ans=pow(x,n)/key;return ans;
}
int fact(int n)
{if(n==1 ||n==0)return 1;
    int fac=1,fac1=1;
while(n>1)
{fac=fac1*n*(n-1);
    fac1=fac;n=n-2;
}
}
int main()
{float x;
scanf("%f",&x);int n=1;
x=x*.0175;float sin=0;int count=1;float re=func(x,n);
while(re>pow(10,-5))
{if(count%2==1)
   {
       sin=sin+func(x,n);
        n=n+2;re=func(x,n);
  }
  else
  {
      sin=sin-func(x,n);
      n=n+2;re=func(x,n);
  }
}
    printf("%f",sin);
}

