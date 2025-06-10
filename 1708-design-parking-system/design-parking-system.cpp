class ParkingSystem {
public:
    int b,m,s;
    int cb,cm,cs;
    ParkingSystem(int big, int medium, int small) {
        b=big,m=medium,s=small;
        cb=0,cm=0,cs=0;
    }
    
    bool addCar(int carTye) {
        if(carTye==1){
            if(cb<b){
                cb++;
                return true;
            }
            return false;
        }
        if(carTye==2){
            if(cm<m){
                cm++;
                return true;
            }
            return false;
        }
            if(cs<s){
                cs++;
                return true;
            }
            return false;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */