class Solution {
public:
    pair<int,int> divisor(int a){
        int c=0,s=0;
        for(int i=2;i<=a/2;i++){
            if(a%i==0){
                // cout<<i<<endl;
                c++;
                s+=i;
            }
        }
        // cout<<c+2<<endl;
        return {c+2,s+1+a};
    }
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int,int> u;
        int c=0;
        for(auto it:nums){
            if(u.find(it)!=u.end()){
                if(u[it]!=-1)
                    c+=u[it];
            }
            else{
                auto a=divisor(it);
                if(a.first==4){
                    u[it]=a.second;
                    c+=a.second;
                }
                else{
                    u[it]=-1;
                }
            }
        }
        return c;
    }
};