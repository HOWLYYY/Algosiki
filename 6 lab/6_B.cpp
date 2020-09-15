#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    int left;
    int right;
};

void through_out(vector<node> &tree, vector <int> &keys, int root)
{
    if (root != -1)
    {
        through_out(tree, keys, tree[root].left);
        keys.push_back(tree[root].data);
        through_out(tree, keys, tree[root].right);
    }
}

int ifCorrect(vector <node> &tree)
{
    vector <int> keys;
    through_out(tree, keys, 0);
    for (int i = 1; i < keys.size(); ++i)
        if (keys[i - 1] >= keys[i])
        {
            return 0;
        }
    return 1;
}

int main()
{
    int i;
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    cin >> i;
    vector <node> tree(i);
    for (int j = 0; j < i; j++)
    {
        cin >> tree[j].data >> tree[j].left >> tree[j].right;
        tree[j].left--;
        tree[j].right--;
    }

    if (i == 0 || ifCorrect(tree))
    {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}