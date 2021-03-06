class ParkingSystem {
public:
    vector<int> v;
    ParkingSystem(int big, int medium, int small) 
    {
        v={big,medium,small};
    }
    
    bool addCar(int carType) 
    {
        if(v[carType-1]==0)
            return false;
        v[carType-1]--;
        return true;
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
