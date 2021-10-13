#include <bits/stdc++.h>
using namespace std;

ListNode* Solution::solve(ListNode* A) {
        stack<ListNode*> even;
        queue<ListNode*> odd;
        ListNode* temp = A;
        while(temp!=NULL) {
                odd.push(temp);
                temp = temp->next;
                if(temp==NULL) break;
                even.push(temp);
                temp = temp->next;
        }
        ListNode* newhead = odd.front();
        ListNode* ntemp = newhead;
        odd.pop();
        while(!odd.empty()) {
                ntemp->next = even.top();
                ntemp = ntemp->next;
                ntemp->next = odd.front();
                ntemp = ntemp->next;
                odd.pop();
                even.pop();
        }
        if(!even.empty()) {ntemp->next = even.top(); ntemp = ntemp->next;}

        ntemp->next = NULL;
        return newhead;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);


        return 0;
}
