class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push('(');
            }else if(s[i] == ')'){
                int num = 0;
                while(st.top() != '('){
                    num += (666-(int)(st.top()));
                    st.pop();
                }
                st.pop();
                if(num!=0){
                    st.push(666-(2*num));
                }
                else st.push(666-1);
            }
        }
        if(st.size() == 1) return 666-st.top();
        else{
            int ans = 0;
            while(!st.empty()){
                ans += (666-(int)(st.top()));
                st.pop();
            }
            return ans;
        }
    }
};