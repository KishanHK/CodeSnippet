#include <bits/stdc++.h>
using namespace std;

//#1. Iterative approach
Node* sortedMerge(Node*a, Node* b)
{
        Node* ans = new Node(0);
        Node* ptr = ans;
        while(a!=NULL && b!=NULL) {

                if(a->data < b->data) {
                        ptr->next = a;
                        a = a->next;
                }
                else {
                        ptr->next = b;
                        b = b->next;
                }

                ptr = ptr->next;
        }

        if(a != NULL) ptr->next = a;
        else if(b != NULL) ptr->next = b;

        return ans->next;

}

//#2. Recursive approach
Node* sortedMerge(Node*a, Node* b)
{
        Node* res = NULL;
        if(a == NULL) return b;
        if(b == NULL) return a;

        if(a->data >= b->data) {
                res = b;
                res->next = sortedMerge(a, b->next);
        }
        else{
                res = a;
                res->next = sortedMerge(a->next, b);
        }
        return res;
}

int main(){



        return 0;
}
