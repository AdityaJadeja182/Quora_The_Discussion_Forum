#ifndef FORUM_H
#define FORUM_H
#include "bits/stdc++.h"

using namespace std;

struct Node
{
    Node *nextNode;
    Node *prevNode;
    string content;
    string user;
    string time;
};

class Forum
{
    public:
        Forum(Node* Array[], int MAX_INDEX);
        int addNode(string content, string user, string time, int arrayIndex, Node* Array[],int x);
    protected:

    private:

};

#endif // FORUM_H
