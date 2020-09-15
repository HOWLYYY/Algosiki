#include <iostream>
#include <stack>

using namespace std;

bool Positions(string str)
{
    stack <char> skobki;
    for (int i = 0; i < int(str.length()); i++)
    {
        if (str[i] == '[' || str[i] == '(')
            skobki.push(str[i]);
        else if ((!skobki.empty()) && ((str[i] == ')' && skobki.top() == '(') || (str[i] == ']' && skobki.top() == '[')))
            skobki.pop();
        else
            return false;
    }
    if (skobki.empty())
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen ("brackets.in", "r", stdin);
    freopen ("brackets.out", "w", stdout);
    string k;
    while (getline(cin, k))
    {
        if (Positions(k))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}