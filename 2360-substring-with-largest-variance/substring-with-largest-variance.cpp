class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        unordered_map<char,int> u;
        for(auto it:s)
            u[it]++;
        for(char ch='a';ch<='z';ch++){
             for(char ch1='a';ch1<='z';ch1++){
                if(ch==ch1)
                continue;
                int remb=u[ch1];
                int a=0,b=0;
                int c=0;
                for(auto it:s){
                    if(it!=ch and it!=ch1)
                    continue;
                    if(it==ch)
                    a++;
                    else{
                    b++;
                    remb--;
                    }

                    if(a>b and b>0){
                        ans=max(ans,a-b);

                    }
                    if(b>a){
                        if(remb>0){
                            a=0,b=0;
                        }
                    }
                }
             }
        }
        return ans;
    }
};