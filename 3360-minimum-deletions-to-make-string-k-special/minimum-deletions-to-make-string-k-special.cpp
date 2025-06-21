class Solution {
public:
    int minimumDeletions(string word, int k) {
        
       vector<int> f(26,0);
       for(int i=0;i<word.size();i++){
        f[word[i]-'a']++;
       }

        int del=INT_MAX;

    //    sort(f.rbegin(),f.rend());

       for(int i=0;i<f.size();i++){
        int locdel=0;
        if(f[i]==0)
        continue;
        for(int j=0;j<f.size();j++){
            if(j==i or f[j]==0)
                continue;
            
            if(f[j]<f[i]){
                locdel+=f[j];
            }

            else{
                if(abs(f[i]-f[j])>k){
                    locdel+=abs(f[i]-f[j])-k;
                }
            }

           
        }

        del=min(del,locdel);
       }
       return del;
    }
};