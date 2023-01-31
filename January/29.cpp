struct node{
    int val,key,freq;
    node* prev;
    node* next;
    node(int k,int v)
    {
        key=k;
        val=v;
        freq=1;
        prev=NULL;
        next=NULL;
    }
};

struct lis{
    node* head;
    node* tail;
    int size;
    lis()
    {
        head =new node(0,0);
        tail=new node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void addnode(node* temp)
    {
        temp->next=head->next;
        temp->next->prev=temp;
        head->next=temp;
        temp->prev=head;
        size++;
    }
    
    void deletenode(node* temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete(temp);
        size--;
    }
};

class LFUCache {
    unordered_map<int ,node*>keynode;
    unordered_map<int ,lis*>freqlist;
    int maxcap;
    int currsize;
    int minfreq;
public:
    LFUCache(int capacity) {
        maxcap=capacity;
        currsize=0;
        minfreq=0;
    }
    
    void updatefreq(node* target)
    {
        keynode.erase(target->key);
        // node* target=keynode[key];
        int f=target->freq;
        
        freqlist[f]->deletenode(target);
        if(minfreq==f && freqlist[f]->size==0){
            minfreq+=1;
        }
        
        lis* newlist=new lis();
        if(freqlist.find(f+1)!=freqlist.end())
        {
            newlist=freqlist[f+1];
        }
        
        newlist->addnode(target);
        target->freq=f+1;
        freqlist[target->freq]=newlist;
        keynode[target->key]=target;
    }
    
    int get(int key) {
        if(keynode.find(key)!=keynode.end()){
            node *target=keynode[key];
            int ans=target->val;
            updatefreq(target);
            return ans;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(maxcap==0){return ;}
        if(keynode.find(key)!=keynode.end())
        {
            node* target=keynode[key];
            target->val=value;
            updatefreq(target);
        }
        else {
            if(maxcap==currsize)
            {
                lis* tar=freqlist[minfreq];
                keynode.erase(tar->tail->prev->key);
                tar->deletenode(tar->tail->prev);
                currsize--;
            }
            currsize++;
            minfreq=1;
            
            node* newnode=new node(key,value);
            // keynode[key]=newnode;
            lis* tarlist=new lis();
            if(freqlist.find(1)!=freqlist.end())
            {
                tarlist=freqlist[1];
            }
            
            tarlist->addnode(newnode);
            freqlist[1]=tarlist;
            keynode[key]=newnode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */