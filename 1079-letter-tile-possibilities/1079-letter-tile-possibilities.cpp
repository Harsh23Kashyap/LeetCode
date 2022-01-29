class Solution {
public:
    void backtrack(string tiles, int start, set<string>& s)
    {
        s.insert(tiles.substr(0,start));
        cout<<tiles.substr(0,start)<<endl;
        for(int i=start;i<tiles.length();i++)
        {
            if(i != start && tiles[i] == tiles[start]){
                continue;
            }
            swap(tiles[i], tiles[start]);
            backtrack(tiles, start+1, s);
            swap(tiles[i], tiles[start]);
        }
    }
   
    int numTilePossibilities(string tiles) 
    {
        set<string> s;
        sort(tiles.begin(),tiles.end());
        int count=-1;
        //string t="";
        backtrack(tiles,0,s);
        return s.size()-1;
    }
};