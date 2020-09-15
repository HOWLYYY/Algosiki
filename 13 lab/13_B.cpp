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

vector <int> KMP_Search (string text, string pattern)
{
    vector <int> prefixes = computeLPS(pattern);
    vector <int> idxes;
    int i = 0;
    int j = 0;

    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == pattern.size())
        {
            idxes.push_back(i - j);
            j = prefixes[j - 1];
        }

        else if (i < text.size() && text[i] != pattern[j])
        {
            if (j != 0)
                j = prefixes[j - 1];
            else
                i++;
        }
    }

    return idxes;
}

int main()
{
    string pattern, text;
    freopen("search2.in","r",stdin);
    freopen("search2.out","w",stdout);
    cin>>pattern>>text;

    vector <int> idxes = KMP_Search(text, pattern);

    cout<<idxes.size()<<endl;
    for (auto idx : idxes)
        cout<<idx + 1<<' ';
    return 0;
}