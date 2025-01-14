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
    TreeNode* make(vector<int> preorder,int pst, int pend, vector<int> inorder, int ist, int iend, map<int, int> &inMap){
        if(pend< pst || ist> iend){
            return NULL;
        }

        TreeNode* root= new TreeNode(preorder[pst]); //Since pst is root left right
        int inRoot= inMap[root->val]; //Index of root in inorder array

        int numsLeft= inRoot- ist;

        root->left= make(preorder, pst+1, pst+ numsLeft, inorder, ist, inRoot-1, inMap);
        root->right= make(preorder, pst+numsLeft+1, pend, inorder, inRoot+1, iend, inMap);


        return root;

    } 


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]]= i;
        }

        TreeNode* root= make(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};