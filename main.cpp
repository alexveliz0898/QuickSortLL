#include <iostream>
#include <stdlib.h>
using namespace std;

struct listnode{
    struct listnode * next;
    int key;
};

struct listnode * sort(struct listnode * a);
struct listnode * SelectPivot(struct listnode *list);
void printList (listnode *head);
int listLength (struct listnode *list);


int main(){
    listnode n; listnode n1; listnode n2; listnode n3; listnode n4; listnode n5; listnode n6; listnode n7; listnode n8;
    n.next = &n1; n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5; n5.next = &n6; n6.next = &n7; n7.next = &n8; n8.next = NULL;
    n.key = 15; n1.key = 3; n2.key = 1; n3.key = 8; n4.key = 5; n5.key = 2; n6.key = 7; n7.key = 9; n8.key = 6;

    struct listnode * a;
    a = &n;
    cout<<"Linked List before sort(): ";
    printList(a);
    a = sort(a);
    cout<<"Linked List after sort():  ";
    printList(a);
}

void printList (listnode *head){
    listnode * cursor = head;
    while(cursor != NULL){
        cout<< cursor->key <<" ";
        cursor = cursor->next;
    }
    cout<<endl;
}

int listLength (struct listnode *list) {    //finds length of list for partitioning the lists & selecting random pivot
    struct listnode *temp = list;
    int i=0;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}

struct listnode *SelectPivot(struct listnode *list){        // Selects a random pivot point
    int k, n;
    n = listLength(list);
    struct listnode *pivot=list;
    k=rand()%n;  //
    for (int i = 0; i < k; ++i) {
        pivot=pivot->next;
    }
    return pivot;
}

// Sorts a list using QuickSort & a random pivot point
struct listnode *sort(struct listnode *a) {
    if (listLength(a) <= 1)  // Base Case. Returns list, already sorted.
        return a;
    struct listnode *small = NULL, *large = NULL, *next, *end, *temp = NULL;

    // Select a random pivot point
    struct listnode *pivot = SelectPivot(a);

    // Remove pivot from list
    while(a !=NULL) {
        next = a->next;
        if(a->key != pivot->key) {
            a->next=temp;
            temp = a;
        }
        a = next;
    }
    // Divide & Conquer
    while(temp != NULL) {
        next = temp->next;
        if(temp->key < pivot->key) {
            temp->next = small;
            small = temp;
        }
        else {
            temp->next = large;
            large = temp;
        }
        temp = next;
    }
    // Recursive Calls
    small = sort(small);
    large = sort(large);
    // Merging
    if(small != NULL) {
        end = small;
        while(end->next != NULL){
            end=end->next;
        }
        pivot->next = large;
        end->next = pivot;
        return small;
    }
    else{
        pivot->next = large;
        return pivot;
    }
}
