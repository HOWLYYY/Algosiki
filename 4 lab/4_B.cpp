#include <iostream>

using namespace std;

struct element* temp = NULL;
struct element* top = NULL;
int index=0;

struct element{
    int value;
    struct element* next;
};


void push(int amount){
    struct element* NewElement = (struct element*) malloc(sizeof(struct element));
    NewElement->value = amount;
    NewElement->next = top;
    top = NewElement;
    index++;
}

void pop(){
    temp = top;
    for (int i = 0; i < index-1; i++)
    {
        temp = temp->next;
    }
    cout << temp->value << "\n";
    index--;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string commands;
    int M,k;
    freopen ("queue.in", "r", stdin);
    freopen ("queue.out", "w", stdout);
    cin >> M;

    for (int i = 0; i < M; i++){
        cin >> commands;
        if (commands=="+"){
            cin >> k;
            push(k);
        }
        else{
            pop();
        }
    }
}