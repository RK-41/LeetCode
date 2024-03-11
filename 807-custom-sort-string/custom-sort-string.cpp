class Solution {
public:
    string customSortString(string order, string s) {
        // 11.03.24 potd
        unordered_map<char,int> orderCharCount;
        string sorted_s;

        for(char c: order)
            orderCharCount[c]=0;

        for(char c: s)
            if(orderCharCount.find(c) != orderCharCount.end())
                orderCharCount[c]++;

        for(char c: order)
            sorted_s.append(orderCharCount[c], c);

        for(char c: s)
            if(orderCharCount.find(c) == orderCharCount.end())
                sorted_s.push_back(c);

        return sorted_s;
    }
};