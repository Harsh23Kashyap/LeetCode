class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        vector<int> ans;
        int last_i=0,last_j=0;
        bool up=true;
        bool downnow=false;
        while(true){
            if(downnow){
                last_i++;
            }
            // cout<<last_i<<" "<<last_j<<endl;
            vector<int> temp;
            for(int i=last_i, j=last_j;i<mat.size() and j>=0;i++,j--){ 
                    // cout<<mat[i][j]<<" ";
                    temp.push_back(mat[i][j]); 
            }
            cout<<endl;
            if(up){
                reverse(temp.begin(),temp.end());
                ans.insert(ans.end(),temp.begin(),temp.end());
                
            }
            else{
                ans.insert(ans.end(),temp.begin(),temp.end());
            }
            up=!up;

            last_j++;
              if(last_j>=mat[0].size()){
                downnow=true;
                last_j=mat[0].size()-1;
              }
            if(last_i>mat.size())
            break;
        }
        return ans;
    }
};