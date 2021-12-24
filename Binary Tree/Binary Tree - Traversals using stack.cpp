#include <bits/stdc++.h>
using namespace std;

vector<int> inorderTraversal(TreeNode* root) {

        vector<int> v;
        stack<TreeNode* > stackNode;
        while(stackNode.size()!= 0 || root != NULL) {
                if(root==NULL) {

                        root = stackNode.top();
                        stackNode.pop();
                        v.push_back(root->val);
                        root = root->right;

                }
                else{
                        stackNode.push(root);
                        root = root->left;
                }
        }
        return v;
}

vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stackNode;
        vector<int> v;
        stackNode.push(root);
        while(stackNode.size()!=0) {
                TreeNode* topNode = stackNode.top();
                if(topNode->left) {
                        stackNode.push(topNode->left);
                        topNode->left = NULL;
                        continue;
                }
                if(topNode->right) {
                        stackNode.push(topNode->right);
                        topNode->right = NULL;
                        continue;
                }
                v.push_back(topNode->val);
                stackNode.pop();

        }
        return v;
}

int main(){




        return 0;
}
