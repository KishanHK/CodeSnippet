#include <bits/stdc++.h>
using namespace std;
struct Node {
        int data;
        Node* left,*right;
        Node(int val) {
                data = val; left = NULL;  right = NULL;
        }
};

Node* inorderSuccessor(Node* root){
        Node* curr = root->right;
        while(curr->left!=NULL && curr) {
                curr = curr->left;
        }
        return curr;
}

Node* deleteInBST(Node* root,int key){

        if(key<root->data) {
                root->left = deleteInBST(root->left,key);
        }
        else if(key>root->data) {
                root->right = deleteInBST(root->right,key);
        }
        else{
                if(root->left == NULL and root->right == NULL) {
                        return NULL;
                }
                else if(root->left==NULL) {
                        Node* temp = root->right;
                        free(root);
                        return temp;
                }
                else if(root->right==NULL) {
                        Node* temp = root->left;
                        free(root);
                        return temp;
                }
                else{
                        Node* temp =inorderSuccessor(root);
                        root->data = temp->data;
                        root->right = deleteInBST(root->right,temp->data);
                }

        }
        return root;
}



int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);


        return 0;
}

/*
 * after deleting a node our BST should also follow his properties
 * In the third case we assigning current node as inorderSuccessor and recursively deleting it's inorderSuccessor
 */
