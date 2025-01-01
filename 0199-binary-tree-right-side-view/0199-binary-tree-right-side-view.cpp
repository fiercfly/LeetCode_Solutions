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
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> mp;

        if(!root){
            return {};
        }

        queue<pair< int, TreeNode*>> q;
        q.push({0,root});

        while(!q.empty()){
            auto p= q.front();
            q.pop();

            TreeNode* node= p.second;
            
            int lvl= p.first;

            if(mp.find(lvl)==mp.end()){
                mp[lvl]= node->val;
            }

            if(node->right){
                q.push({ lvl+1, node->right});
            }

            if(node->left){
                q.push({ lvl+1, node->left});
            }
        }

        vector<int> ans;

        for(auto i: mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};