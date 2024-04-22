class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // 22.04.24 potd
        // Approach: BFS
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if(deadendSet.count("0000")){
            return -1;
        }

        queue<pair<string,int>> q;
        q.push({"0000", 0});
        deadendSet.insert("0000");

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            string currComb = curr.first;
            int moves = curr.second;

            if(currComb == target){
                return moves;
            }

            for(int i=0; i<4; i++){
                for(int delta: {-1,1}){
                    int newDigit = (currComb[i] - '0' + delta + 10)%10;
                    string newComb = currComb;
                    newComb[i] = '0' + newDigit;

                    // Using deadendSet as visitedSet as well
                    if(deadendSet.find(newComb) == deadendSet.end()){
                        deadendSet.insert(newComb);
                        q.push({newComb, moves+1});
                    }
                }
            }
        }

        return -1;
    }
};