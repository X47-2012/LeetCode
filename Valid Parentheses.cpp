#include <stack>
#include <iostream>
#include <string.h>
using namespace std;

bool isValid(string s)
{
    std::stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
            continue;
        }
        switch(s[i])
        {
        case ')':
            if(st.empty() || st.top() != '(')
            {
                return false;
            }
            else
            {
                st.pop();
            }
            continue;
        case '}':
            if(st.empty() || st.top() != '{')
            {
                return false;
            }
            else
            {
                st.pop();
            }
            continue;
        case ']':
            if(st.empty() || st.top() != '[')
            {
                return false;
            }
            else
            {
                st.pop();
            }
            continue;
        }
    }
    if(st.empty())
        return true;
    else
        return false;
}

int main()
{
    string s = "()";
    cout<<isValid(s);

    return 0;
}
