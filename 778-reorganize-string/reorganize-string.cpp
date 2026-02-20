class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> u;
        for(auto it:s){
            u[it]++;
        }

        priority_queue<pair<int,char>> pq    ;
        for(auto it:u){
            pq.push({it.second, it.first});
        }
        string ans="";
        
        while(pq.size()>1){
            auto [c1,s1]=pq.top();
            pq.pop();
            auto [c2,s2]=pq.top();
            pq.pop();


            ans+=s1;
            ans+=s2;
            c1--,c2--;

            if(c1>0){
                pq.push({c1,s1});
            }
            if(c2>0){
                pq.push({c2,s2});
            }


        }

        if(!pq.empty()){
            auto [c1,s1]=pq.top();
            if(c1>1){
                return "";
            }
            ans+=s1;
        }
        return ans;
    }   
};