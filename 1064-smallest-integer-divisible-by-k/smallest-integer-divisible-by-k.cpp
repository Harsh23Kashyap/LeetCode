class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==2 or k==5 or k==4 or k==6)
        return -1;
        unordered_set<int> u;
        int r=1;
        int sz=1;
        while(true){
            cout<<r<<endl;
            if(r%k==0)
                return sz;
            
            r=((r%k)*(10%k)+(1%k))%k;
            
            if(u.find(r)!=u.end())
                return -1;
            u.insert(r);
            sz++;
        }
        return -1;
    }
};