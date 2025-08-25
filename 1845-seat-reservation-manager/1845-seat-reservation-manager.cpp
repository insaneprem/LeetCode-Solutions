class SeatManager {
public:
    set<int> rs,unrs;
    SeatManager(int n) {
        for(int i=1;i<=n;i++) unrs.insert(i);
    }
    
    int reserve() {
        int val = *unrs.begin();
        unrs.erase(unrs.begin());
        rs.insert(val);
        return val;
    }
    
    void unreserve(int seatNumber) {
        rs.erase(seatNumber);
        unrs.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->rs();
 * obj->unrs(seatNumber);
 */