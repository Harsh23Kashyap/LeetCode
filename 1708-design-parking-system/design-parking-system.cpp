class ParkingSystem {
public:
    int cb,cm,cs;
    ParkingSystem(int big, int medium, int small) {
        cb=big,cm=medium,cs=small;
    }
    
    bool addCar(int carType) {
        switch(carType){
            case 1:
                return --cb>=0;
                break;
             case 2:
                return --cm>=0;
                break;
             case 3:
                return --cs>=0;
                break;
        }
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */