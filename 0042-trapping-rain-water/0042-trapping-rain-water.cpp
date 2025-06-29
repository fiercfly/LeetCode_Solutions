class Solution {
public:
    int trap(vector<int>& height) {
        int right= height.size()-1;
        int left= 0;
        int leftMax= left;
        int rightMax= right;
        int paani= 0;
        while(left<= right){
            //2 cases: if left is smaller and if right is smaller
            if(height[left]<= height[right]){
                if(height[left]>= height[leftMax]){
                    leftMax= left;
                }
                else{
                    paani+= height[leftMax]-height[left];
                }
                left++;
            }
            else{
                if(height[right]>= height[rightMax]){
                    rightMax= right;
                }
                else{
                    paani+= height[rightMax]-height[right];    
                }
                right--;
            }  
        }
        return paani;
    }
};