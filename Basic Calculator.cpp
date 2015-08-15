#include <iostream>
#include <map>
#include <stack>
using namespace std;

int calculate(string s) {
    map<char, int> order;
    order['+'] = 0; order['-'] = 0;
    order['('] = 1; order[')'] = 1;

    stack<char> symbol;
    stack<int> number;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || s[i] == '\t')
            continue;

        if (order.find(s[i]) == order.end()) {
            int num = s[i] - '0';
            i++;
            while (i < s.size()) {
                if (s[i] == ' ' || s[i] == '\t') {
                    i++;
                    continue;
                }

                if (order.find(s[i]) != order.end()) {
                    i--;
                    break;
                }

                num = (num * 10 + (s[i] - '0'));
                i++;
            }
            number.push(num);

        } else if (s[i] == ')') {
            char tmp;
            while ((tmp = symbol.top()) != '(') {
                symbol.pop();

                int x = number.top();
                number.pop();
                int y = number.top();
                number.pop();
                if (tmp == '+')
                    number.push(x + y);
                else
                    number.push(y - x);
            }
            symbol.pop();
        } else {
            char tmp;
            while (true) {
                if (symbol.empty())
                    break;
                tmp = symbol.top();
                if (tmp == '(')
                    break;
                if (order[tmp] < order[s[i]])
                    break;
                symbol.pop();

                int x = number.top();
                number.pop();
                int y = number.top();
                number.pop();
                if (tmp == '+')
                    number.push(x + y);
                else
                    number.push(y - x);
            }
            symbol.push(s[i]);
        }
    }

    while (!symbol.empty()) {
        char tmp = symbol.top();
        symbol.pop();

        int x = number.top();
        number.pop();
        int y = number.top();
        number.pop();
        if (tmp == '+')
            number.push(x + y);
        else
            number.push(y - x);
    }

    return number.top();
}

int main() {
    int ans = calculate("(1+(4+5+2)-3)+(6+8)");
    cout << ans;
}

