class Solution {
public:
vector<bool> col;
bool possible( vector<string> &a, int i, int k){

    int tr=i-1;
    int tc=k-1;
    while(tc>=0 and tr>=0){
        if(a[tr][tc]=='Q')
            return false;
            tr--,tc--;
    }
    tr=i-1,tc=k+1;
    while(tr>=0 and tc<a.size()){
        if(a[tr][tc]=='Q')
            return false;
            tr--,tc++;
    }
    return true;
}
    void pass(vector<vector<string>>&ans,  vector<string> &a, int i){
        if(i==a.size()){
            ans.push_back(a);
        }
        
        for(int k=0;k<a.size();k++){
            if(col[k]==false and possible(a,i,k)){
                a[i][k]='Q';
                col[k]=true;
                pass(ans,a,i+1);
                a[i][k]='.';
                col[k]=false;
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