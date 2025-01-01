class Solution {
    public int maxScore(String s) {
    int n = s.length();
    
    // Arrays to store the prefix counts of '0's and suffix counts of '1's
    int[] prefix = new int[n - 1];
    int[] suffix = new int[n - 1];
    
    // Count of '0's for prefix array
    int count0 = 0;
    
    // Fill the prefix array
    for (int i = 0; i < n - 1; i++) {
        if (s.charAt(i) == '0') {
            count0++;
        }
        prefix[i] = count0;
    }
    
    // Count of '1's for suffix array
    int count1 = 0;
    
    // Fill the suffix array
    for (int i = n - 1; i > 0; i--) {
        if (s.charAt(i) == '1') {
            count1++;
        }
        suffix[i - 1] = count1;
    }
    
    // Variable to store the maximum score
    int ans = Integer.MIN_VALUE;
    
    // Calculate the maximum score by iterating through possible split points
    for (int i = 0; i < n - 1; i++) {
        int sum = prefix[i] + suffix[i];
        if (ans < sum) {
            ans = sum;
        }
    }
    
    return ans;
}

}