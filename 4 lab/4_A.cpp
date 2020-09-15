#include <iostream>

using namespace std;

struct Stack
{ 
    long value; 
    Stack *last;
};

Stack* add(long value, Stack* last)
{
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    temp->value = value;
    temp->last = last;
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long n, value;
    char sign; 
    freopen ( "stack.in", "r", stdin );
    freopen ( "stack.out", "w", stdout );
    cin >> n; 
    
    Stack* First;
    for ( int i = 0; i < n; i++ ) 
    { 
        cin >> sign; 
        if (sign == '+')
        {
            cin >> value; 
            First = add(value, First);
        } 
        else 
        { 
            cout << First->value << '\n';
            First = First->last;
        } 
    }
}