class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int fleet=0;
        stack<double> time;
        vector<pair<int,int>> cars;
        for(int i=0;i<position.size();i++) {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        for(int i=0;i<cars.size();i++) {
            double pos=cars[i].first;
            double spd=cars[i].second;
            double a=(double)(target-pos)/spd;
            if(time.empty()) {
                time.push(a);
                fleet++;
            }
            else{
                if(a<=time.top()) {
                    continue;
                }
                else {
                    fleet++;
                    time.push(a);
                }
            }
        }
        return fleet;
    }
};
