#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
char data;
struct node* next;}
node;
typedef struct stack{
node* top;}stack;
stack* init()
{
stack* s=(stack*)malloc(sizeof(node));
s->top=NULL;
return s;
}
void push(stack*s,char x)
{
node*p=(node*)malloc(sizeof(node));
p->data=x;
p->next=s->top;
s->top=p;
}
void pop(stack* s)
{
node*p= s->top;
if(s->top!=NULL)
{
s->top=p->next;
free(p);
}
}

int main()
{
    char temp[200];
    scanf("%s",&temp);
    int linf,c=-1,i;
    linf = strlen(temp);
    char inf[linf],pfix[linf];
    strcpy(inf,temp);
    stack*s=init();
    for(i=0;i<linf;i++)
    {
        if(('a'<=inf[i])&&(inf[i]<='z'))
        {
           c++;
           pfix[c]=inf[i];
        }
        else if(inf[i]=='(')
        {
            push(s,inf[i]);
        }
        else if(inf[i]==')')
        {
            while(s->top->data!='(')
            {
                c++;
                pfix[c]=s->top->data;
                pop(s);
            }
            pop(s);
        }
        else
        {
           if((inf[i]=='+')||(inf[i]=='-'))
            {
                while(s->top!=NULL)
                {
                    if(s->top->data=='(')
                        break;
                    else
                    {
                        c++;
                        pfix[c]=s->top->data;
                        pop(s);
                    }
                }
                push(s,inf[i]);
            }
        else if((inf[i]=='*')||(inf[i]=='/'))
            {
                while(s->top!=NULL)
                {
                    if((s->top->data=='(')||(s->top->data=='+')||(s->top->data=='-'))
                        break;
                    else
                    {
                        c++;
                        pfix[c]=s->top->data;
                        pop(s);
                    }
                }
                push(s,inf[i]);
            }
        }
    }
    while(s->top!=NULL)
    {
        c++;
        pfix[c]=s->top->data;
        pop(s);
    }
    printf("%s",pfix);
    return 1;
}
