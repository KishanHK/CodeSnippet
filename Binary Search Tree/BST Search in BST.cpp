#include <bits/stdc++.h>
using namespace std;
struct Node {
        int data;
        Node* left,*right;
        Node(int val) {
                data = val; left = NULL;  right = NULL;
        }
};

Node* searchInBST(Node* root,int key){
        if(root==NULL) {
                return NULL;
        }
        if(root->data==key) {
                return root;
        }
        if(key < root->data) {
                return searchInBST(root->left,key);
        }
        return searchInBST(root->right,key);
}


int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);


        return 0;
}
