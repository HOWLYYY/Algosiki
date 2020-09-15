#include <iostream>
using namespace std;

struct node
{
    int data;
    int left;
    int right;
};

int t_depth(node* arr, int root)
{
    if (root<=-1) return 0;

    int left_branch = t_depth(arr, arr[root].right);
    int right_branch = t_depth(arr, arr[root].left);

    if (left_branch > right_branch) return (left_branch + 1);
    else return (right_branch + 1);

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    int i;
    cin >> i;
    node* bin_tree = new node[i];
    for (int j = 0; j < i; j++)
    {
        cin >> bin_tree[j].data >> bin_tree[j].left >> bin_tree[j].right;
        bin_tree[j].right--;
        bin_tree[j].left--;
    }

    if (i !=0 ) cout << t_depth(bin_tree, 0);

    else cout << 0;

    return 0;
}