#include <iostream>
using namespace std;

typedef struct list
{
    int value;
    struct list* next;
} list;

typedef struct set
{
    list** hash_values;
} set;

set* create_set(int size)
{
    auto *s = new set;
    s->hash_values = (list **) calloc(size, sizeof(list *));
    return s;
}

int to_hash(int x)
{
    return abs(x % 1000001);
}

void insert(set* s, int x)
{
    int h = to_hash(x);
    list* element = s->hash_values[h];

    if (element == nullptr)
    {
        element = new list;
        element->value = x;
        element->next = nullptr;
        s->hash_values[h] = element;
        return;
    }

    while (element->next != nullptr)
    {
        if (element->value == x)
        {
            return;
        }
        element = element->next;
    }

    if (element->value == x)
    {
        return;
    }
    element->next = new list;
    element->next->value = x;
    element->next->next = nullptr;
}

void del(set* s, int x)
{
    int h = to_hash(x);
    list* element = s->hash_values[h];
    list* previous = element;
    int i = 0;
    while (element != nullptr)
    {
        if (element->value == x && i == 0)
        {
            s->hash_values[h] = element->next;
            delete element;
            return;
        }
        else if (element->value == x)
        {
            previous->next = element->next;
            delete element;
            return;
        }
        previous = element;
        element = element->next;
        i = 1;
    }
}

void exists(set* s, int x)
{
    int h = to_hash(x);
    list* element = s->hash_values[h];
    if (element != nullptr)
    {
        do
            {
            if (element->value == x)
            {
                cout<<"true\n";
                return;
            }
            element = element->next;
        } while (element != nullptr);
    }
    cout<<"false\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    string command;
    int x;
    set* hash = create_set(1000001);
    while(cin>>command)
    {
        cin >> x;
        if (command == "insert")
        {
            insert(hash, x);
        }
        if (command == "exists")
        {
            exists(hash, x);
        }
        if (command == "delete")
        {
            del(hash, x);
        }
    }
}