class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        unordered_map<int,int> u;
        for(auto it:digits)
            u[it]++;
        unordered_map<int,int> a;
                
      for(int i=1;i<=9;i++){
        a[i]++;
        for(int j=0;j<=9;j++){
            a[j]++;
            for(int k=0;k<=9;k+=2){
                cout<<i*100+j*10+k<<endl;
                a[k]++;
                bool possible=true;
                for(auto it:a){
                    cout<<it.first<<" "<<it.second<<". ->"<<u[it.first]<<endl;
                    if(u.find(it.first)==u.end() or u[it.first]<it.second){
                        cout<<"yo"<<endl;
                        possible=false;
                        break;
                    }
                    

                }
                if(possible){
                     int ki=i*100+j*10+k;
                    ans.push_back(ki);
                }
                a[k]--;
            }
            a[j]--;
        }
        a[i]--;
      }
    //   sort(ans.begin(),ans.end());
      return ans;
    }
};