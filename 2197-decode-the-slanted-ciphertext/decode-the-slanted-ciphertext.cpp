class Solution {
public:
    string decodeCiphertext(string et, int rows) {
        int m=rows;
        //finding n;
        int tc=et.size();
        int n=tc/m;
        // cout<<" M- "<<m<<" - N- "<<n<<endl;
        vector<vector<char>> mat(m, vector<char> (n,' '));
        int r=0;
        int c=0;
        int i=0;
        while(i<et.size()){
            if(c==n){
                r++;
                c=0;
                continue;
            }
            else if(et[i]!=' '){
                mat[r][c]=et[i];
                c++;i++;
            }
            else{
                c++;
                i++;
            }
        }

        string res="";
        // for(int i=0;i<mat.size();i++){
        //     for(int j=0;j<mat[0].size();j++){
        //         cout<<mat[i][j]<<" ";
        //     }
        //     cout<<endl;

        // }
        for(int i=0;i<n;i++){
            bool nf=false;
            int ni=i,nj=0;
            string curr="";
           while(ni<n and nj<m)
           {
            if(mat[nj][ni]!=' ')
                nf=true;
            curr+=mat[nj][ni];
            nj++,ni++;
           }

            res+=curr;
        }
        i=res.size()-1;
        while(i>=0 and res[i]==' ')i--;
        return res.substr(0,i+1);
    }
};