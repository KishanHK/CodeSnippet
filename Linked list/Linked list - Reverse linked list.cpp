#include <bits/stdc++.h>
using namespace std;


class node {
public:
int data;
node* next;
node(int val){
        data = val;
        next = NULL;
}
};

// #1. Iterative approach :
node* reverse(node* &head){
        node* prevptr = NULL;
        node* curptr = head;
        node* nextptr;

        while(curptr!=NULL) {
                nextptr = curptr->next;
                curptr->next = prevptr;
                prevptr = curptr;
                curptr = nextptr;

        }

        return prevptr;
}

// #2. Recursive approach :
node* reverseRecursive(node* &head){

        if(head==NULL || head->next == NULL) {
                return head;
        }

        node* newhead = reverseRecursive(head->next);

        head->next->next = head;
        head->next = NULL;

        return newhead;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);



        return 0;
}
