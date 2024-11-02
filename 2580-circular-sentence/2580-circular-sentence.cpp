auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        string temp= "";
        for(char c: sentence){
            if(c != ' '){
                temp+= c;
            }
            else{
                words.push_back(temp);
                temp= "";
            }
        }
        words.push_back(temp);
        //words have been taken out from the sentence in words vector

        for(int i=1; i<words.size(); i++){
            if(words[i-1][words[i-1].size()-1] != words[i][0]){
                return false;
            }
        }
        // cout<<words[0][0]<<" "<<words[words.size()-1][words[words.size()-1].length()-1]<<endl;
        if(words[0][0]!= words[words.size()-1][words[words.size()-1].length()-1]){
            return false;
        }
        return true;
    }
};