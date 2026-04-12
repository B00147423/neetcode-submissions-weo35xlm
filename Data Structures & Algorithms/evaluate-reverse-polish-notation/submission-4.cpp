class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> ms;
        for(string& c : tokens){
            if(c == "+"){
                int a = ms.top(); ms.pop();
                int b = ms.top(); ms.pop();
                ms.push(b + a);
            }else if(c == "-"){
                int a = ms.top(); ms.pop();
                int b = ms.top(); ms.pop();
                ms.push(b - a);
            }else if(c == "*"){
                int a = ms.top(); ms.pop();
                int b = ms.top(); ms.pop();
                ms.push(b * a);
            }else if( c == "/"){
                int a = ms.top(); ms.pop();
                int b = ms.top(); ms.pop();
                ms.push(b / a);
            }else{
                ms.push(stoi(c));
            }
        }
        return ms.top();
    }
};
