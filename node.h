#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>

const int INFINITY = 1e9;

class TNode {
private:
    int firstpos;
    int edgelength;
    TNode *parent;
    std::map<int, TNode *> link;
    TNode *suffixlink;
public:
    TNode(int firstposvalue, int edgelengthvalue, TNode *parentvalue);
    virtual ~TNode();

    void SetFirstPos(int value);
    int GetFirstPos();

    void SetEdgeLength(int value);
    int GetEdgeLength();

    void SetParent(TNode *value);
    TNode *GetParent();

    TNode *SetLink(int value, TNode* nodevalue);
    std::map<int, TNode *> &GetLink();

    void SetSuffixLink(TNode *value);
    TNode *GetSuffixLink();
};

#endif
