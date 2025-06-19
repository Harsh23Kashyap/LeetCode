class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1)
        return word;
        int n=word.size();
        int maxSize=n-numFriends;
        // cout<<maxSize<<endl;
        int i=0;
        string best="";
        best+=word[0];
        while(i<word.size()){
            if(word[i]>=best[0]){
                int j=1;
                string currw="";
                currw+=word[i];
                // cout<<j<<" ";
                while(j<=maxSize and i+j<n){

                    int curr=i+j;
                    // cout<<curr<<endl;
                    // if(j<best.size() and best[j]>word[curr]){
                    //     cout<<"break"<<endl;
                    //     break;
                    // }
                    currw+=word[curr];
                    
                    j++;

                }
                // cout<<currw<<endl;
                int k=0;
                bool broken = false;
                while(k<min(currw.size(),best.size())){
                    if(currw[k]>best[k]){
                        best=currw;
                        broken=true;
                        break;
                    }
                    else if(currw[k]<best[k]){
                          broken=true;
                        break;
                    }
                    k++;
                }
                if(!broken){
                    if(currw.size()>best.size())
                    best=currw;
                }
                
            }
            i++;
        }
        return best;
    }
};