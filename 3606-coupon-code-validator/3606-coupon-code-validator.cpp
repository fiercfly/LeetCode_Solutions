// class Solution {
// public:
//     bool isValid(string s){
//         for(int i: s){
//             if(i >= 48 && i<=57 || i>=65 && i<=90 || i>= 97 && i<= 122 || i==95){
//                 return true;
//             }
//         }
//         return false;
//     }
//     vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
//         vector<string> el;
//         vector<string> gr;
//         vector<string> ph;
//         vector<string> re;

//         for(int i=0; i<code.size(); i++){
//             if(code[i].length() == 0 || !isValid(code[i])){
//                 continue;
//             }
//             if(businessLine[i] == "electronics") el.push_back(code[i]);
//             else if(businessLine[i] == "grocery") gr.push_back(code[i]);
//             else if(businessLine[i] == "pharmacy") ph.push_back(code[i]);
//             else if(businessLine[i] == "restaurant") re.push_back(code[i]);
//         }

//         vector<string> ans;
        
//     }
// };









class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();

        // Mapping from business line name to its required sort order
        unordered_map<string, int> businessLineSortOrder = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        // Store each valid coupon with the information needed for sorting
        // First field: (business line order, code), Second field: code string
        vector<pair<pair<int, string>, string>> sortableCoupons;

        for (int i = 0; i < n; ++i) {
            // Check coupon is currently active
            if (!isActive[i]) continue;

            // Check if business line is valid
            if (businessLineSortOrder.find(businessLine[i]) == businessLineSortOrder.end()) continue;

            // Check if code is non-empty and only alphanumeric or underscore
            if (code[i].empty()) continue; //""
            bool isCodeValid = true;
            for (char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    isCodeValid = false;
                    break;
                }
            }
            if (!isCodeValid) continue;

            // Everything is valid, collect coupon for sorting
            int sortIndex = businessLineSortOrder[businessLine[i]];
            sortableCoupons.push_back({{sortIndex, code[i]}, code[i]});
        }

        // Sort by business line order, then code alphabetically
        sort(sortableCoupons.begin(), sortableCoupons.end());

        // Gather the sorted coupon codes
        vector<string> sortedValidCodes;
        for (auto& entry : sortableCoupons) {
            sortedValidCodes.push_back(entry.second);
        }

        return sortedValidCodes;
    }
};