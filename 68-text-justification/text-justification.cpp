class Solution {
public:
string pass(vector<string> words,int c, int w){
    if(words.size()==1)
    {
        string space(w-words[0].size(),' ');
        return words[0]+space;
    }
    int gs=words.size()-1;
    int rem=w-c;
    int necessaryGap=rem/gs;
    int fp=rem-gs*necessaryGap;
    // cout<<"Word count"<<c<<endl;
    // cout<<necessaryGap<<endl;
    // cout<<fp<<endl;
    string normalGap(necessaryGap,' ');
    string ans="";
    for(int i=0;i<words.size();i++){
        ans=ans+words[i];
        if(i==words.size()-1)
            continue;
        ans=ans+normalGap;
        if(fp>0){
            fp--;
            ans=ans+" ";
        }
    }
    return ans;
}
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> currStack;
        vector<string> ans;
        int c=0;
        for (int i=0;i<words.size();i++){
            c+=words[i].size();
            if(c+currStack.size()>maxWidth){
                c=c-words[i].size();
                string temp=pass(currStack,c,maxWidth);
                ans.push_back(temp);
                c=words[i].size();
                currStack.clear();
                
            }
            currStack.push_back(words[i]);

        }
        string temp="";
        if(currStack.size()!=0)
        {
            for(auto it:currStack)
            temp=temp+it+" ";
        }

        temp.pop_back();
        int k=maxWidth-temp.size();
        string add(k,' ');
        temp=temp+add;
        ans.push_back(temp);
        return ans;
    }
};