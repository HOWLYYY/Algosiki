#include <iostream>
#include <vector>

using namespace std;
vector<pair<string, string>> runner;

void Merge_Sort(int l, int r)
{
    if (l == r)
        return;
    int middle = (l + r) / 2;
    Merge_Sort(l, middle);
    Merge_Sort(middle + 1, r);
    int i = l;
    int j = middle + 1;
    vector<pair<string, string> > result(r - l + 1);
    for (int q = 0; q < r - l + 1; q++)
    {
        if ((j > r) || ((i <= middle) && (runner[i].first <= runner[j].first)))
        {
            result[q] = runner[i];
            i++;
        } else
        {
            result[q] = runner[j];
            j++;
        }
    }
    for (int q = 0; q < r - l + 1; q++)
        runner[l + q] = result[q];
}


int main()
{
    int n;
    string emptyy = "";
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    cin >> n;
    runner.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> runner[i].first >> runner[i].second;
    }

    Merge_Sort(0, n - 1);

    for (int i = 0; i < n; i++) {
        if (runner[i].first != emptyy) {
            emptyy = runner[i].first;
            cout << "=== " << emptyy << " ===" << endl;
        }
        cout << runner[i].second << " " << endl;
    }
    getchar();
    return 0;
}