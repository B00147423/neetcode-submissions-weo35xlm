class TimeMap {
public:
 unordered_map<string, vector<pair<int, string>>> keyStore;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timeStamp) {
        auto& values = keyStore[key];
        string result = "";
        int left = 0, right = values.size()-1;
        while(left <= right){
            int mid = (left+right) / 2;
            if(values[mid].first <= timeStamp){
                result = values[mid].second;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return result;
    }
};
