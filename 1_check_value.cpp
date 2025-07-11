#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

class Node
{
    public:
        int val;
        Node* next;
        Node* prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, int val)
{
    Node* newnode = new Node(val);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }

    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
}

void print_doubly(Node* head, Node* head2)
{
    Node* temp = head;
    int cnt = 0;

    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    cout << endl;



    Node* temp2 = head2;
    int cnt2 = 0;

    while(temp2 != NULL)
    {
        cnt2++;
        temp2 = temp2->next;
    }
    temp = head;
    temp2 = head2;
    bool flag = true;

    if(cnt == cnt2)
    {
        while(temp != NULL)
        {
            if(temp->val != temp2->val)
            {
                flag = false;
                break;
            }
            temp = temp->next;
            temp2 = temp2->next;
        }
        if (flag == true)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while (cin >> val)
    {
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    Node* head2 = NULL;
    Node* tail2 = NULL;
    while (cin >> val)
    {
        if(val == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, val);
    }


    print_doubly(head, head2);
    
    

    return 0;
}