class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // POSTFIX EXPRESSION EVALUATION
        // 09.09.23
        // 30.01.24 (POTD)
        
        stack<int> stk;

        for(auto t: tokens){
            if(isOperator(t)){
                int opd2 = stk.top();
                stk.pop();
                int opd1 = stk.top();
                stk.pop();

                stk.push(operate(opd1, opd2, t));
            }
            else{
                stk.push(stoi(t));
            }
        }

        return stk.top();
    }

    bool isOperator(string t){
        return (t=="*" || t=="/" || t=="+" || t=="-");
    }

    int operate(int a, int b, string oprtr){
        if(oprtr == "*")
            return a*b;

        if(oprtr == "/")
            return a/b;

        if(oprtr == "+")
            return a+b;

        // if(oprtr == "-")
            return a-b;
    }
};