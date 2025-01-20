class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> r;
        unordered_map<int,int> c;

        int m=mat.size(),n=mat[0].size();
        unordered_map<int,int> tr;
        unordered_map<int,int> tc;
         for(int i=0;i<mat.size();i++)
            tr[i]=n;
         for(int i=0;i<mat[0].size();i++)
            tc[i]=m;   

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++)
            {
                int t=mat[i][j];
                r[t]=i;
                c[t]=j;
            }
        }


        for(int i=0;i<arr.size();i++)
        {
            int ttc=arr[i];
            int cr=r[ttc];
            int cc=c[ttc];
            tr[cr]--;
            tc[cc]--;
            if(tr[cr]==0)
            return i;
            if(tc[cc]==0)
            return i;
        }
        return -1;
        
        
    }
};