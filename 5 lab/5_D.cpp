#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define SEED 317

struct newSet
{
    string key;
    vector <vector<string>> element;
    newSet()
    {
        element.resize(SEED);
    }
};

struct newMultiMap
{
    vector <vector<newSet>> set;
    newMultiMap()
    {
        set.resize(10009);
    }
};

int to_hash(const string &key, int size)
{
    int hash_value = 0;
    for(char i : key)
    {
        hash_value = SEED * hash_value + i;
    }
    return abs(hash_value % size);
}
newMultiMap map;
vector <string> result;

void insert(const string& key, const string& value)
{
    int hash_key = to_hash(key, 10009);
    for (auto & i : map.set[hash_key])
    {
        if (i.key == key)
        {
            int elHash = to_hash(value, SEED);
            for (const auto & j : i.element[elHash])
            {
                if (j == value)
                    return;
            }
            i.element[elHash].push_back(value);
            return;
        }
    }
    auto* temp_set = new newSet;
    temp_set->key = key;
    temp_set->element[to_hash(value, SEED)].push_back(value);
    map.set[hash_key].push_back(*temp_set);
    delete temp_set;
}

void del(const string& key, const string& value)
{
    int hash_key = to_hash(key, 10009);
    for (auto & i : map.set[hash_key])
    {
        if (i.key == key)
        {
            int hash_value = to_hash(value, SEED);
            for (int j = 0; j < i.element[hash_value].size(); j++)
            {
                if (i.element[hash_value][j] == value)
                {
                    swap(i.element[hash_value][j], i.element[hash_value].back());
                    i.element[hash_value].pop_back();
                    return;
                }
            }
        }
    }
}

void full_delete(const string& key)
{
    int hash_key = to_hash(key, 10009);
    for (auto & i : map.set[hash_key])
    {
        if (i.key == key)
        {
            for(auto & j : i.element)
            {
                while(!j.empty())
                    j.pop_back();
            }
            return;
        }
    }
}

void get (const string& key)
{
    int hash_key = to_hash(key, 10009);
    for (auto & i : map.set[hash_key])
    {
        if (i.key == key)
        {
            for(auto & j : i.element)
            {
                for(const auto & k : j)
                {
                    result.push_back(k);
                }
            }
            return;
        }
    }
}

int main()
{
    ifstream file_for_in;
    ofstream file_for_out;
    file_for_in.open("multimap.in");
    file_for_out.open("multimap.out");

    while(!file_for_in.eof())
    {
        string command;
        file_for_in >> command;
        if (command == "put")
        {
            string key, value;
            file_for_in >> key >> value;
            insert(key, value);
        }
        if (command == "delete")
        {
            string key, value;
            file_for_in >> key >> value;
            del(key, value);
        }
        if (command == "deleteall")
        {
            string key;
            file_for_in >> key;
            full_delete(key);
        }
        if (command == "get")
        {
            string key;
            file_for_in >> key;
            get(key);
            file_for_out << result.size() << ' ';
            for (const auto & i : result)
                file_for_out << i << ' ';
            file_for_out << "\n";
            result.resize(0);
        }

    }

    file_for_in.close();
    file_for_out.close();
    return 0;
}