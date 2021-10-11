#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
        int val;
        TreeNode* left,*right;
        TreeNode(int x){
                left = NULL; right = NULL;  val = x;
        }
};

vector<TreeNode*> helper(int low, int high){
        vector<TreeNode* > list;
        if(low > high) {
                list.push_back(NULL);
                return list;
        }
        for(int i = low; i<=high; i++) {
                vector<TreeNode*> left = helper(low,i-1);
                vector<TreeNode*> right = helper(i+1,high);
                for(int j = 0; j<left.size(); j++) {
                        for(int k = 0; k<right.size(); k++) {
                                TreeNode* node = new TreeNode(i);
                                node->left = left[j];
                                node->right = right[k];
                                list.push_back(node);
                        }
                }
        }
        return list;
}


int main(){

        vector<TreeNode* > res = helper(1,3);

        return 0;
}
