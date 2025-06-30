class Solution {
public:
    int maximumSwap(int num) {
        
        unordered_map<int,int> m;
        string s=to_string(num);
        for(int i=0;i<s.size();i++){
            m[s[i]-'0']=i;
        }


      for(int i=0;i<s.size();i++){
        cout<<s[i]<<endl;
        for(int j=9;j>s[i]-'0';j--){
            if(m.find(j)!=m.end() and m[j]>i){
                cout<<"replace with "<<j<<endl;
                if(m[j]==i)
                continue;
                swap(s[m[j]],s[i]);

                return stoi(s);
            }
        }

      }
      return num;

        
    }
};