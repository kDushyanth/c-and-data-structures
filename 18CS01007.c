#include<stdio.h>
#include<stdlib.h>
void q1()
{
	int n;
	printf("enter n: ");
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=1;j<2*n;j++)
		{
			if(j<=n-i){
			int p='A'+n-j-i;
			printf("%c",p);}
			else if((j>n-i)&&(j<n+i))
			printf(" ");
			else{
			int p='A'+j-n-i;
			printf("%c",p);}
		}
		printf("\n");
	}
}

void merge(int a[],int low,int m1,int m2,int high)
{
	int i=low, j=m1+1, k=m2+1, p=0, b[high-low+1],min;
	while((i!=m1+1)&&(j!=m2+1)&&(k!=high+1))
	{
		int min,c=0;
		if(a[i]<=a[j])
			min = a[i];
		else
		{
			min = a[j];
			c=1;
		}
		if(min<=a[k])
		{
			(c==0)?i++:j++;
		}
		else
		{
			min = a[k++];
		}
			b[p++] = min;
	}
	while((i!=m1+1)&&(j!=m2+1))
	{
		if(a[i]<=a[j])
		b[p++] = a[i++];
		else
		b[p++] = a[j++];
	}
	while((i!=m1+1)&&(k!=high+1))
	{
		if(a[i]<=a[k])
		b[p++] = a[i++];
		else
		b[p++] = a[k++];
	}
	while((k!=high+1)&&(j!=m2+1))
	{
		if(a[j]<=a[k])
		b[p++] = a[j++];
		else
		b[p++] = a[k++];
	} 
	while(i!=m1+1)
	{
		b[p++] = a[i++];
	}
	while(j!=m2+1)
	{
		b[p++] = a[j++];
	}
	while(k!=high+1)
	{
		b[p++] = a[k++];
	}
	for(i=low;i<=high;i++)
	{
		a[i]=b[i-low];
	}
	return;
}

void mergesort(int a[],int low, int high)
{
	if (high ==low+1)
	{
		if(a[low]<a[high])
		return;
		else
		{
		 int temp = a[high];
		 a[high] = a[low];
		 a[low]= temp;
		}
		return;
	}
	else if(low<high)
	{
		int m1 = low+(high-low)/3;
		int m2 = low+2*(high-low)/3;
		mergesort(a,low,m1);
		mergesort(a,m1+1,m2);
		mergesort(a,m2+1,high);
		merge(a,low,m1,m2,high);
	}
	return;
}

void q2()
{
	int n;
	printf("enter the size of array: ");
	scanf("%d",&n);
	int i,a[n];
	printf("enter the elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a, 0, n-1);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int length(char* str)
{
	int i=0;
	while(str[i]!='\0')
	i++;
	return i;
}

void copy(char* s1, char* s2)
{
	int i;
	while(s2[i]!='\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = s2[i];
	return;
}

char* replace(char* sen,char* w1,char* w2,int l)
{
	if(length(w1)==length(w2))
	{
		int i=l;
		while(w2[i-l]!='\0')
		{
			sen[i] = w2[i-l];
			i++;
		}
		return sen;
	}
	else if(length(w2)<length(w1))
	{
		int s = length(w1) - length(w2);
		int i=l;
		while(w2[i-l]!='\0')
		{
			sen[i] = w2[i-l];
			i++;
		}
		while(i+s-1<=length(sen))
		{
			sen[i] = sen[i+s];
			i++;
		}
		sen = (char*)realloc(sen,sizeof(char)*i);
		return sen;
	}
	else 
	{
		int s = length(w2) - length(w1);
		int i = length(sen);
		sen = (char*)realloc(sen,sizeof(char)*(s+i));
		while(i!=l+length(w1)-s)
		{
			sen[i+s]=sen[i];
			i--;
		}
		i=l;
		while(w2[i-l]!='\0')
		{
			sen[i] = w2[i-l];
			i++;
		}
		return sen;
	}
	return sen;
}

char* check(char* sen,char* w1,char* w2,int l)
{
	int i = l;
	while((sen[i]!='\0')&&(w1[i-l]!='\0'))
	{
		if(sen[i]==w1[i-l])
			i++;
		else
		{
		    i=-1;
		    break;
		}
	}
	if(i==-1)
		return sen;
	else if(w1[i-l]=='\0')
		sen = replace(sen, w1, w2, l);
	return sen;
}

void run(char* sen, char* w1,char* w2)
{
	int l = 0;
	while(sen[l]!='\0')
	{
		if(w1[0] == sen[l])
			sen = check(sen,w1,w2,l);
		l++;
	}
	return;
}

void q3()
{
	char str[100];
	printf("enter the sentence: ");
	scanf(" %[^\n]s",str);
	int l=length(str);
	char* sen = (char*)malloc(sizeof(char)*l);
	copy(sen,str);
	printf("enter w1: ");
	scanf("%s",str);
	l = length(str);
	char* w1 = malloc(sizeof(char)*l);
	copy(w1,str);
	printf("enter w2: ");
	scanf("%s",str);
	l = length(str);
	char* w2 = malloc(sizeof(char)*l);
	copy(w2,str);
	run(sen,w1,w2);
	printf("%s\n",sen);
}
int main()
{
	q1();
	q2();
	q3();
}
