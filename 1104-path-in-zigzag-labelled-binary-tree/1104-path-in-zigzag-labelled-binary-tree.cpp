class Solution {
public:
    vector<int> pathInZigZagTree(int label) 
    {
        int height=0;
        double h=log2(label);
        if(h-floor(h)==0)
            height=(int)h+1;
        else
            height=ceil(h);
        
        //cout<<"Height"<<height<<endl;
        vector<long long> prefix(height+1,0);
        for(int i=1;i<=height;i++)
            prefix[i]=prefix[i-1]+pow(2,i-1);
        vector<int> ans;
        while(height>1)
        {
            // cout<<"height -"<<height<<" label-"<<label<<endl;
            ans.push_back(label);
            height--;
            long long prev=prefix[height-1];
            // cout<<"Prev- "<<prev<<endl;
            long long curr=prefix[height];
             // cout<<"Curr- "<<curr<<endl;
            int parent=label/2;
            // cout<<"Actual parent- "<<parent<<endl;
            int rem=curr-parent;
            // cout<<"Remaining- "<<rem<<endl;
            label=prev+rem+1;
            // cout<<"label- "<<label<<endl;
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};