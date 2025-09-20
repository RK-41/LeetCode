// 20.09.25 potd
class Router {
public:
    int lim;
    queue<vector<int>> q;
    unordered_set<string> st;
    unordered_map<int, vector<int>> destTimestamps;

    Router(int memoryLimit) {
        lim = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string key = to_string(source) + "," + to_string(destination) + "," + to_string(timestamp);
        if (st.count(key))
            return false;

        q.push({source, destination, timestamp});
        st.insert(key);
        auto& timestamps = destTimestamps[destination];
        auto it = upper_bound(timestamps.begin(), timestamps.end(), timestamp);
        timestamps.insert(it, timestamp);

        if (q.size() > lim) {
            vector<int> oldest = q.front();
            q.pop();
            string oldestKey = to_string(oldest[0]) + "," + to_string(oldest[1]) + "," + to_string(oldest[2]);
            st.erase(oldestKey);
            auto& oldTimestamps = destTimestamps[oldest[1]];
            auto oldIt = lower_bound(oldTimestamps.begin(), oldTimestamps.end(), oldest[2]);
            if (oldIt != oldTimestamps.end() && *oldIt == oldest[2])
                oldTimestamps.erase(oldIt);
        }
        return true;
    }
    
    vector<int> forwardPacket() {
        if (q.empty())
            return {};

        vector<int> v = q.front();
        q.pop();
        string key = to_string(v[0]) + "," + to_string(v[1]) + "," + to_string(v[2]);
        st.erase(key);
        auto& timestamps = destTimestamps[v[1]];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), v[2]);
        if (it != timestamps.end() && *it == v[2])
            timestamps.erase(it);

        return v;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& timestamps = destTimestamps[destination];
        auto left = lower_bound(timestamps.begin(), timestamps.end(), startTime);
        auto right = upper_bound(timestamps.begin(), timestamps.end(), endTime);
        return right - left;
    }
};