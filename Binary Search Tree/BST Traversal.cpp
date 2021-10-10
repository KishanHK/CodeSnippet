#include <bits/stdc++.h>
using namespace std;

struct Node {
        int data;
        Node* left,*right;
        Node(int val){
                data = val; left = NULL;  right = NULL;
        }
};

void printInorder(Node* root){
        if(root==NULL) {
                return;
        }
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
}

void printPreorder(Node* root){
        if(root==NULL) {
                return;
        }
        cout<<root->data<<" ";
        printPreorder(root->left);
        printPreorder(root->right);
}

void printPostorder(Node* root){
        if(root==NULL) {
                return;
        }
        printPostorder(root->left);
        printPostorder(root->right);
        cout<<root->data<<" ";
}

int main(){



        return 0;
}
