#include <stdio.h>
#include <stdlib.h>

struct node
{
    int a;
    struct node* next;
};
struct node* start = NULL;

void display(){
    struct node* cur = (struct node*)malloc(sizeof(struct node*));
    cur = start;
    printf("\nElements of Stack.....\n");
    while(cur != NULL){
        printf("--> %d\n", cur->a);
        cur = cur->next;
    }
}

void push(){
    int val;
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the value : ");
    scanf("%d", &val);
    if(start == NULL){
        newnode->a = val;
        newnode->next = NULL;
        start = newnode;
    }else{
        newnode->a = val;
        newnode->next = start;
        start = newnode;
    }
    display();
}

void pop(){
    if(start != NULL){
        start = start->next;
        display();
    }else{
        printf("\nThe Stack is empty.....\n");
    }
}

void topElement(){
    if(start != NULL)
        printf("\nThe top element is %d\n", start->a);
    else
        printf("\nThe Stack is empty\n");
}

void IsEmpty(){
    if(start == NULL){
        printf("\nThe Stack is empty.....\n");
    }else{
        printf("\nThe Stack is not empty.....\n");
    }
}

void nElements(){
    struct node* cur = (struct node*)malloc(sizeof(struct node*));
    cur = start;
    int count = 0;
    while(cur != NULL){
        count++;
        cur = cur->next;
    }
    printf("\nThe no of Elements in the stack is %d\n", count);
}

int main(int argc, char const *argv[])
{
    int ch;
    printf("-------20BEE034--------MD SAQUIB SHAKEEL---------");
     

    do{
        printf("\n");
        printf("Options : \n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Top\n");
        printf("5. No of Elements\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 1: push();
                break;
            case 2: pop();
                break;
            case 3: IsEmpty();
                break;
            case 4: topElement();
                break;
            case 5: nElements();
                break;
            case 6: display();
                break;
            case 7: return 0;
            default: printf("\nNot a valid option \n");
        }
    }while(1);
}