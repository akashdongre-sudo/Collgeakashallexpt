#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

char st[MAX];
int top = -1;

void push(char);
char pop();
int getPriority(char);
void InfixtoPostfix(char[], char[]);

int main()
{
    char infix[100], postfix[100];
    clrscr();
    printf("\nEnter any infix expression : ");
    gets(infix);
    strcpy(postfix, "");
    InfixtoPostfix(infix, postfix);
    printf("\nThe corresponding postfix expression is : ");
    puts(postfix);
    getch();
    return 0;
}

void InfixtoPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    while(source[i] != '\0')
    {
        if(source[i] == '(')
        {
            push(source[i]);
            i++;
        }
        else if(source[i] == ')')
        {
            while(top != -1 && st[top] != '(')
            {
                target[j++] = pop();
            }
            if(top == -1)
            {
                printf("\nINCORRECT EXPRESSION");
                return;
            }
            temp = pop();
            i++;
        }
        else if(isdigit(source[i]) || isalpha(source[i]))
        {
            target[j++] = source[i];
            i++;
        }
        else if(source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/' || source[i] == '%')
        {
            while(top != -1 && st[top] != '(' && getPriority(st[top]) >= getPriority(source[i]))
            {
                target[j++] = pop();
            }
            push(source[i]);
            i++;
        }
        else
        {
            printf("\nINCORRECT ELEMENT IN EXPRESSION");
            return;
        }
    }
    while(top != -1 && st[top] != '(')
    {
        target[j++] = pop();
    }
    target[j] = '\0';
}

int getPriority(char op)
{
    if(op == '/' || op == '*' || op == '%')
        return 1;
    else if(op == '+' || op == '-')
        return 0;
    return -1;
}

void push(char val)
{
    if(top == MAX - 1)
        printf("\nSTACK OVERFLOW");
    else
        st[++top] = val;
}

char pop()
{
    if(top == -1)
    {
        printf("\nSTACK UNDERFLOW");
        return '\0';
    }
    return st[top--];
}
