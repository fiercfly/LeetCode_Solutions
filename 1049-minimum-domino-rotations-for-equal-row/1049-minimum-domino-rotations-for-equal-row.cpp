class Solution {
public:
//there can be 4 combinations possible: tops swap, tops no swap, bottms swap and bottoms no swap

//1st approach*********************************


    // int noSwap(vector<int> tops, vector<int> bottoms, int itr1, int swap){
    //     int swaps= swap;
    //     int n= tops.size();
    //     for(int i=1; i<=n; i++){
    //         if(i == n){
    //             break;
    //         }
    //         else if(tops[i] != itr1 && bottoms[i] != itr1){
    //             swaps= 1e9;
    //             break;
    //         }
    //         else if(tops[i] == itr1){
    //             continue;
    //         }
    //         else{
    //             swaps++;
    //         }
    //     }
    //     return swaps;
    // }
    // int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    //     int itr1= tops[0];
    //     int itr2= bottoms[0];

    //     int swap1= noSwap(tops, bottoms, itr1, 0);
    //     int swap2= noSwap(tops, bottoms, itr2, 1);
    //     int swap3= noSwap(bottoms, tops, itr1, 1);
    //     int swap4= noSwap(bottoms, tops, itr2, 0);
    //     // cout<<swap1<<" "<<swap2<<" "<<swap3<<" " <<swap4;
        
    //     // cout<<swap1<<" "<<swap2<<" "swap3<<" ";

    //     if(swap1 != 1e9 || swap2 != 1e9 || swap3 != 1e9 || swap4 != 1e9) 
    //         return min({
    //             swap1,
    //             swap2,
    //             swap3,
    //             swap4
    //         });
    //     else return -1;
    // }

//2nd approach********************************

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans= INT_MAX;
      

        for(int i=1; i<= 6; i++){
            int tswap= 0;
            int bswap= 0;
            for(int j=0; j<tops.size(); j++){
                if(tops[j] != i && bottoms[j] != i){
                    //impossible
                    tswap= INT_MAX;
                    bswap= INT_MAX;
                    break;
                }
                if(tops[j] != i){
                    tswap++;
                }
                if(bottoms[j] != i){
                    bswap++;
                }
            }
            ans= min(ans, min(tswap, bswap));
        }
        return ans==INT_MAX? -1: ans;
    }
};

//DOmino Rotations
//TOps: top half
//Btms: bottom half
//we have to check for wither top[0] or bottom[0] to get the answer, other than that we have to return -1

//iterations: 2
//it3r 1: check for tops[0] in the whole array, if not found return-1

