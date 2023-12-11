#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Node struct node

Node{
    int task;
    char name[30];
    Node *next;
    Node *prev;
};
Node *head=NULL;
Node *tail=NULL;

void enqueue(int task, char n[]){
    Node *newNode = (Node *) malloc (sizeof(Node));
    newNode->task = task;
    strcpy(newNode->name, n);
    newNode->next = NULL;
    newNode->prev = NULL;  

    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = NULL;
    tail = newNode;
}

void deque(){
    if(head==NULL){
        printf("Queue is empty!\n");
        return;
    }
    printf("\nTask No is %d\n", head->task);
    printf("Task Name is %s\n\n", head->name);

    Node * temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
}

void nextTask(){
    Node * temp = head;
    printf("\nNext Task No is %d\n", temp->task);
    printf("Next Task Name is %s\n\n", temp->name);
}

void showTask(){
    Node * temp = head;
    while (temp != NULL)
    {
        printf("\nTask No is %d\n", temp->task);
        printf("Task Name is %s\n\n", temp->name);
        temp = temp->next;
    }
    
}

int main(){
    while (1)
    {
        printf("1. Scheduel Task.\n");
        printf("2. Execute Task.\n");
        printf("3. Display Task.\n");
        printf("4. Display Next Task.\n");
        printf("0. Exit.\n\n");
        printf("Enter choise: ");
        int n; scanf("%d",&n);

        if(n==1){
            int task;
            char name[30];
            printf("Enter task id: ");
            scanf("%d", &task);
            printf("Enter task nmae: ");
            scanf(" %s", &name);
            enqueue(task,name);
            printf("\n\n");
        }
        else if(n==2){
            deque();
        }
        else if(n==3){
            showTask();
        }
        else if(n==4){
            nextTask();
        }
        else if(n==0) break;

    }
    return 0;
}
