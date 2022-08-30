class Solution {
public:
    bool isRobotBounded(string instructions) 
    {
        char dir = 'N';
        int posx = 0, posy = 0;
        
        for(int i=0;i<instructions.size();i++) 
        {
            if(instructions[i] == 'G') 
            {
                posy += ((dir == 'N') ? 1 : 0);
                posy += ((dir == 'S') ? -1 : 0);
                posx += ((dir == 'E') ? 1 : 0);
                posx += ((dir == 'W') ? -1 : 0);
            }
            else 
            {
                char incomingDir = instructions[i];
            
                if(dir == 'N') 
                    dir = ((incomingDir == 'L') ? 'W' : 'E');
                
                else if(dir == 'S') 
                    dir = ((incomingDir == 'L') ? 'E' : 'W');
                
                else if(dir == 'E') 
                    dir = ((incomingDir == 'L') ? 'N' : 'S');
                
                else if(dir == 'W') 
                    dir = ((incomingDir == 'L') ? 'S' : 'N');
                
            }
        }
        
        if((posx == 0 && posy == 0) or dir != 'N') 
            return true;
        return false;
    }
};