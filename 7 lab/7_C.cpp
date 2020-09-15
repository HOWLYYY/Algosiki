#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct InputNode
{
    int key;
    int left;
    int right;
};

struct Node
{
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int key): key(key)
    {
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree
{
public:
    Node* root = nullptr;
    int Size = 0;
    Node* buildDfs(vector<InputNode>& G, int vertex)
    {
        if(vertex < 0 || G.size() == 0) return nullptr;
        auto newNode = new Node(G[vertex].key);
        this->Size++;
        newNode->left = buildDfs(G, G[vertex].left);
        newNode->right = buildDfs(G, G[vertex].right);
        newNode->height = max(this->getHeight(newNode->left), this->getHeight(newNode->right)) + 1;
        return newNode;
    }

    int getHeight(Node* node)
    {
        if(node == nullptr) return 0;
        return node->height;
    }

    void fixHeight(Node* node)
    {
        node->height = max(
                this->getHeight(node->left),
                this->getHeight(node->right)) + 1;
    }

    int Balancing(Node* node)
    {
        return this->getHeight(node->right) - this->getHeight(node->left);
    }

    Node* balanceTree(Node* node)
    {
        if(this->Balancing(node) > 1)
        {
            if(this->Balancing(node->right) < 0) node->right = this->rotateRight(node->right);
            return this->rotateLeft(node);
        }

        if(this->Balancing(node) < -1)
        {
            if(this->Balancing(node->left) > 0)  node->left = this->rotateLeft(node->left);
            return this->rotateRight(node);
        }
        return node;
    }
    Node* rotate(Node* node, bool isLeft)
    {
        Node* tmp = isLeft ? node->right : node->left;
        if(isLeft)
        {
            node->right = tmp->left;
            tmp->left = node;
        }
        else
        {
            node->left = tmp->right;
            tmp->right = node;
        }
        this->fixHeight(node);
        this->fixHeight(tmp);
        return tmp;
    }

    Node* insertDfs(int key, Node* now)
    {
        if(now == nullptr) return new Node(key);
        if(key > now->key) now->right = insertDfs(key, now->right);
        else now->left = insertDfs(key, now->left);
        this->fixHeight(now);
        return this->balanceTree(now);
    }

    Node* rotateLeft(Node* node)
    {
        return this->rotate(node, true);
    }

    Node* rotateRight(Node* node)
    {
        return this->rotate(node, false);
    }

    void buildTree(vector<InputNode>& G)
    {
        this->root = this->buildDfs(G, 0);
    }

    void insert(int key)
    {
        this->root = this->insertDfs(key, this->root);
        this->Size++;
    }

    void printTree()
    {
        queue<Node*> bfs;
        bfs.push(this->root);
        int line = 1;
        cout << this->Size << "\n";
        while(!bfs.empty())
        {
            Node* node = bfs.front();
            bfs.pop();
            int left = 0, right = 0;

            if(node->left != nullptr)
            {
                bfs.push(node->left);
                left = ++line;
            }

            if(node->right != nullptr)
            {
                bfs.push(node->right);
                right = ++line;
            }
            cout << node->key << " " << left << " " << right << "\n";
        }
    }
};

int main()
{
    int n, newKey;
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    cin >> n;
    vector<InputNode> nodes(n);
    auto AVL = new AVLTree();
    for(int i = 0; i < n; i++)
    {
        cin >> nodes[i].key >> nodes[i].left >> nodes[i].right;
        nodes[i].left--;
        nodes[i].right--;
    }
    AVL->buildTree(nodes);
    cin >> newKey;
    AVL->insert(newKey);
    AVL->printTree();
    return 0;
}
