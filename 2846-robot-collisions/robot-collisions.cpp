class Solution {
public:
// typedef pair<pair<int,int>, pair<int,char>> pp;
typedef tuple<int,int,int,char> pp; 
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pp> v;

        for(int i=0;i<positions.size();i++)
            v.push_back({positions[i],healths[i],i,directions[i]});


        sort(v.begin(),v.end());

        stack<pp> st;

        st.push(v[0]);

        for(int j=1;j<v.size();j++){ 
            auto [pos,hea,i,dir]=v[j]; 
            bool toadd=true;
            while(!st.empty()){
                auto [npos,nhea,ni,ndir]=st.top(); 

                if(ndir==dir or (ndir=='L' and dir=='R')){
                    break;
                }

                else{
                    if(hea<nhea){
                        toadd=false;
                        st.pop();
                        st.push({npos,nhea-1, ni,ndir});
                        break;
                    }
                    else if(hea==nhea){
                        toadd=false;
                        st.pop();
                        break;
                    }
                    else{
                        hea--;
                        st.pop();
                    }
                }

                
            }
            if(toadd)
                st.push({pos,hea,i,dir});
        }
        vector<int> ans(positions.size(),-1);
        int n=st.size()-1;
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            
            ans[get<2>(it)]=get<1>(it) ;// it.first.second;
        }
         vector<int> res;
         for(auto it:ans){
            if(it!=-1)
                res.push_back(it);
         }

         return res;


        

    }
};