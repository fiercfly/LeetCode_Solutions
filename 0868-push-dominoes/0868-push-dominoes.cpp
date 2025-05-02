class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string ans = dominoes;

        int i = 0;
        while (i < n) {
            if (dominoes[i] == 'L') {
                int j = i - 1;
                while (j >= 0 && ans[j] == '.') {
                    ans[j--] = 'L';
                }
                i++;
            }
            else if (dominoes[i] == 'R') {
                int j = i + 1;
                while (j < n && dominoes[j] == '.') {
                    j++;
                }
                if (j < n && dominoes[j] == 'L') {
                    int left = i + 1;
                    int right = j - 1;
                    while (left < right) {
                        ans[left++] = 'R';
                        ans[right--] = 'L';
                    }
                    i = j + 1;
                } else {
                    for (int k = i + 1; k < j; ++k) {
                        ans[k] = 'R';
                    }
                    i = j;
                }
            } else {
                i++;
            }
        }

        return ans;
    }
};
