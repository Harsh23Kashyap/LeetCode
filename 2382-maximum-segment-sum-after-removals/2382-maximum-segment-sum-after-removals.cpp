class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) 
    {
        int n=nums.size();
        vector<long long> ans;
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+nums[i];
        
        
        multiset<long long> m;
        m.insert(0);
        m.insert(prefix[n-1]);
        
        set<int> s;
        s.insert(n);
        s.insert(-1);
        
        for(int i:removeQueries)
        {
            cout<<i<<endl;
            auto it = s.lower_bound(i);
            int r=*it;
            int l=*(--it);
            //cout<<l<<" - "<<r<<endl;
            long long curr=prefix[r-1]-((l==-1)?0:prefix[l]);
            //cout<<"Sum->"<<curr<<endl;
            m.erase(m.find(curr));
                                        
                                        
            long long leftV=((i==0)?0:prefix[i-1])-((l==-1)?0:prefix[l]);
            //cout<<"Left Sum->"<<leftV<<endl;
            long long rightV=prefix[r-1]-prefix[i];
            //cout<<"Right Sum->"<<rightV<<endl;
            m.insert(leftV);
            m.insert(rightV);
            
            s.insert(i);
            ans.push_back(*(m.rbegin()));
        }
            
        return ans;
    }
};