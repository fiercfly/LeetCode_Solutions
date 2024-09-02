class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(int i=0; i<chalk.size(); i++){
            sum+= chalk[i];
        }
        k= k%sum;

        int stud= 0;
        while(k-chalk[stud] >=0){
            k= k-chalk[stud];
            cout<<k<<endl;
            stud++;

            if(stud > chalk.size()-1){
                stud= 0;
            }
        }
        return stud;
    }
};