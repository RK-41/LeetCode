class Solution {
public:
    string countOfAtoms(string formula) {
        // 14.07.24 potd
        int n = formula.size(), currIdx = 0;
        unordered_map<string,int> resCounter;
        stack<unordered_map<string,int>> parenthesisStack;

        while(currIdx < n){
            char currChar = formula[currIdx];

            if(currChar == '('){
                currIdx++;
                parenthesisStack.push(unordered_map<string,int>());
                continue;
            }

            if(currChar == ')'){
                string multStr = "";
                currIdx++;

                while(currIdx < n && isdigit(formula[currIdx])){
                    multStr += formula[currIdx];
                    currIdx++;
                }

                int mult = multStr.empty() ? 1 : stoi(multStr);
                unordered_map<string,int> lastCounter = parenthesisStack.top();
                parenthesisStack.pop();
                unordered_map<string,int>& target = parenthesisStack.empty() ? resCounter : parenthesisStack.top();

                for(const auto& [elem, counter] : lastCounter){
                    target[elem] += counter * mult;
                }

                continue;
            }

            string currElem = "", currCounterStr = "";
            unordered_map<string,int>& target = parenthesisStack.empty() ? resCounter : parenthesisStack.top();

            while(currIdx < n && formula[currIdx] != '(' && formula[currIdx] != ')'){
                if(isalpha(formula[currIdx])){
                    if(isupper(formula[currIdx]) && !currElem.empty()){
                        target[currElem] += currCounterStr.empty() ? 1 : stoi(currCounterStr);
                        currElem = "", currCounterStr = "";
                    }

                    currElem += formula[currIdx];
                } else {
                    currCounterStr += formula[currIdx];
                }

                currIdx++;
            }

            target[currElem] += currCounterStr.empty() ? 1 : stoi(currCounterStr);
        }

        vector<string> parts;
        for(const auto& [elem, counter] : resCounter){
            parts.push_back(elem + (counter == 1 ? "" : to_string(counter)));
        }

        sort(parts.begin(), parts.end());
        
        string res;
        for(const auto& part: parts){
            res += part;
        }

        return res;
    }
};