#include <bits/stdc++.h>
using namespace std;

struct Node {
        int data;
        Node* left,*right;
        Node(int val) {
                data = val; left = NULL;  right = NULL;
        }
};

bool isBST(Node* root,Node* min,Node* max){
        if(root==NULL) {
                return true;
        }

        if(min!=NULL && root->data <= min->data) {
                return false;
        }
        if(max!=NULL && root->data >= max->data) {
                return false;
        }

        bool leftvalid = isBST(root->left,min,root);
        bool rightvalid = isBST(root->right,root,max);

        return leftvalid and rightvalid;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);


        Node* root = new Node(3);
        root->left = new Node(2);
        root->right = new Node(7);
        root->left->left = new Node(1);
        root->right->right = new Node(8);
        root->right->left = new Node(5);
        root->right->right->right = new Node(9);

        cout<<isBST(root,NULL,NULL);

        // Binary search tree
        //                3
        //              /  \
        //            2     7
        //           /     /  \
        //         1      5    8
        //                      \
        //                       9



        return 0;
}
