class UndergroundSystem {
public:
    unordered_map<string, pair<long long, int>> Times;
    unordered_map<int, pair<string,int>> Transit;
    UndergroundSystem() {
        Times.clear();
        Transit.clear();
    }
    
    void checkIn(int id, string sName, int t) {
        if(Transit.find(id) != Transit.end()) return;
        Transit[id] = {sName, t};
    }
    
    void checkOut(int id, string sName, int t) {
        auto& info = Transit[id];
        string startStation = info.first;
        int Start = info.second;
        string key = startStation + ":" + sName;
        int time = t - Start;
        
        if(Times.find(key) != Times.end()) {
            auto& oldTimes = Times[key];
            oldTimes.first += time;
            oldTimes.second++;
        } else {
            Times[key] = {time, 1};
        }
        Transit.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        auto & info = Times[key];
        double avg = (double)info.first / (double)info.second;
        return avg;
    }
};