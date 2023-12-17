#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact{    // contract er structure
    int id;
    char name[50];
    char number[20];
    struct Contact *prev;
    struct Contact *next;
};

struct Contact *head = NULL;
struct Contact *tail = NULL;

void addContact(int id, char name[], char number[]){
    struct Contact *newContact = (struct Contact *)malloc(sizeof(struct Contact));
    newContact->id = id;
    strcpy(newContact->name, name);
    strcpy(newContact->number, number);
    newContact->prev = NULL;
    newContact->next = NULL;

    if(head==NULL){
        head = newContact;
        tail = newContact;
    }
    else{
        tail->next = newContact;
        newContact->prev = tail;
        tail = newContact;
    }
    printf("Contact added successfully!\n");
}

void showContact(){
    if(head == NULL){
        printf("Phone book is empty!\n");
        return;
    }

    struct Contact *temp = head;
    printf("Contacts:\n");
    while (temp != NULL){
        printf("\n");
        printf("ID: %d, Name: %s, Number: %s\n", temp->id, temp->name, temp->number);
        temp = temp->next;
    }
}

struct Contact *findContact(int id){
    struct Contact *temp = head;
    while (temp != NULL){
        if(temp->id==id){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void deleteContact(int id){
    struct Contact *temp=findContact(id);
    if(temp==NULL){
        printf("Contact with ID %d not found.\n", id);
        return;
    }

    if(temp==head){
        head = temp->next;
        if(head != NULL) head->prev = NULL;
        else tail = NULL;
        free(temp);
        printf("Contact with ID %d deleted successfully.\n", id);
        return;
    }

    if(temp==tail){
        tail = temp->prev;
        tail->next = NULL;
        free(temp);
        printf("Contact with ID %d deleted successfully.\n", id);
        return;
    }

    struct Contact *back = temp->prev;
    struct Contact *front = temp->next;
    back->next = front;
    front->prev = back;
    free(temp);
    printf("Contact with ID %d deleted successfully.\n", id);
}

int main(){
    int choice;
    int id;
    char name[50], number[20];

    while(1){
        printf("\nPhone Book Management\n");
        printf("1. Add Contact\n");
        printf("2. Show Contacts\n");
        printf("3. Find Contact by ID\n");
        printf("4. Delete Contact by ID\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter contact ID: ");
            scanf("%d", &id);
            printf("Enter name: ");
            scanf("%s", name); 
            printf("Enter number: ");
            scanf("%s", number);
            addContact(id, name, number);
        }

        else if(choice==2){
            showContact();
        }

        else if(choice==3){
            printf("Enter contact ID to find: ");
            scanf("%d", &id);
            struct Contact *foundContact = findContact(id);
            if(foundContact != NULL){
                printf("Contact found!\nID: %d, Name: %s, Number: %s\n", foundContact->id, foundContact->name, foundContact->number);
            } 
            else{
                printf("Contact not found : %d\n", id);
            }
        }

        else if(choice==4){
            printf("Enter contact ID to delete: ");
            scanf("%d", &id);
            deleteContact(id);
        }

        else if(choice==5){
            break;
        }

        else{
            printf("Choice is Wrong! Do it Again!!\n");
        }
    }
    return 0;
}