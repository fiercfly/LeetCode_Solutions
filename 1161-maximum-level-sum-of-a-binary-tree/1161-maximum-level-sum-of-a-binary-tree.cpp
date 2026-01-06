class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;

        int maxSum = INT_MIN;
        int maxLevel = 0;
        int currentLevel = 1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); // Number of nodes in the CURRENT level
            int currentLevelSum = 0;

            // Process ALL nodes at this current level
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                currentLevelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // After the for-loop, we have the full sum for this level
            if (currentLevelSum > maxSum) {
                maxSum = currentLevelSum;
                maxLevel = currentLevel;
            }

            currentLevel++;
        }

        return maxLevel;
    }
};