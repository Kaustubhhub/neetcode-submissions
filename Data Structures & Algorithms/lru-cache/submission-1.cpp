class Node{
public:
    int key;
    int val;
    Node* next; 
    Node* prev;
    Node(int k, int v): key(k), val(v), next(nullptr), prev(nullptr) {}
};
class LRUCache {
private:
    unordered_map<int,Node*>cache;
    Node* left;
    Node* right;
    int cap;

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->next = right;
        right->prev = node;
        node->prev = prev;
    }

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }
        Node* newNode = new Node(key,value);
        insert(newNode);
        cache.insert({key, newNode});
        if(cache.size() > cap){
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
        return;
    }
};
