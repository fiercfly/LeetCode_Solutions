/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map <TreeNode* , TreeNode* > mp;
    unordered_set <TreeNode* > visited;
    vector<int> ans;

    void makeMap(TreeNode* root){
        if(root == NULL){
            return;
        }

        if(root->left){
            mp[root->left]= root;
            makeMap(root->left);
        }

        if(root->right){
            mp[root->right]= root;
            makeMap(root->right);
        }
    }

    void findTarget(TreeNode* root, int k, int dis){
        if(root == NULL || visited.count(root)){ //already visited
            return;
        }

        visited.insert(root);

        if(dis == k){
            ans.push_back(root->val);
        }

        findTarget(root->left, k, dis+1);
        findTarget(root->right, k, dis+1);
        findTarget(mp[root], k, dis+1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeMap(root);
        findTarget(target, k ,0);
        return ans;
    }

};