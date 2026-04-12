
#include <bits/stdc++.h>
using namespace std;


// 🔧 YOUR FUNCTION (fill this)
string alienOrder(vector<string>& words) {
    unordered_set<char> vis;
    unordered_map<char, unordered_set<char>> u;
    
    unordered_map<char,int> indeg;
    for(auto it:words){
        for(auto c:it)
        {
            vis.insert(c);
            indeg[c]=0;
            
        }
    }
    for(int i=1;i<words.size();i++){
        string a=words[i-1];
        string b=words[i];
        bool found=false;
        for(int j=0;j<min(a.size(),b.size());j++){
            if(a[j]==b[j])
                continue;
            else{
                u[a[j]].insert(b[j]);
                found=true;
                break;
            }
            
            
        }
        if(!found){
            if(a.size()>b.size())
                return "";
            
        }
        
    }
    
    
    
    
    for(auto it:u){ 
        for(auto j:it.second){
            vis.insert(j);
            indeg[j]++;
        }
    }
    queue<char> q;
    for(auto it:indeg)
    {
        if(it.second==0)
            q.push(it.first);
    }
    
    string ans="";
    
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        ans+=it;
        
        for(auto ne:u[it]){
            if(--indeg[ne]==0)
                q.push(ne);
        }
    }
    if(ans.size()!=vis.size())
        return "";
    return ans;
    
    
    
    
    
}


// 🧪 HELPER: compare answers (multiple valid answers possible)
bool isValid(string order, vector<string>& words) {
    if(order == "") return false;

    unordered_map<char, int> pos;
    for(int i = 0; i < order.size(); i++) {
        pos[order[i]] = i;
    }

    for(int i = 0; i < words.size() - 1; i++) {
        string a = words[i], b = words[i+1];
        int len = min(a.size(), b.size());
        bool found = false;

        for(int j = 0; j < len; j++) {
            if(a[j] != b[j]) {
                if(pos[a[j]] > pos[b[j]]) return false;
                found = true;
                break;
            }
        }

        if(!found && a.size() > b.size()) return false;
    }
    return true;
}


// 🧪 TEST DRIVER
int main() {
    vector<vector<string>> tests = {
        {"wrt","wrf","er","ett","rftt"},
        {"z","x"},
        {"z","x","z"},
        {"abc","ab"} // invalid case
    };

    for (auto &words : tests) {
        cout << "Test: ";
        for (auto &w : words) cout << w << " ";
        cout << "\n";

        string my = alienOrder(words);
        string correct = correctAnswer(words);

        cout << "Your Output: " << my << "\n";
        cout << "Correct (one possible): " << correct << "\n";

        if (correct == "") {
            if (my == "") cout << "✅ PASS\n";
            else cout << "❌ FAIL\n";
        } else {
            if (isValid(my, words)) cout << "✅ PASS\n";
            else cout << "❌ FAIL\n";
        }

        cout << "--------------------------\n";
    }

    return 0;
}