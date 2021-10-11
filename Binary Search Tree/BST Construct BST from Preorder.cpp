#include <bits/stdc++.h>
using namespace std;

struct Node {
        int data;
        Node* left,*right;
        Node(int val) {
                data = val; left = NULL;  right = NULL;
        }
};

Node* constructBST(int preorder[],int* idx,int key,int min,int max,int n){
        if(*idx>=n) {
                return NULL;
        }
        Node* root = NULL;
        if(key>min && key <max) {
                root = new Node(key);
                *idx = *idx + 1;
                if(*idx<n) {
                        root->left = constructBST(preorder,idx,preorder[*idx],min,key,n);
                }
                if(*idx<n) {
                        root->right = constructBST(preorder,idx,preorder[*idx],key,max,n);
                }

                return root;
        }

        return root;
}


int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int preorder[] = {10,2,1,13,11};

        int n = sizeof(preorder)/sizeof(preorder[0]);

        int idx = 0;
        Node* root = constructBST(preorder,&idx,preorder[0],INT_MIN,INT_MAX,n);

        return 0;
}
