class Solution {
public:
    vector<int> kGreaterThanZero(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                ans[i] += code[(i + j) % n];
            }
        }
        return ans;
    }

    vector<int> kSmallerThanZero(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= abs(k); j++) {
                ans[i] += code[(i - j + n) % n];
            }
        }
        return ans;
    }

    vector<int> decrypt(vector<int>& code, int k) {
        if (k == 0) {
            return vector<int>(code.size(), 0);
        } else if (k > 0) {
            return kGreaterThanZero(code, k);
        } else {
            return kSmallerThanZero(code, k);
        }
    }
};
