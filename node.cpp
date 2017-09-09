#include "node.h"

TNode::TNode(const int& firstposvalue, const int& edgelengthvalue, TNode *parentvalue)
{
    this->firstpos = firstposvalue;
    this->edgelength = edgelengthvalue;
    this->parent = parentvalue;
}

TNode::~TNode()
{
    this->parent = nullptr;
    this->suffixlink = nullptr;
    for (std::map<int, TNode *>::iterator it = this->link.begin(); it != this->link.end(); it++) {
        delete it->second;
    }
    this->link.clear();
}

