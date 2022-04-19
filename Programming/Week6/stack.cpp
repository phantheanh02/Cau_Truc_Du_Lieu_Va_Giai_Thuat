#include <stdio.h>
#include <stack>
using namespace std;

bool match(char a, char b)
{
    if (a == '(' && b == ')') return true;
    if (a == '{' && b == '}') return true;
    if (a == '[' && b == ']') return true;
    return false;
}

bool solve(char *x, int n)
{
    stack<char> s;
    for (int i =0; i< n; i++)
    {
        if (x[i] == '[' || x[i] == '(' || x[i] == '{')
            s.push(x[i]);
        else if (s.empty())
        {
            char c = s.top();
            s.top();
            if (!match(c,x[i])) return false;
        }
    }
    return s.empty();
}

int main()
{
    bool ok = solve("[]",2);
    if (ok) printf("TRUE");
    else printf("FALSE");
}