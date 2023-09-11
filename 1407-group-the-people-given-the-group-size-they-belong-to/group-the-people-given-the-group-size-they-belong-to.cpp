class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // 11.09.23 POTD
        unordered_map<int,queue<int>> grEle;
        vector<vector<int>> ans;

        for(int i=0; i<groupSizes.size(); i++){
            grEle[groupSizes[i]].push(i);
        }

        for(auto &g: grEle){
            int grSize = g.first;
            auto q = g.second;

            if(q.size() == grSize){
                vector<int> v;

                while(q.size()){
                    v.push_back(q.front());
                    q.pop();
                }

                ans.push_back(v);
            }
            else{
                while(q.size()){
                    vector<int> v;
                    int sz = grSize;

                    while(sz--){
                        v.push_back(q.front());
                        q.pop();
                    }

                    sz = grSize;
                    ans.push_back(v);
                }
            }
        }

        return ans;
    }
};