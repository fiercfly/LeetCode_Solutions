class Solution {
public:
    // int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    //     sort(tasks.rbegin(), tasks.rend());
    //     sort(workers.rbegin(), workers.rend());

    //     int count = 0;

    //     int i=0;
    //     int j=0;

    //     int wrkr= workers.size();
    //     int tsks= tasks.size();

    //     while(i<wrkr && j<tsks){
    //         if(workers[i] >= tasks[j]){
    //             workers[i]= -1;
    //             tasks[j]= -1;
    //             count++;
    //             i++;
    //             j++;
    //         }
    //         else{
    //             j++;
    //         }
    //     }

        
    //     i= 0;
    //     j= 0;
    //     while(i<wrkr && workers[i] == -1){
    //         i++;
    //     }
    //     while(j< tsks && tasks[j] == -1){
    //         j++;
    //     }
    //     while(i<wrkr && j< tsks){
    //         if((workers[i]+ strength)>= tasks[j] && pills>0){
    //             count++;
    //             do{i++;}
    //             while(i<wrkr && workers[i] == -1);

    //             do{j++;}
    //             while(j<tsks && tasks[j] == -1);

    //             pills--;
    //         } 
    //         else{
    //             do{j++;}
    //             while(j<tsks && tasks[j] == -1);
    //         }
    //     }

    //     return count;

    // }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
         sort(tasks.begin(), tasks.end());
         sort(workers.begin(), workers.end());
         int low= 0;
         int high= min(tasks.size(), workers.size());

         while(low < high){
            int mid= (low+ high+1 )/2;
            if(canAssign(tasks, workers, pills, strength , mid)){
                low= mid;
            }
            else{
                high= mid-1;
            }
         }
         return low;
    }

    bool canAssign(vector<int> &tasks, vector<int> workers, int pills, int strength, int taskCount){
        deque<int> boosted;
        int w= workers.size()-1;
        int freePills= pills;
        for(int t= taskCount-1; t>= 0; t--){
            int task= tasks[t];
            if(!boosted.empty() && boosted.front() >= task){
                boosted.pop_front();
            }
            else if(w>= 0 && workers[w]>= task){
                w--;
            }
            else{
                while(w>= 0 && workers[w]+strength >= task){
                    boosted.push_back(workers[w]);
                    w--;
                }
                if(boosted.empty() || freePills == 0){
                    return false;
                }
                boosted.pop_back();
                freePills--;
            }
        }
        return  true;

    }

};

