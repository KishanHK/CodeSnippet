#include <bits/stdc++.h>
using namespace std;
struct Node*{
        int data;
        Node* left, *right;
        Node(int val){
                this->data = val;
                this->left = NULL;
                this->right = NULL;
        }
}
Node* createBST(int start,int end, vector<int> &array){
        if(start > end)
                return NULL;
        int mid = (start + end)/2;

        Node* root = new Node(array[mid]);

        root->left = createBST(start, mid - 1,array);
        root->right = createBST(mid + 1, end, array);

        return root;
}
int main(){

        vector<int> inorder = {1,2,3,4,5,6,7};

        int n = inorder.size();

        Node * root = createBST(0,n-1,inorder);

        return 0;
}
