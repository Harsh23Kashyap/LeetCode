class Node
{
    public:
    char data;
    unordered_map<char,Node*> children;
    bool terminal;
    Node(char d)
    {
        data=d;
        terminal=false;
    }
};


class Trie 
{
    Node* root;
    public:
    Trie() 
    {
        root=new Node('\0');
        
    }
    
    void insert(string word) 
    {
        Node *temp=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            if(temp->children.count(ch))
            {
                temp=temp->children[ch];
                //cout<<"Already created for "<<ch<<endl;
                
            }
              else
               {
                   //cout<<"New node created "<<ch<<endl;
                 Node *n= new Node(ch);
                temp->children[ch]=n;
                temp=n;
               }
        }
        temp->terminal=true;
        
    }
    
    bool search(string word) 
    {
        Node *temp=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            cout<<ch<<" ";
            if(temp->children.count(ch)==0)
            {
                cout<<endl;
                return false;
            }
              else
               {
                   temp=temp->children[ch];
               }
        }
        cout<<endl;
        return temp->terminal;
        
    }
    
    bool startsWith(string prefix) 
    {
        Node *temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            char ch=prefix[i];
            if(temp->children.find(ch)==temp->children.end())
            {
                return false;
            }
              else
               {
                   temp=temp->children[ch];
               }
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */