#include <iostream>
#include <vector>

using namespace std;

typedef struct list_element
{
    string key;
    string value;
    struct list_element* next;
    struct list_element* prev;
    struct list_element* listnext;
} list_element;

class List
{
    list_element *str;
public:
    List();
    void insert(const string& key, const string& value, list_element *head);
    void del(const string& key);
    list_element* exists(const string& key);
};

List::List()
{
    str = new list_element();
    str->value = str->key = "";
    str->listnext = nullptr;
}

void List::insert(const string& key, const string& value, list_element *head)
{
    list_element *new_element = exists(key);
    if (exists(key) == nullptr)
    {
        new_element = new list_element;
        new_element->key = key;
        new_element->value = value;
        new_element->listnext = str->listnext;
        str->listnext = new_element;
        list_element *tail = head->prev;
        tail->next = new_element;
        head->prev = new_element;
        new_element->next = head;
        new_element->prev = tail;
    }
    else
        new_element->value = value;
}

void List::del(const string& key)
{
    list_element *current_element = str;
    while (current_element->listnext != nullptr)
    {
        if (current_element->listnext->key == key)
        {
            list_element *to_delete = current_element->listnext;
            current_element->listnext = current_element->listnext->listnext;
            list_element *prev_element = to_delete->prev, *NextNode = to_delete->next;
            to_delete->prev->next = NextNode;
            to_delete->next->prev = prev_element;
            delete to_delete;
            return;
        }
        else
        {
            current_element = current_element->listnext;
        }
    }
}

list_element* List::exists(const string& key)
{
    list_element *current_element = str;
    while (current_element->listnext != nullptr)
    {
        if (current_element->listnext->key == key)
            return current_element->listnext;
        else
            current_element = current_element->listnext;
    }
    return nullptr;
}

class LinkedMap
{
    vector <List> linkmap;
    list_element *head;
    static int to_hash(const string& key);
public:
    LinkedMap();
    void insert(const string& key, const string& value);
    void del(const string& key);
    void exists(const string& key);
    void next(const string& K);
    void prev(const string& key);
};

LinkedMap::LinkedMap()
{
    linkmap.resize(1000001);
    head = new list_element;
    head->prev = head->next = head;
}

int LinkedMap::to_hash(const string &key)
{
    int hash_value = 0;
    for(char i : key)
    {
        hash_value = 317 * (hash_value % 7) + i;
    }
    return abs(hash_value % 1000001);
}

void LinkedMap::insert(const string& key, const string& value)
{
    linkmap[to_hash(key)].insert(key, value, head);
}

void LinkedMap::del(const string& key)
{
    linkmap[to_hash(key)].del(key);
}

void LinkedMap::exists(const string& key)
{
    list_element *result = linkmap[to_hash(key)].exists(key);
    if (result == nullptr)
        cout<<"none\n";
    else
        cout << result->value <<"\n";
}

void LinkedMap::prev(const string& key)
{
    list_element *result = linkmap[to_hash(key)].exists(key);
    if (result == nullptr || result->prev == head)
        cout<<"none\n";
    else
        cout<<result->prev->value<<"\n";
}

void LinkedMap::next(const string& K)
{
    list_element *result = linkmap[to_hash(K)].exists(K);
    if (result == nullptr || result->next == head)
        cout<<"none\n";
    else
        cout<<result->next->value<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    string key, value, command;
    LinkedMap map_fun;
    while(cin>>command)
    {
        if (command == "put")
        {
            cin>>key>>value;
            map_fun.insert(key, value);
        }
        if (command == "get")
        {
            cin>>key;
            map_fun.exists(key);
        }
        if (command == "delete")
        {
            cin>>key;
            map_fun.del(key);
        }
        if (command == "next")
        {
            cin>>key;
            map_fun.next(key);
        }
        if (command == "prev")
        {
            cin>>key;
            map_fun.prev(key);
        }
    }
}