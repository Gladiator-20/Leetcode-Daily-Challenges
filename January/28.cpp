class SummaryRanges {
    set<pair<int,int>>range;
public:
    SummaryRanges() {
        while(range.size())range.erase(range.begin());        
    }
    
    void addNum(int value) {
        if(!range.size())
        {
            range.insert({value,value});
            return;
        }
        auto x = range.lower_bound({value,0});
        if(x==range.end()){
            --x;
            if(x->second+1<value)range.insert({value,value});
            else if(x->second+1==value){
                int first=x->first;
                range.erase(x);
                range.insert({first,value});
            }
        }
        else if(range.begin()==x){
            if(x->first-1>value)range.insert({value,value});
            else if(x->first-1==value){
                int second=x->second;
                range.erase(x);
                range.insert({value,second});
            }
        }
        else{
            if(x->first==value)return;
            else if(x->first-1==value){
                
                int tem=x->second;
                auto y=x;
                --y;
                if(y->second+1==value){
                    int first=y->first;
                    range.erase(y);
                    range.erase(x);
                    range.insert({first,tem});
                    return;
                }
                range.erase(x);
                range.insert({value,tem});
            }
            else {
                --x;
                if(x->second+1==value){
                    int first=x->first;
                    range.erase(x);
                    range.insert({first,value});
                    return;
                }
                else if(x->second<value){
                    range.insert({value,value});
                }
            }
        }

    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        for(auto i:range)ans.push_back({i.first,i.second});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */