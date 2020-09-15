#include <iostream>
using namespace std;

typedef struct list
{
    string key;
    string value;
    struct list* next;
} list;

typedef struct set
{
    list** hash_values;
} map;

map* create_set(int size)
{
    auto *s = new map;
    s->hash_values = (list **) calloc(size, sizeof(list *));
    return s;
}

int to_hash(const string &key)
{
    int hash_value = 0;
    for(char i : key)
    {
        hash_value = 7 * hash_value + i;
    }
    return abs(hash_value % 1000001);
}

void insert(map* s, const string& key, const string& value)
{
    int h = to_hash(key);
    list* element = s->hash_values[h];

    if (element == nullptr)
    {
        element = new list;
        element->key = key;
        element->value = value;
        element->next = nullptr;
        s->hash_values[h] = element;
        return;
    }

    while (element->next != nullptr)
    {
        if (element->key == key)
        {
            element->value = value;
            return;
        }
        element = element->next;
    }

    if (element->key == key)
    {
        element->value = value;
        return;
    }
    element->next = new list;
    element->next->key = key;
    element->next->value = value;
    element->next->next = nullptr;
}

void del(map* s, const string& key)
{
    int h = to_hash(key);
    list* element = s->hash_values[h];
    list* prev = element;
    int i = 0;
    while (element != nullptr)
    {
        if (element->key == key && i == 0)
        {
            s->hash_values[h] = element->next;
            delete element;
            return;
        }
        else if (element->key == key)
        {
            prev->next = element->next;
            delete element;
            return;
        }
        prev = element;
        element = element->next;
        i = 1;
    }
}

void gets(map* s, const string& x)
{
    int h = to_hash(x);
    list* element = s->hash_values[h];
    if (element != nullptr)
    {
        do
        {
            if (element->key == x)
            {
                cout<<element->value<<"\n";
                return;
            }
            element = element->next;
        } while (element != nullptr);
    }
    cout<<"none\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    string key;
    string value;
    string command;
    map* hash = create_set(1000001);
    while(cin>>command)
    {
        if (command == "put")
        {
            cin>>key>>value;
            insert(hash, key, value);
        }
        if (command == "get")
        {
            cin>>key;
            gets(hash, key);
        }
        if (command == "delete")
        {
            cin>>key;
            del(hash, key);
        }
    }
}