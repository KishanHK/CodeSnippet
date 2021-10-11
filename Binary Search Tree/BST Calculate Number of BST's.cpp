#include <bits/stdc++.h>
using namespace std;

int numberOfBST(int n){

        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = dp[1] = 1;

        for(int i = 2; i<=n; i++) {
                for(int j = 1; j<i; j++) {
                        dp[i] += (dp[i - j] * dp[j - 1]);
                }
        }
        return dp[n];
}

int main(){

        return 0;
}

/*
 * -> Task is to calculate total number of BST that can be constructed from the number from 1 to n
 * -> The solution is equal to for a number = (i-1)*(n-i) taking "i" as a root node.
 *
 * -> number of possible *binary tree* =  dp[n] * (n!)
 *
 *-> Number of BST can also be calculated from the Catalan Formula = (2n)! / ( (n+1)! * (n)! ) == C(2n,n)/(n+1)
 */
