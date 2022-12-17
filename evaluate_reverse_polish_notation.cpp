/*QEUSTION:-
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there 
will not be any division by zero operation.
Testcase-
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        // int ans=0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                long long val1 =s.top();
                s.pop();
                long long val2 = s.top();
                s.pop();
                if(tokens[i]=="+"){
                    long long tot = val1+val2;
                    s.push(tot);
                }
                else if(tokens[i]=="-"){
                    long long tot = val2-val1;
                    s.push(tot);
                }
                else if(tokens[i]=="*"){
                    long long tot = val1*val2;
                    s.push(tot);
                }
                else{
                    long long tot = val2/val1;
                    s.push(tot);
                }
            }
            else{
                long long temp = stoi(tokens[i]);
                s.push(temp);
            }
        }
        return s.top();
    }
};
