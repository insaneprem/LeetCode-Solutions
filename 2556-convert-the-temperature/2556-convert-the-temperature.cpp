class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double k=celsius+273.15;
        double f=celsius*1.8 + 32;

        return {k,f};
    }
};