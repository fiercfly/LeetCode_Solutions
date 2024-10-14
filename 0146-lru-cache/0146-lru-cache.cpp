#pragma GCC optimize("Ofast")
class LRUCache {
public:
    //Map will be containing key and value and value will get stored in double linked list
    //create doubly linkedlist:
    class node{
        public:
        //key value, 2 pointer: next and prev
        int key; 
        int val;
        node *next;
        node *prev;

        //initialise key and value whenever we write node with key and val as argument
        node(int k, int v){
            key= k;
            val= v;
        }
    };

    node *head= new node(-1, -1);
    node *tail= new node(-1, -1);

    int cap;
    unordered_map<int, node* > mp; //store int and node in map

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

            //node delete..
            mp.erase(key);
            deleteNode(resNode);

            //add just after the head
            addNode(resNode);
            mp[key]= head->next;


            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        //if already exists in map then remove that node else remove last node(least used)
        if(mp.find(key)!= mp.end()){
            node *oldNode= mp[key];
            mp.erase(key);
            deleteNode(oldNode);
        }
        if(mp.size()== cap){
            mp.erase(tail->prev->key);
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