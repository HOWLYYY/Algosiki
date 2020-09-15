#include <iostream>
#include <vector>

using namespace std;

vector <int> computeLPS (string txt)
{
    vector <int> LPS (txt.size());
    LPS[0] = 0;
    int len = 0;
    int i = 1;
    while (i < txt.size())
    {
        if (txt[i] == txt[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }

        else
        {
            if (len > 0)
                len = LPS[len - 1];
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }

    return LPS;
}


int main()
{
    int capacity;
    string text;
    cin>>capacity>>text;
    vector <vector <int>> statements (text.size() + 1, vector <int> (capacity, 0));
    vector <int> prefixes = computeLPS(text);

    for (int i = 0; i < text.size() + 1; i++)
    {
        for (char letter = 'a'; letter < 'a' + capacity; letter++)
        {
            if (i > 0 && letter != text[i]) statements[i][letter - 'a'] = statements[prefixes[i - 1]][letter - 'a'];
            else statements[i][letter - 'a'] = i + (letter == text[i]);
        }
    }

    for (const auto& condition : statements)
    {
        for (auto input : condition)
            cout<<input<<' ';
        cout<<endl;
    }
    return 0;
}