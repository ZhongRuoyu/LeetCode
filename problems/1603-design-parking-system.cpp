// Solved 2021-02-02 10:18
// Runtime: 48 ms (97.56%)
// Memory Usage: 32.9 MB (95.80%)

class ParkingSystem {
   public:
    ParkingSystem(int big, int medium, int small) {
        slots[0] = big;
        slots[1] = medium;
        slots[2] = small;
    }

    bool addCar(int carType) {
        if (carType < 1 || carType > 3 || slots[carType - 1] <= 0) return false;
        --slots[carType - 1];
        return true;
    }

   private:
    int slots[3];
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
