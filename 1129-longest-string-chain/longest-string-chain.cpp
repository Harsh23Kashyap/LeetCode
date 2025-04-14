class Solution {
public:
bool canbepredecessor(string a, string b){
    bool used=false;
    int i=0,j=0;
    while(i<a.size() and j<b.size()){
        if(a[i]!=b[j]){
            if(used)
                return false;
            else
                j++;
        
        }
        else{
        i++,j++;
        }

    }
    if(i==a.size() and j==b.size()-1)
        return !used;
    return i==a.size() and j==b.size();
}

static bool cmp(string &a, string &b){
    if(a.size()!=b.size()){
        return a.size()<b.size();
    }
    return a<b;
}
    int longestStrChain(vector<string>& words) {
        int maxi=1;
        sort(words.begin(),words.end(),cmp);
        for(int i=0;i<words.size();i++)
        cout<<words[i]<<endl;

        vector<int> dp(words.size(),1);
        
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++)
            {
                if(words[i].size()-1==words[j].size()){
                    if(canbepredecessor(words[j],words[i])){
                        dp[i]=max(dp[i],dp[j]+1);
                        maxi=max(maxi,dp[i]);
                    }
                }
            }
        }
        return maxi;


        return maxi;

    }
};