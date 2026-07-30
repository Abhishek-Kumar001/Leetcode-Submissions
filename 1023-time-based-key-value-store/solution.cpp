class TimeMap {
private:
    unordered_map<string, map<int, string> > mpp;
            //   <key, <timestamp, value>>
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mpp[key][timestamp] = value; // vvi not mpp[key] = {timestamp, value}
    }
    
    string get(string key, int timestamp) {
        if(mpp.find( key ) == mpp.end()) return "";

        auto &timeline = mpp[key];
        auto it = timeline.upper_bound(timestamp);

        if (it == timeline.begin()) return "";     // no entry with time <= timestamp
        --it;                                       // step back to the largest time <= timestamp
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
