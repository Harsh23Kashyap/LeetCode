class Solution {
public:
    int sum(string w)
    {
        int num=0;
        for(int i=0;i<w.size();i++)
            num=num*10+(int)(w[i]-'a');
        //cout<<num<<endl;
        return num;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) 
    {
        return (sum(firstWord)+sum(secondWord)==sum(targetWord));
        
    }
};