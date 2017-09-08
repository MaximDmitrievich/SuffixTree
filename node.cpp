#include "node.h"

TNode::TNode(int firstposvalue, int edgelengthvalue, TNode *parentvalue)
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

void TNode::SetFirstPos(int value)
{
    this->firstpos = value;
}

int TNode::GetFirstPos()
{
    int result = this->firstpos;
    return result;
}

void TNode::SetEdgeLength(int value)
{
    this->edgelength = value;
}

int TNode::GetEdgeLength()
{
    int result = this->edgelength;
    return result;
}

void TNode::SetParent(TNode *value)
{
    this->parent = value;
}

TNode *TNode::GetParent()
{
    TNode *result = this->parent;
    return result;
}

TNode *TNode::SetLink(int value, TNode *nodevalue)
{
    this->link.insert(std::pair<int, TNode *>(value, nodevalue));
    TNode *result = this->link.find(value)->second;
    return result;
}

std::map<int, TNode *> &TNode::GetLink()
{
    return this->link;
}

void TNode::SetSuffixLink(TNode *value)
{
    this->suffixlink = value;
}

TNode *TNode::GetSuffixLink()
{
    TNode *result = this->suffixlink;
    return result;
}

