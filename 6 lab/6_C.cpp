#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
    int data;
    node *prev, *left, *right;
};

class t_search
{
    node *root = nullptr;

public:
    void through(node* root, vector<int> &Keys);
    void insert(int x);
    void del(int x);
    bool exists(int x);
    node* search(int x);
    node* next(int x);
    node* prev(int x);
};

bool t_search::exists(int x)
{
    return search(x) != nullptr;
}

void t_search::insert(int x)
{
    if (exists(x)) return;
    node *new_node = new node;
    new_node->data = x;
    new_node->prev = new_node->left = new_node->right = nullptr;
    node *curr = root;

    while (curr != nullptr)
    {
        new_node->prev = curr;
        if (new_node->data < curr->data) curr = curr->left;
        else curr = curr->right;
    }

    if (new_node->prev == nullptr) root = new_node;
    else if (new_node->data < new_node->prev->data) new_node->prev->left = new_node;
    else new_node->prev->right = new_node;
}

node* t_search::prev(int x)
{
    node *curNode = root, *prevNode = nullptr;
    while (curNode != nullptr)
        if (curNode->data < x)
        {
            prevNode = curNode;
            curNode = curNode->right;
        }
        else  curNode = curNode->left;
    return prevNode;
}

node* t_search::next(int x)
{
    node *curr = root, *next_node = nullptr;
    while (curr != nullptr)
        if (curr->data > x)
        {
            next_node = curr;
            curr = curr->left;
        }
        else
            curr = curr->right;
    return next_node;
}

void t_search::del(int x)
{
    node *to_delete = search(x);
    if (to_delete == nullptr)
        return;
    node *NodeL, *NodeR;
    if (to_delete->left == nullptr || to_delete->right == nullptr) NodeL = to_delete;
    else NodeL = next(x);
    if (NodeL->left != nullptr) NodeR = NodeL->left;
    else NodeR = NodeL->right;
    if (NodeR != nullptr) NodeR->prev = NodeL->prev;
    if (NodeL->prev == nullptr) root = NodeR;
    else if (NodeL == NodeL->prev->left) NodeL->prev->left = NodeR;
    else NodeL->prev->right = NodeR;
    if (NodeL != to_delete) to_delete->data = NodeL->data;
    delete NodeL;
}

node* t_search::search(int x)
{
    node *curr = root;
    while (curr != nullptr && x != curr->data)
        if (x < curr->data) curr = curr->left;
        else curr = curr->right;
    return curr;
}



void t_search::through(node* root, vector<int> &Keys)
{
    if (root != nullptr)
    {
        through(root->left, Keys);
        Keys.push_back(root->data);
        through(root->right, Keys);
    }
}


int main()
{
    int value;
    string command;
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);

    t_search tree;
    while (cin >> command >> value)
    {

        if (command == "insert") tree.insert(value);
        if (command == "delete") tree.del(value);
        if (command == "exists")
        {
            if (tree.search(value)) cout << "true\n";
            else cout << "false\n";
        }
        if (command == "next")
        {
            node *result = tree.next(value);
            if (result == nullptr) cout << "none\n";
            else cout << result->data << "\n";
        }
        if (command == "prev")
        {
            node *result = tree.prev(value);
            if (result == nullptr) cout << "none\n";
            else cout << result->data << "\n";
        }
    }

    return 0;
}