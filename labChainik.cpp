#include <iostream>
#include <vector>

using namespace std;

class Water {
public:
    int boiled;
    Water() : boiled(0) {}
};

class Kettle {
public:
    Water* water;
    
    Kettle() : water(nullptr) {}

    bool isFull() {
        return water != nullptr;
    }

    void boil() {
        if (water != nullptr) {
            water->boiled = 1;
            cout << "Water boil" << endl;
        } else {
            cout << "No water" << endl;
        }
    }

    void removeWater() {
        water = nullptr;
        cout << "Kettle removed" << endl;
    }

    void fillWithWater(Water* w) {
        water = w;
    }
};

class Match {
public:
    int matches;
    
    Match(int m) : matches(m) {}

    bool useOne() {
        if (matches != 0) {
            matches--;
            return true;
        }
        return false;
    }
};

class Sink {
public:
    vector<Water*> allWater;
    Kettle* kettle;

    Sink(vector<Water*>& water) : allWater(water), kettle(nullptr) {}

    void putKettle(Kettle* k) {
        kettle = k;
    }

    void removeKettle() {
        kettle = nullptr;
    }

    void fillKettle() {
        if (!allWater.empty() && !kettle->isFull()) {
            kettle->fillWithWater(allWater.back());
            cout << "Kettle filled" << endl;
        } else {
            cout << "No water" << endl;
        }
    }
};

class Stove {
public:
    Match* matches;
    Kettle* kettle;

    Stove(Match* m) : matches(m), kettle(nullptr) {}

    void putKettle(Kettle* k) {
        kettle = k;
    }

    void removeKettle() {
        kettle = nullptr;
    }

    void boilKettle() {
        if (kettle != nullptr) {
            kettle->boil();
        }
    }
};

int main() {
    Match match(10);
    Kettle kettle;
    Water water;
    vector<Water*> waterVec = {&water};
    Sink sink(waterVec);
    sink.putKettle(&kettle);
    sink.fillKettle();
    sink.removeKettle();
    Stove stove(&match);
    stove.putKettle(&kettle);
    stove.boilKettle();
    stove.removeKettle();
    kettle.removeWater();

    return 0;
}
