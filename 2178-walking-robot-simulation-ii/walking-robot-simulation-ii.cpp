class Robot {
public:
    string dir="East";
    int x=0,y=0;
    int m=0,n=0;                                                                                                                         int peri;                                                                
    Robot(int width, int height) {
        m=width,n=height;
        peri=2*(m+n)-4;
    }
    
    void step(int num) { 
        num=num%peri;    
        if(num==0){
            if(x==0 and y==0)
                dir="South";
        }                    
        
        int cx=x,cy=y;
        if(dir=="East"){
              x=cx+num;y=cy;
            if(x>=m){
                x=m-1;
                int rem=num-(m-1-cx);
                dir="North";
                step(rem);
            }
        }
        else if(dir=="North"){
              x= cx;y=num+cy;
            if(y>=n){
                y=n-1;
                int rem=num-(n-1-cy);
                dir="West";
                step(rem);
            }
            
        }

        else if(dir=="South"){
              x= cx;y=cy-num;
            if(y<0){
                y=0;
                int rem=num-(cy);
                dir="East";
                step(rem);
            }
            
        }
        else if(dir=="West"){
              x=cx-num;y=cy;
            if(x<0){
                x=0;
                int rem=num-(cx);
                dir="South";
                step(rem);
            }
            
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */