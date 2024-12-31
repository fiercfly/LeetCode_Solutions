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
    void find(TreeNode* root, int pos, int &l, int &r) {
        if(!root)
            return;
        l = min(l,pos);
        r = max(r,pos);
        find(root->left, pos-1, l, r);
        find(root->right,pos+1, l, r);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<vector<int>> positive(r + 1);
        vector<vector<int>> negative(abs(l) + 1);

        // bfs
        queue<TreeNode*> q;
        q.push(root);
        queue<int> index;
        index.push(0);

        while (!q.empty()) {
            int size = q.size();

            vector<vector<int>> temppositive(r + 1);
            vector<vector<int>> tempnegative(abs(l) + 1);
            
            for (int i = 0; i < size; i++) {

                TreeNode* temp = q.front();
                q.pop();
                int pos = index.front();
                index.pop();

                if (pos >= 0)
                    temppositive[pos].push_back(temp->val);
                else
                    tempnegative[abs(pos)].push_back(temp->val);

                if (temp->left) {
                    q.push(temp->left);
                    index.push(pos - 1);
                }
                if (temp->right) {
                    q.push(temp->right);
                    index.push(pos + 1);
                }
            }

            // merge sorted temp array to final
            for (int i = 0; i < tempnegative.size(); i++) {
                if (!tempnegative[i].empty()) {
                    sort(tempnegative[i].begin(), tempnegative[i].end());
                    negative[i].insert(negative[i].end(), tempnegative[i].begin(), tempnegative[i].end());
                }
            }

            for (int i = 0; i < temppositive.size(); i++) {
                if (!temppositive[i].empty()) {
                    sort(temppositive[i].begin(), temppositive[i].end());
                    positive[i].insert(positive[i].end(), temppositive[i].begin(), temppositive[i].end());
                }
            }
        }

        // Combine results into final answer
        vector<vector<int>> ans;
        for (int i = negative.size() - 1; i > 0; i--) {
            if (!negative[i].empty())
                ans.push_back(negative[i]);
        }
        for (int i = 0; i < positive.size(); i++) {
            if (!positive[i].empty())
                ans.push_back(positive[i]);
        }

        return ans;
    }
};