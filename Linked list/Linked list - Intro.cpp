#include <bits/stdc++.h>
using namespace std;

class node {
public:
int data;
node* next;
node(int val){
        data = val; next = NULL;
}
};

int length(node* head){
        node* temp = head;
        int len = 0;
        while(temp!=NULL) {
                len++;
                temp = temp->next;
        }
        return len;
}

void insertAthead(node*&head,int val){
        node* n = new node(val);
        n->next=head;
        head = n;
}

void InsertAtTail(node* &head,int val){
        node* n = new node(val);
        if(head==NULL) {
                head = n;
                return;
        }
        node* temp = head;
        while(temp->next!=NULL) {
                temp=temp->next;
        }
        temp->next = n;
}

void display(node*head){
        node* temp = head;
        while(temp!=NULL) {
                cout<<temp->data<<' ';
                temp = temp->next;
        }
        cout<<endl;
}

bool search(node* head,int key){
        node* temp = head;
        while(temp!=NULL) {
                if(temp->data==key) return true;
                temp=temp->next;
        }
        return false;
}

void deleteAthead(node* &head){
        node* todelete = head;
        head = head->next;

        delete todelete;
}

void deletion(node* &head,int val){

        node* temp = head;

        if(head==NULL) return;

        if(temp->next==NULL) {
                deleteAthead(head);
                return;
        }

        while(temp->next->data!=val) {
                temp = temp->next;
        }
        node* todelete  = temp->next;

        temp->next= temp->next->next;

        delete todelete;
}


int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        node* head = NULL;
        InsertAtTail(head,1);
        InsertAtTail(head,3);
        InsertAtTail(head,2);

        display(head);

        insertAthead(head,4);

        display(head);

        cout<<search(head,5)<<endl;

        deletion(head,3);

        deleteAthead(head);

        display(head);


        return 0;
}
