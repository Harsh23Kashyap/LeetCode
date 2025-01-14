class Solution {
public:
int findAll(unordered_map<int,int> u){

    int c=0;

    for(auto it:u){
        
        // cout<<it.first<<" "<<t.first<<" "<<t.second<<endl;
        if(it.second==2)
            c++;
        
        
    }
    // cout<<c<<endl;
    //     cout<<endl;
    return c;
}
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> ans;
        unordered_map<int,int> u;
        for(int i=0;i<n;i++)
            u[i]=0;
        for(int i=0;i<n;i++)
        {
            u[A[i]]++;
            u[B[i]]++;
            ans.push_back(findAll(u));

        }
    return ans;
    }
};