class Solution {
public:
vector<bool> col;
unordered_map<int,bool> ldiag;
unordered_map<int,bool> rdiag;
bool possible( vector<string> &a, int i, int k){

   if(not(ldiag.find(i-k)==ldiag.end() or (ldiag.find(i-k)!=ldiag.end() and ldiag[i-k]==false)))
    return false;

 if(not(rdiag.find(i+k)==rdiag.end() or (rdiag.find(i+k)!=rdiag.end() and rdiag[i+k]==false)))
    return false;

    return true;
    

}
    void pass(vector<vector<string>>&ans,  vector<string> &a, int i){
        if(i==a.size()){
            ans.push_back(a);
            return;
        }
        
        for(int k=0;k<a.size();k++){
            if(col[k]==false and possible(a,i,k)){
                a[i][k]='Q';
                col[k]=true;
                ldiag[i-k]=true;
                rdiag[i+k]=true;
                pass(ans,a,i+1);
                a[i][k]='.';
                col[k]=false;
                 ldiag[i-k]=false;
                rdiag[i+k]=false;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        col.assign(n,false);
        vector<string> a(n, string(n,'.'));

        vector<vector<string>> ans;

         pass(ans,a,0);
         return ans;

    }
};