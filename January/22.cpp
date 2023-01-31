class Solution {
public:

    void fin(string &s, string x, vector<string>& val, int pos, int dot){
        int len=s.length();
        if(pos==len ) {
            x.pop_back();
            if(dot==0)val.push_back(x);
            return;
        }
        else if( !dot)return;

        if(s[pos]=='0'){
            fin(s,x+"0.",val,pos+1,dot-1);
            return;
        }

        int num=0;
        for(int i=pos;i<len;i++){
            num = num*10  + (s[i]-'0');
            if(num>255)break;
            x.push_back(s[i]);
            x.push_back('.');
            fin(s,x,val,i+1,dot-1);
            x.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string>val;
        string x="";
        fin(s,x,val,0,4);
        return val;
    }
};