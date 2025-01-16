class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans= 0;

        int xorNum1=0;
        int xorNum2= 0;

        for(int i: nums1){
            xorNum1^= i;
        }
        
        for(int j: nums2){
            xorNum2^= j;
        }
        cout<<xorNum1<<" "<<xorNum2<<endl;

        //conditions :)

        if(nums1.size()%2==0 && nums2.size()%2 == 0){
            return 0; //Both even
        }
        else if(nums1.size()%2==1 && nums2.size() %2== 0){
            return xorNum2; //nums1 odd nums2 even
        }
        else if(nums1.size()%2==0 && nums2.size()%2== 1){
            return xorNum1; //nums1 even nums2 odd
        }
        else
            return xorNum1^ xorNum2; //both odd
    }
};

/*

****OBSERVATIONS****

num1 xor num2

Odd size of num1 && num2 of Even size: num1 will cancel each other in xor => return xor of num2
if both of even size => return 0(all will cancel out)
Even size of num1 && num2 of Odd size: num2 will cancel out each other in xor so return xor of num1
if(both are of Odd size) => return xor of num1^ xor of num2 (all will cancel out only 1-1 of them will remain in the end)


13
14
23
24

2 10


*/