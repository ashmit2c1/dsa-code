#include<bits/stdc++.h>
using namespace std;
// =========================================== // 
// CREATING THE LIST NODE CLASS FOR LINKED LIST 
// =========================================== // 
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

// =========================================== // 
// INSERTING A NODE AT THE HEAD OF A LINKED LIST
// =========================================== // 
void insertAtHead(Node* &head, int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head=newNode;
}
// =========================================== // 
// TRAVERSING A LINKED LIST
// =========================================== // 
void traverse(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << "\n";
}
// =========================================== // 
// INSERTING A NODE AT THE TAIL OF A LINKED LIST 
// =========================================== // 
void insertAtTail(Node* &head, int value){
    Node* newNode = new Node(value);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}
// =========================================== // 
// INSERTING A NEW NODE AT THE KTH POSITION 
// =========================================== // 
void insertAtK(Node* &head, int value, int pos){
    Node* temp = head;
    Node* newNode = new Node(value);
    if(pos==0){
        insertAtHead(head,value);
    }
    int position = 0;
    while(position!=pos-1){
        temp=temp->next;
        position++;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
// =========================================== // 
// UPDATING THE VALUE AT THE KTH POSITION
// =========================================== // 
void updateAtK(Node* &head, int K, int value){
    Node* temp = head;
    int position = 0;
    while(position!=K){
        temp=temp->next;
        position++;
    }
    temp->data = value;
}
// =========================================== // 
// DELETE A NODE AT THE HEAD OF THE LINKED LIST
// =========================================== // 
void deleteAtHead(Node* &head){
    Node* temp = head;
    head=head->next;
    free(temp);
}
// =========================================== // 
// DELETE A NODE AT THE END OF A LINKED LIST
// =========================================== // 
void deleteAtTail(Node* &head){
    Node* temp =head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    Node* delNode = temp->next;
    temp->next=NULL;
    free(temp);
}
// =========================================== // 
// DELETE A NODE AT THE KTH POSITION 
// =========================================== // 
void deleteAtK(Node* &head, int K){
    if(K==0){
        deleteAtHead(head);
    }
    int pos=0;
    Node* temp = head;
    while(pos!=K-1){
        temp=temp->next;
    }
    Node* delNode  = temp->next;
    delNode->next = temp->next->next;
    free(temp);
}
// =========================================== // 
// LENGTH OF THE LINKED LIST 
// =========================================== // 
int lengthOfLinkedList(Node* &head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
// =========================================== // 
// PRINT THE KTH NODE
// =========================================== // 
void printKthNode(Node* &head, int K){
    int count=0;
    while(count<=K){
        head=head->next;
        count++;
    }
    cout << head->data << "\n";
}
int main(){
    // CREATING NODES STATICALLY
    Node n1(1);
    Node n2(2);
    n1.next=&n2;
    // CREATING NODES DYNAMICALLY
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    n3->next=n4;
    Node* head = NULL;
    insertAtHead(head,2);
    insertAtHead(head,4);
    traverse(head);
    insertAtTail(head,6);
    traverse(head);
}