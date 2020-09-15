#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;


class qaka
{
private:
    int max = 65536;
    uint16_t registers[26] = {};
    queue <uint16_t> values;
    map <string, int> labels;
public:
    void intor(const vector <string>& commands)
    {
        int i=0;
        uint16_t tmpint;
        string tmp;

        for(int j=0; j<commands.size(); j++)
        {
            char a = commands[j][0];
            if(a==':')
            {
                tmp = commands[j];
                tmp.erase(0, 1);
                labels[tmp] = j;
                continue;
            }
        }

        while(i<commands.size())
        {
            char a = commands[i][0];
            switch (a)
            {
                case ':':
                {
                    i++;
                    continue;
                }
                case '+' :
                {
                    tmpint = values.front();
                    values.pop();
                    tmpint += values.front();
                    values.pop();
                    values.push(tmpint % max);
                    i++;
                    continue;
                }

                case '-':
                {
                    tmpint = values.front();
                    values.pop();
                    tmpint = tmpint - values.front();
                    values.pop();
                    values.push(tmpint % max);
                    i++;
                    continue;
                }

                case '*':
                {
                    tmpint = values.front();
                    values.pop();
                    if(values.front()!=0) tmpint = tmpint * values.front();
                    else tmpint = 0;
                    values.pop();
                    values.push(tmpint % max);
                    i++;
                    continue;
                }

                case '/':
                {
                    tmpint = values.front();
                    values.pop();
                    if(values.front()!=0) tmpint = tmpint / values.front();
                    else tmpint = 0;
                    values.pop();
                    values.push(tmpint % max);
                    i++;
                    continue;
                }

                case '%':
                {
                    tmpint = values.front();
                    values.pop();
                    if(values.front()!=0) tmpint %= values.front();
                    else tmpint = 0;
                    values.pop();
                    values.push(tmpint % max);
                    i++;
                    continue;
                }

                case '>':
                {
                    registers[commands[i][1]-'a'] = values.front();
                    values.pop();
                    i++;
                    continue;
                }

                case '<':
                {
                    values.push(registers[commands[i][1]-'a']);
                    i++;
                    continue;
                }

                case 'P':
                {
                    if(commands[i].length()==1)
                    {
                        cout << values.front() << "\n";
                        values.pop();
                    }
                    else cout<<registers[commands[i][1]-'a']<<"\n";
                    i++;
                    continue;
                }

                case 'Q':
                {
                    return;
                }

                case 'C':
                {
                    if(commands[i].length()==1)
                    {
                        cout<<(char)(values.front()%256);
                        values.pop();
                    }
                    else cout<<(char)((registers[commands[i][1]-'a']%256));
                    i++;
                    continue;
                }

                case 'J':
                {
                    tmp = commands[i];
                    tmp.erase(0, 1);
                    i = labels[tmp];
                    continue;
                }
                case 'Z':
                {
                    if (registers[commands[i][1]-'a']==0)
                    {
                        tmp = commands[i];
                        tmp.erase(0, 2);
                        i = labels[tmp];
                        continue;
                    }
                    i++;
                    continue;
                }
                case 'E':
                {
                    if(registers[commands[i][1]-'a']==registers[commands[i][2]-'a'])
                    {
                        tmp = commands[i];
                        tmp.erase(0, 3);
                        i = labels[tmp];
                        continue;
                    }
                    i++;
                    continue;
                }
                case 'G':
                {
                    if(registers[commands[i][1]-'a']>registers[commands[i][2]-'a'])
                    {
                        tmp = commands[i];
                        tmp.erase(0, 3);
                        i = labels[tmp];
                        continue;
                    }
                    i++;
                    continue;
                }

                default:
                    values.push(stoi(commands[i]));
                    i++;
            }
        }
    }
};

int main()
{
    string command;
    freopen("quack.in", "r", stdin);
    freopen("quack.out", "w", stdout);
    vector <string> cmd;
    while(cin>>command)
    {
        cmd.push_back(command);
    }
    qaka exec;
    exec.intor(cmd);
}