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
    TNode(const int& firstposvalue, const int& edgelengthvalue, TNode *parentvalue);
    virtual ~TNode();

    void SetFirstPos(const int& value);
    const int& GetFirstPos();

    void SetEdgeLength(const int& value);
    const int& GetEdgeLength();

    void SetParent(TNode *value);
    TNode *GetParent();

    void SetLink(const int& value, TNode* nodevalue);
    std::map<int, TNode *> &GetLink();

    void SetSuffixLink(TNode *value);
    TNode *GetSuffixLink();
};

#endif
