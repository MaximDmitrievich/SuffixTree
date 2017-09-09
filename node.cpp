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

void TNode::SetFirstPos(const int& value)
{
    this->firstpos = value;
}

const int& TNode::GetFirstPos()
{
    const int& result = this->firstpos;
    return result;
}

void TNode::SetEdgeLength(const int& value)
{
    this->edgelength = value;
}

const int& TNode::GetEdgeLength()
{
    const int& result = this->edgelength;
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

void TNode::SetLink(const int& value, TNode *nodevalue)
{
    this->link.insert(std::pair<int, TNode *>(value, nodevalue));
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

