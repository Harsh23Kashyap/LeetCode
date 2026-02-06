class Solution {
public:
    bool palin(string &s, int i, int j){

        while(i<=j){
            if(s[i]!=s[j])
            return false;
            i++,j--;
        }
        return true;
    }
    int minCut(string &s, int i,  unordered_map<int,int> &u){
        if(i==s.size())
        return 0;

        if(u.find(i)!=u.end())
            return u[i];
        int res=INT_MAX;
        for(int j=i;j<s.size();j++){
            //palindrome fron i to j
            int len=j-i;
            if(palin(s,i,j)){
                // cout<<"Cut after "<<" i "<<i<<" , "<<j<<endl;
                res=min(res,1+minCut(s,j+1,u));
            }
        }
        return u[i]=res;
    }
    int minCut(string s) {
        unordered_map<int,int> m;
        return minCut(s,0,m)-1;
    }
};