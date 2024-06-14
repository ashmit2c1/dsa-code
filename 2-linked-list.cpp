#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;

    }
};


//INSERT AT HEAD OF LINKED LIST 
void insertAtHead(Node* &head, int value){
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}
// TRAVERSEING A LINKED LIST 
void traverse(Node* &head){
    Node* temp  = head;
    while(temp!=NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << "\n";
}
// PRINTING AN ARRAY AS LINKED LIST 
void printLinkedListArray(Node* &head, vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        if(head==NULL){
            head = new Node(arr[i]);
        }
        else{
            Node* newNode = new Node(arr[i]);
            newNode->next = head;
            head = newNode;
        }
    }
}
// INSERTING AT THE TAIL OF A LINKED LIST 
void insertAtTail(Node* &head, int value){
    Node* newNode = new Node(value);
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;

    }
    temp->next = newNode;
}
// PRINTING AN ARRAY AS LINKED LIST TAIL
void printLinkedListArrayTail(Node* &head, vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i<n ; i++){
        if(head==NULL){
            head = new Node(arr[i]);
        }
        else{
            Node* newNode = new Node(arr[i]);
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }

    }
}
// INSERT A NODE AT THE NTH POSITION IN LINKED LIST 
void insertAtK(Node* &head, int K, int value) {
    if (K == 0) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    Node* newNode = new Node(value);
    int currPosition = 0;
    while (currPosition != K - 1) {
        temp = temp->next;
        currPosition++;
    }
        newNode->next = temp->next;
        temp->next = newNode;
}
// DELETE A NODE AT THE HEAD OF THE LINKED LIST 
void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    delete(temp);
}
// DELETE AT THE TAIL OF THE LINKED LIST 
void deleteAtTail(Node* &head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete(head);
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    Node* deleteNode = temp->next;
    temp->next = NULL;
    delete(deleteNode);
}
// DELETE AT THE KTH POSITION OF LINKED LIST 
void deleteAtKthPosition(Node* head,int pos){
    if(pos==0){
        deleteAtHead(head);
        return;
    }
    Node* prev = head;
    int currPos=0;
    while(currPos!=pos-1){
        prev = prev->next;
        currPos++;
    }
    Node* temp = prev->next;
    prev->next = prev->next->next;
    delete(temp);
}
// LENGTH OF THE LINKED LIST 
int lengthLinkedList(Node* &head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
// PRINT THE Ith NODE IN THE LINKED LIST 
void printIthNode(Node* head, int i) {
    if (i < 0) {
        cout << -1 << "\n";
        return;
    }
    int count = 0;
    Node* current = head;
    while (count < i && current != nullptr) {
        current = current->next;
        count++;
    }
    if (current != nullptr) {
        cout << current->data << "\n";
    } else {
        cout << -1 << "\n";
    }
}
// UDPATE THE VALUE AT Kth POSITION IN LINKED LIST 
void updateAtK(Node* &head, int K, int value){
    Node* temp = head;
    int curr = 0;
    while(curr!=K){
        temp = temp->next;
        curr++;
    }
    temp->data = value;
}
// REVERSE A GIVEN LINKED LIST
Node* reverseLinkedList(Node* &head){
    Node* prev = NULL;
    Node* current = head;
    Node* next = current->next;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current=next;
    }
    return prev;
}
// FIND THE MIDDLE OF THE LINKED LIST USING COUNT
int findMiddleCount(Node* &head){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    count = count/2;
    Node* ans = head;
    while(count--){
        ans = ans->next;
    }
    return ans->data;
}
int main(){
    Node* thirdHead = NULL;
    vector<int> arr;
    for(int i=1;i<=5;i++){
        arr.push_back(i);
    }
    printLinkedListArrayTail(thirdHead,arr);
    traverse(thirdHead);
    printIthNode(thirdHead,3);
    updateAtK(thirdHead,3,2);
    traverse(thirdHead);

    
}