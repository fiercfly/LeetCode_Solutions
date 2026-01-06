/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int level= 1;
        int maxSum= INT_MIN;
        int maxSumLevel= -1;


        int currNode= 0;
        int nextNode= 0;
        int tempSum= 0;

        queue<TreeNode*> q;

        q.push(root);
        currNode= 1;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            tempSum+= node->val;
            --currNode;


            if(node->left){
                q.push(node->left);
                nextNode++;
            }
            if(node->right){
                q.push(node->right);
                nextNode++;
            }
            if(currNode == 0){
                if(maxSum < tempSum){
                    maxSum= tempSum;
                    maxSumLevel= level;
                }
                level++;
                tempSum= 0;
                currNode= nextNode;
                nextNode= 0;
            }
        }
        return maxSumLevel;

    }
};

// nodes at level n-1= 2*n-1
// total nodes at level n= 2^n-1
