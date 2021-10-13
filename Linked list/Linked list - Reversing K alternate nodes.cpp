#include <bits/stdc++.h>
using namespace std;

/*
 * Reversing k alternate nodes
 * if k == 2 then we are swappin pairs
 */

ListNode* Solution::solve(ListNode* head, int k) {

        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        ListNode* nextptr;

        int count = 0;
        while(currptr!=NULL && count<k ) {
                nextptr = currptr->next;
                currptr->next = prevptr;
                prevptr = currptr;
                currptr = nextptr;
                count++;

        }

        if(nextptr!=NULL) {
                head->next = nextptr;
                count = 0;
                while(head!=NULL&&count<k ) {
                        head = head->next;
                        count++;
                }

                if(head->next!=NULL) {
                        head->next = solve(head->next,k);
                }

        }
        return prevptr;
}

int main(){

        ios_base::sync_with_stdio(0);
        cin.tie(0);


        return 0;
}
