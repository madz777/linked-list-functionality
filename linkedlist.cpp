#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next = NULL;
};

void Push(struct node** headRef,int data){
    struct node* newNode = new struct node;
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

void Print(struct node* head){
    struct node* current = head;
    while(current != NULL){
        cout << current->data << endl;
    current = current->next;
    }
}

void PrintRecursive(struct node* head){
    if(head == NULL) return;
    cout << head->data << endl;
    PrintRecursive(head->next);
}

int Length(struct node* head){
    int counter = 0;
    struct node* current = head;
    while(current != NULL){
        counter++;
        current = current->next;
    }
    return(counter);
}

void AddToEnd(struct node** headRef,int dataValue){
    struct node* current = *headRef;
    if(current == NULL){
        Push(headRef, dataValue);
    }else{
        while(current->next != NULL){
            current = current->next;
        }
    Push(&(current->next), dataValue);
    }
}

void AddToEndv2(struct node** headRef,int dataValue){
    struct node* newNode = new struct node;
    newNode->data = dataValue;
    newNode->next = NULL;
    if(*headRef == NULL){ //list is empty
        *headRef = newNode;
    }else{
        struct node* current = *headRef;
        while(current->next != NULL){
            current = current->next;
        }
    current->next = newNode;
    }
}

struct node* FindKthLast(struct node* head, int k){
    int count = 0;
    int iterate = 0;
    struct node* current = head;
    while(current != NULL){
        current = current->next;
        count ++;
    }
    iterate = count - k;
    current = head;
    while(iterate > 0){
        current = current->next;
        iterate--;
    }
    return current;
}

struct node* FindKthLastPointers(struct node* head, int k){
    struct node* current = head;
    struct node* runner = head;
    while(k>0 && runner != NULL){
        runner = runner->next;
        k--;
    }
    if(k > 0) {
        return NULL;
    }
    while(runner != NULL){
        runner = runner->next;
        current = current->next;
    }
    return current;
}

void InsertSorted(struct node** headRef,int dataValue){
    struct node* newNode = new struct node;
    newNode->data = dataValue;
    struct node* current = *headRef;
    if(current == NULL){
        newNode->next = NULL;
        *headRef = newNode;
    } else {
        while( (current->next != NULL) && (newNode->data > current->next->data)
        ){
            current = current->next;
        }
        if((*headRef)->data > newNode->data){
        newNode->next = current;
        *headRef = newNode;
        }else{
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

//Assignment Work
//A. Return true if there are duplicate values to be remove

bool RemoveDuplicatesSorted(struct node* head) {
    struct node* current = head;
    struct node* store;
    if (current == NULL) return;
    while (current->next != NULL) {
        if (current->data == current->next->data) {
            //delete

        } else {
            current = current->next;
        }
    }
}

//B. check if the linked list is a palindrome

bool checkIsPalindrome(struct node** left, struct node* right) {
    if (right == NULL) return true;
    bool check1 = checkIsPalindrome(left, right->next);
    if (!check1) return false;
    bool check2 = (right->data == (*left)->data);
    *left = (*left)->next;
    return check2;
}

bool IsPalindrome(struct node* head) {
    return checkIsPalindrome(&head, head);
}

//C. Merge and sort 2 single linked lists

struct node* MergeTwoSorted(struct node* head1, struct node* head2) {
    struct node* newHead = NULL;
    struct node* temp = newHead;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            AddToEndv2(&newHead, head1->data);
            head1 = head1->next;
        } else {
            AddToEndv2(&newHead, head2->data);
            head2 = head2->next;
        }
        temp = temp->next;
    }

    if (head1 == NULL) temp->next = head2;
    if (head2 == NULL) temp->next = head1;

    return newHead->next;
}

//D. 

int main() {
    struct node* head = NULL;
    AddToEndv2(&head, 50);
    AddToEndv2(&head, 60);
    AddToEndv2(&head, 70);
    AddToEndv2(&head, 80);
    AddToEndv2(&head, 90);
    Print(head);
    cout << "\n";
    return 0;
}