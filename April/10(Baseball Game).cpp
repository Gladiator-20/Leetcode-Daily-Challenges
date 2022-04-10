class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int>x;
        for(string i:ops)
        {
            if(i=="+")
            {
                int a=x.back();x.pop_back();
                int b=x.back();
                // x.push_back(b);
                x.push_back(a);
                x.push_back(a+b);
            }
            else if(i=="D")
            {
                int a=x.back();
                x.push_back(a*2);
            }
            else if(i=="C")x.pop_back();
            else x.push_back(stoi(i));
        }
        int val=0;
        for(int i:x)val+=i;
        return val;
    }
};