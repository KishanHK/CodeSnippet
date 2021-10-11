#include <bits/stdc++.h>
using namespace std;

Node* inorderSuccessor(Node* root){
        Node* curr = root->right;
        while(curr->left!=NULL && curr) {
                curr = curr->left;
        }
        return curr;
}

int main() {


        return 0;
}

/*
 * In BST the inorderSuccessor will be the next smallest greater number which is greater then the given number
 * And that number is  leftmost number in the right child of the root which have value greater than root
 */
