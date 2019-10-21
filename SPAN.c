#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
typedef struct stack
{
    node *top;
}stack;
stack *init()
{
    stack *t=(stack *)malloc(sizeof(stack));
    t->top=NULL;
    return t;
}
stack *push(stack *s,int x)
{
    node *p=(node *)malloc(sizeof(node));
    p->data=x;
    p->next=s->top;
    s->top=p;
    return s;
}
stack *pop(stack *s)
{
    node *p=s->top;
    if(p==NULL)return s;
    s->top=s->top->next;
    free(p);
    return s;
}
int main()
{int n;stack *s=init();
scanf("%d",&n);
int price[n],k,span[n],i;
for(i=0;i<n;i++)
{
    scanf("%d",&price[i]);
}
span[0]=1;
s=push(s,0);
for(i=1,k=1;i<n;i++,k++)
{
    if(price[i]< price[s->top->data] )
    {
        s=push(s,i);span[k]=1;
    }
    else
        {
            while(s->top!=NULL)
            {if(price[i] > price[s->top->data])
                s=pop(s);
                else
                    break;

            }
            if(s->top!=NULL)
           {
               s=push(s,i);span[k]=(s->top->data)- (s->top->next->data);
           }
           else
           {span[k]=i+1;s=push(s,i);}
        }
}

    for(i=0;i<n;i++)
{
    printf("%d",span[i]);
}
}


