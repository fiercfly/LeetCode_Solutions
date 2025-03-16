class Solution {
public:
    bool timeIsSuff(vector<int>& ranks, int cars, long long minGiven){
        long long carsDone = 0;
        for (int r : ranks) {
            long c2 = minGiven / r;
            long c = floor(sqrt(c2));
            carsDone += c;
        } 
        return carsDone >= cars;
    }



    // ______________________________________
    // |        //      ...                 |
    // |        //     .   .                |
    // |        //    .     .               |
    // |        //   .       .              |
    // |        //  .         .             |
    // |        // .   AkShT   .            |
    // |        //  .  JaIn   .             |
    // |        //   .       .              |
    // |        //    .     .               |
    // |        //     .   .                |
    // |        //      ...                 |
    // |____________________________________|



    long long repairCars(vector<int>& ranks, int cars){
        long l = 1, r = 1e14;
        while (l < r) {
            long mid = (l + r) / 2;
            if(timeIsSuff(ranks, cars, mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};