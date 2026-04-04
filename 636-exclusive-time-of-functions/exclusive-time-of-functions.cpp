class Solution {
public:
    vector<int> parse(string a){
        int id=0;
        string type="";
        int t=0;
        int end=0;

        int i=0; 

        while(i<a.size() and a[i]!=':')
        {
            id=id*10+(a[i]-'0');
            i++;
        }
        i++;
        while(i<a.size() and a[i]!=':')
        {
            type+=a[i];
            i++;
        }
        i++;
        while(i<a.size())
        {
            end=end*10+(a[i]-'0');
            i++;
        }

        if(type=="end")
            t=1;
 

        return {id,t,end};
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        unordered_map<int, int> u;
        vector<int> ans(n,0);
        stack<int> st;
        int curr=-1;

        cout << "Starting processing logs...\n";

        for(auto it:logs){
            cout << "\nProcessing log entry: " << it << endl;

            vector<int> pass=parse(it);

            cout << "Current state -> curr: " << curr << endl;
            cout << "Stack size: " << st.size() << endl;

            if(pass[1]==1){
                cout << "END event for function: " << pass[0] << endl;
                cout << "Start time: " << u[pass[0]] << endl;
                int tt=pass[2]-u[pass[0]]+1;
                cout << "Computed time: " << tt << endl;

                ans[pass[0]]+=tt;

                cout << "Updated ans[" << pass[0] << "] = " 
                     << ans[pass[0]] << endl;

                u.erase(pass[0]);
                cout << "Erased from map: " << pass[0] << endl;

                if(!st.empty()){
                    curr=st.top();
                    cout << "Resuming function from stack: " << curr << endl;

                    u[curr]=pass[2]+1;
                    cout << "Updated start time of resumed function: " 
                         << u[curr] << endl;

                    st.pop();
                }
                else
                    curr=-1;
            }
            else{
                cout << "START event for function: " << pass[0] << endl;

                
                cout << "Set start time in map: " << u[pass[0]] << endl;

                if(curr!=-1){
                    cout << "Pausing current function: " << curr << endl;

                    st.push(curr);
                    cout << "Pushed to stack: " << curr << endl;

                    int tt=pass[2]-u[curr];
                    cout << "Computed time for paused function: " << tt << endl;

                    ans[curr]+=tt;

                    cout << "Updated ans[" << curr << "] = " 
                         << ans[curr] << endl;

                    u.erase(curr);
                    cout << "Erased paused function from map: " << curr << endl;

                    curr=pass[0];
                    cout << "Switched current function to: " << curr << endl;   
                    u[pass[0]]=pass[2];
                }
                else{
                    curr=pass[0];
                    u[pass[0]]=pass[2];
                    cout << "Set current function to: " << curr << endl;
                }
            }
        }

        cout << "\nFinal Answer:\n";
        for(int i=0;i<n;i++){
            cout << "Function " << i << " -> " << ans[i] << endl;
        }

        return ans;
    }
};