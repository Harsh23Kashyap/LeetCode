class Solution {
public:
    void gen(string dig,map<int,string>& m, string s,int i,int curr,vector<string>& res)
    {
        if(i==dig.length())
        {
            //count++;
            cout<<s<<endl;
            res.push_back(s);
            return;
        }
        else
        {
            string temp=m[dig[i]-'0'];
            for(int j=0;j<temp.length();j++)
            {
                s[curr]=temp[j];
                gen(dig,m,s,i+1,curr+1,res);
            }
        }

    }
    vector<string> letterCombinations(string digits) 
    {
        map<int,string> m;
        m[2]="abc";
        m[3]="def";
        m[4]="ghi";
        m[5]="jkl";
        m[6]="mno";
        m[7]="pqrs";
        m[8]="tuv";
        m[9]="wxyz";
        vector<string> res;
        string s;
        if(digits.length()==0) return res;
        s.append(digits.length(), ' ');
        //int count=0;
        gen(digits,m,s,0,0,res);
        //cout<<count<<endl;
        return res;
    }
};