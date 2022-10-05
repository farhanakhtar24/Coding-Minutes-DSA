#include <stdio.h>
#include <conio.h>

#define N 25

struct stacktype
{
    int s[N];
    int top;
};

typedef struct stacktype stack;

int isempty(int top)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull(int top)
{
    if (top == N - 1)
        return 1;
    else
        return 0;
}

void push(stack *sp, int item)
{
    if (isfull(sp->top))
    {
        printf("Stack full/overflow -Insertion not possible\n");
        return;
    }
    (sp->top)++;
    sp->s[sp->top] = item;
}

int pop(stack *sp)
{
    int item;
    if (isempty(sp->top))
    {
        printf("Stack empty/underflow -Deletion not possible\n");
        return 0;
    }
    item = sp->s[sp->top];
    (sp->top)--;
    return item;
}

int peek(stack st)
{
    if (isempty(st.top))
    {
        printf("Stack empty\n");
        return 0;
    }
    return st.s[st.top];
}

void traversal(stack st)
{
    int i = 0;
    if (isempty(st.top))
    {
        printf("\nStack empty\n");
        return;
    }
    printf("\nContents of Stack:\n");
    while (i <= st.top)
        printf("%d ", st.s[i++]); /*outputs all items starting from s[0] upto top*/
    printf("<-top\n");
}

int main()
{
    int choice, item;
    stack st; /*initially stack is empty*/
    st.top = -1;
    do
    {
        printf("\nMENU (Stack Operations):");
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Traversal\n5.Exit\n");
        printf("Choice ? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter an int value to be pushed: ");
            scanf("%d", &item);
            push(&st, item);
            break;
        case 2:
            if (isempty(st.top))
            {
                printf("\nStack empty, Press any key to continue...\n");
                getch();
            }
            else
            {
                item = pop(&st);
                printf("Item popped= %d\n", item);
            }
            break;
        case 3:
            if (isempty(st.top))
            {
                printf("\nStack empty, Press any key to continue...\n");
                getch();
            }
            else
            {
                item = peek(st);
                printf("Item at the top= %d\n", item);
            }
            break;
        case 4:
            traversal(st);
            break;
        }
    } while (choice != 5);
    return 0;
}
