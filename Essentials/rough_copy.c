#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *p;

int count = 0;

void display()
{
    if (head == NULL)
    {
        printf("Linked list is empty. \n");
        return;
    }
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert_at_begin(int data)
{
    count++;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    display();
}

void insert_at_end(int data)
{
    count++;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    p = head;
    if (p == NULL)
    {
        head = newnode;
        display();
        return;
    }
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newnode;
    display();
}

void insert_at_pos(int data)
{
    int n;
    printf("Enter position : ");
    scanf("%d", &n);
    if (n == 0)
    {
        insert_at_begin(data);
        return;
    }
    if (n >= count)
    {
        insert_at_end(data);
        return;
    }
    count++;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    p = head;
    if (p == NULL)
    {
        head = newnode;
        display();
        return;
    }
    for (int i = 1; i < n; i++)
    {
        p = p->next;
    }
    newnode->next = p->next;
    p->next = newnode;
    display();
}

void delete_at_begin()
{
    if (head == NULL)
    {
        printf("Linked list is empty. \n");
        return;
    }
    p = head;
    count--;
    printf("Deleted item = %d .\n", head->data);
    head = head->next;
    free(p);
    display();
}

void delete_at_end()
{
    if (head == NULL)
    {
        printf("Linked list is empty. \n");
        return;
    }
    p = head;
    if (p->next == NULL)
    {
        delete_at_begin();
        return;
    }
    count--;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    printf("Deleted item = %d .\n", p->next->data);
    p->next = NULL;
    free(p->next);
    display(p->next);
}

void delete_at_pos()
{
    if (head == NULL)
    {
        printf("Linked list is empty. \n");
        return;
    }
    int n;
    printf("Enter position : ");
    scanf("%d", &n);
    if (n == 0 || n == 1)
    {
        delete_at_begin();
        return;
    }
    if (n >= count)
    {
        delete_at_end();
        return;
    }
    count--;
    p = head;
    for (int i = 1; i < (n - 1); i++)
    {
        p = p->next;
    }
    printf("Deleted item = %d .\n", p->next->data);
    free(p->next);
    p->next = p->next->next;
    display();
}

void total()
{
    printf("Total number of elements = %d .\n", count);
}

void sum_of_elements()
{
    int sum = 0;
    if (head == NULL)
    {
        printf("Linked list is empty. \n");
        return;
    }
    p = head;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    printf("Total sum of elements = %d .\n", sum);
}

void search_item()
{
    if (head == NULL)
    {
        printf("Linked list is empty. \n");
        return;
    }
    int data;
    printf("Enter data to be searched : ");
    scanf("%d", &data);
    p = head;
    int i = 0;
    while (p != NULL)
    {
        i++;
        if (p->data == data)
        {
            printf("Item is present at position = %d .\n", i);
            return;
        }
        p = p->next;
    }
    printf("Item is not present. \n");
}

void max_number()
{
    if (head == NULL)
    {
        printf("Linked list is empty. \n");
        return;
    }
    int max = head->data;
    p = head->next;
    while (p != NULL)
    {
        if (max < p->data)
            max = p->data;
        p = p->next;
    }
    printf(" Maximum number = %d .\n", max);
}

int main()
{
    int ch;
    printf("------20BEE038------MOHD FARHAN AKHTAR-------\n");
    while (1)
    {
        printf("\n--------------MENU-------------\n");
        printf("\n1. Insert at beginning.\n");
        printf("2. Insert at end.\n");
        printf("3. Insert at given position.\n");
        printf("4. Delete from beginning.\n");
        printf("5. Delete from end.\n");
        printf("6. Delete from given position.\n");
        printf("7. Total number of elements.\n");
        printf("8. Sum of elements of linked list.\n");
        printf("9. Search of item.\n");
        printf("10. Maximum number in linked list.\n");
        printf("11. Display .\n");
        printf("12. Exit. \n");
    xy:
        printf("Enter your choice : ");
        scanf("%d", &ch);
        int num;
        switch (ch)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &num);
            insert_at_begin(num);
            break;
        case 2:
            printf("Enter data : ");
            scanf("%d", &num);
            insert_at_end(num);
            break;
        case 3:

            printf("Enter data : ");
            scanf("%d", &num);
            insert_at_pos(num);
            break;
        case 4:
            delete_at_begin();
            break;

        case 5:
            delete_at_end();
            break;
        case 6:
            delete_at_pos();
            break;
        case 7:
            total();
            break;
        case 8:
            sum_of_elements();
            break;
        case 9:
            search_item();
            break;
        case 10:
            max_number();
            break;
        case 11:
            display();
            break;
        case 12:
            printf("Exiting ............. \n");
            return 0;
        default:
            printf("Invalid choice, please try again \n");
            goto xy;
        }
    }
    return 0;
}