class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // 10.04.24 potd
        int n=deck.size();
        vector<int> ans(n);
        deque<int> idx;

        sort(deck.begin(), deck.end());

        for(int i=0; i<n; i++){
            idx.push_back(i);
            cout<<deck[i]<<" ";
        }

        for(int card: deck){
            int i = idx.front();
            idx.pop_front();
            ans[i] = card;

            if(idx.size()){
                idx.push_back(idx.front());
                idx.pop_front();
            }
        }

        return ans;
    }
};