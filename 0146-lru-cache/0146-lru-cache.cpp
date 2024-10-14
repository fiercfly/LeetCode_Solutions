class LRUCache {
public:
    //doubly linkedlist banayenge:
    class node{
        public:
        //key value, 2 pointer: next and prev
        int key; 
        int val;
        node *next;
        node *prev;

        //kind of function which will initialise all the key and value
        node(int k, int v){
            key= k;
            val= v;
        }
    };
    node *head= new node(-1, -1);
    node *tail= new node(-1, -1);

    int cap;
    unordered_map<int, node* > mp; //map me int aur node store krenge

    LRUCache(int capacity) {
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }

    //how we will add a node in the list:
    void addNode(node *newNode){
        node *temp= head->next;
        newNode-> next= temp;
        newNode->prev= head;
        head->next= newNode;
        temp->prev= newNode;
    }
    

    //how we will delete  node from the list:
    void deleteNode(node *delNode){
        node *delPrev= delNode->prev;
        node *delNext= delNode->next;
        delPrev->next= delNext;
        delNext->prev= delPrev;
    }

    int get(int key){
        if(mp.find(key)!= mp.end()){
            node* resNode= mp[key];
            int res= resNode->val;

            //node delete crow..
            mp.erase(key);
            deleteNode(resNode);

            //head k just baad add crow
            addNode(resNode);
            mp[key]= head->next;


            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        //if already existing in map then remove that node else remove last node(least used)
        if(mp.find(key)!= mp.end()){
            node *oldNode= mp[key];
            mp.erase(key);
            deleteNode(oldNode);
        }
        if(mp.size()== cap){
            mp.erase(tail->prev->val);
            deleteNode(tail->prev);
        }

        addNode(new node(key, value));
        mp[key]= head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */