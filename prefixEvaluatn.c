#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size 20
int top = -1;
int stack[size];

int pop()
{
    int n;
    if(top == -1)
    {
        printf("stack Underflow\n");
    }
    else 
    {
       return stack[top--];
    }
}
void push(int n)
{
    if(top == size)
    {
      printf("stack Overflow\n");
    }
    else 
    {
        ++top;
        stack[top] = n;
    }
}
void evaluate(char postfix[])
{
    int i,A,B,value;
    for(i = 0; postfix[i] != ')'; i++)
    {
       if(isdigit(postfix[i]))
       {
        int pass;
        pass = postfix[i] - 48;
        push(pass);
       }
       else if(postfix[i] == '+'||postfix[i] == '/'||postfix[i] == '-'||postfix[i] == '*')
        { 
          A = pop();
          B = pop();
          switch(postfix[i])
          {
            case '+':
                value = B + A;
                break;

            case'-':
                value = B - A;
                break;

            case'*':
                value = B * A;
                break;

            case '/':
                value = B / A;
                break;    
          }
          push(value);
        }
    }
    printf("Result = %d",stack[top]);
}
int main()
{
    char postfix[size];
    char prefix[size];
    int i,j;
    printf("Enter the value :\n");
    for(i = 0; i < size; i++)
    {
        scanf("%c",&prefix[i]);
        if(prefix[i] == ')')
        {
            break;
        }
    }
    for(i = 0; prefix[i] != ')'; i++);
    postfix[i] = ')';
    i-=2;
    j=0;
    while(prefix[j] != ')')
    {
       postfix[i] = prefix[j];
       i-=2;
       j+=2;
    }
    evaluate(postfix);
    return 0;
}