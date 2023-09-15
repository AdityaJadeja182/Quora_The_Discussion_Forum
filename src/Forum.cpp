#include "Forum.h"
#include <fstream>

Forum::Forum(Node* Array[], int MAX_INDEX)
{

    int idx;
    for (idx = 0; idx < MAX_INDEX; idx++) {//for each list in the array
        Node* newNode = new Node;//create a new node
        Array[idx] = newNode;//assign it to the array index
        newNode->nextNode = NULL;//initialize to null
        newNode->prevNode = NULL;//initialize to null
        newNode->content = "";//set to content to empty
        newNode->user = "";//set to content to empty
        newNode->time = "";//set to content to empty
    }
}

int Forum::addNode(string content, string user, string time, int arrayIndex, Node* Array[],int x)
{

    Node* topNode = Array[arrayIndex];//assign top node to variable
    if(topNode->content == "")
    {//if the top node is empty
        if(x==2)
        {
            return 1;
        }
        topNode->content = content;//assign the content to it
        topNode->user = user;
        topNode->time = time;
        return 2;
    }
    else
    {//otherwise
        Node* newNode = new Node;//create new node
        //insert node to list
        newNode->nextNode = topNode->nextNode;
        topNode->nextNode = newNode;
        newNode->prevNode = topNode;

        //if there's more than one node, set the inserted
        //node as the previous to the one it has replaced
        if (newNode->nextNode != NULL) {
            newNode->nextNode->prevNode = newNode;
        }
        newNode->content = content;//assign the content
        newNode->user = user;
        newNode->time = time;
        return 3;

    }

}
