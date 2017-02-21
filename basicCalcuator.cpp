/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23

TODO:
remove the if statement at the end
can remove the inner while loop
*/
class Solution {
public:
    int calculate(string s) {
        stack<string> expr;
        int i=0;
        int index;
        int a = 0,sum=0;
        string op;
        while(i<s.size()){
            if(s[i]=='(')
                expr.push("(");
            else if(s[i] == '+')
               expr.push("+");
            else if(s[i] == '-')
                expr.push("-");
            else if(s[i]>='0' && s[i]<='9'){
                index = i;
                while((s[i]>='0' && s[i]<='9')){
                    i++;
                }
                expr.push(s.substr(index,i-index));
                continue;
            }
            else if(s[i]==')'){
                 sum = 0;
                while(expr.top()[0]!='('){
                    a = stoi(expr.top());
                    expr.pop();
                    op = expr.top();
                    expr.pop();
                    if(op[0]=='-')
                        a = -a;
                    sum = sum + a;
                    if(op[0]=='(')
                        break;
                }
                expr.push(to_string(sum));
            }
            i++;
        }
        sum = 0;
        while(!expr.empty()){
            a = stoi(expr.top());
            //cout << a;
            expr.pop();
            if(!expr.empty()){
                op = expr.top();
                expr.pop();
                if(op[0]=='-')
                    a = -a;
            }
            sum = sum + a;
        }
        return sum ;
    }
};
