/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        if(root!= NULL){
            for(int i=0; i<root->children.size(); i++){
                postorder(root->children[i]);
                // ans.push_back(root->children[i]->val);
            }
            ans.push_back(root->val);

        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();