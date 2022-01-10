class Solution {
public:
    string capitalizeTitle(string title) 
    {
        //string copy="";
        for(int i=0;i<title.length();i++)
            title[i]=tolower(title[i]);
        //title=copy;
        cout<<title<<endl;
        stringstream s(title); // Used for breaking words
        string sentence; // to store individual words
        string word;
        while (s >> word)
        {
            if(word.length()<3)
                sentence=sentence+word+" ";
            else
            {
                word[0]=toupper(word[0]);
                sentence=sentence+word+" ";
            }
        }
        return sentence.substr(0,sentence.length()-1);
        
    }
};