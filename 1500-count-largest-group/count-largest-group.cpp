class Solution {
public:
    int sum(int a){
        int s=0;
        while(a>0)
        {
            s+=a%10;
            a/=10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        
        unordered_map<int,int> u;
        unordered_map<int,int> du;
        int largest=1;
        for(int i=1;i<=n;i++){
            int a=sum(i);
            u[a]++;
            largest=max(largest,u[a]);
        }
        int f=0;
        for(auto it:u){
            if(it.second==largest)
            f++;
            // cout<<it.first<<" "<<it.second<<endl;
        }

            return f;      

    }
};