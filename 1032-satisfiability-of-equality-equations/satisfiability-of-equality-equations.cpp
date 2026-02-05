class Solution {
public:
    vector<int> val;
    int find(int x){
        if(val[x]==x)
        return x;
        return val[x]=find(val[x]);
    }

    bool equationsPossible(vector<string>& equations) {
        
       for(int i=0;i<26;i++)
       val.push_back(i);
        for(auto it:equations){
            int a=it[0]-'a';
            int b=it[3]-'a';
            cout<<"a-"<<a<< ",  b"<<b<<endl;
            if(it[1]=='='){
              val[find(a)]=find(b);
            }
            cout<<val[a]<<" "<<val[b]<<endl;
            
        }
 cout<<"hi 1"<<endl;
        for(auto it:equations){
            int a=it[0]-'a';
            int b=it[3]-'a';
            cout<<"hi "<<endl;
            cout<<"a-"<<a<< ",  b"<<b<<endl;
            if(it[1]=='!'){
              if(find(a) == find(b))
              return false;
            }
            
        }
        return true;
    }
};