class Solution {
public:
long long ans=0;
     unordered_map<int, vector<pair<int,char>>> u;
    unordered_map<int,int> freq;
    void dfs(int i, int mask,int par){

        for(auto [ne,val]:u[i]){ 
            if(par==ne)
             continue;
            int cmask=mask ^ (1<<(val-'a')); 
          ans += freq[cmask];

for(int b = 0; b < 26; b++) {
    ans += freq[cmask ^ (1 << b)];
}

freq[cmask]++;
            dfs(ne,cmask,i);
            // freq[cmask]--;
        }
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
       

       for(int i=1;i<parent.size();i++){
            u[i].push_back({parent[i],s[i]});
            u[parent[i]].push_back({i,s[i]});
       }

    freq[0] = 1;  
        dfs(0,0,-1); 
       return ans;
    }
};