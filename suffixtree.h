#ifndef _SUFFIXTREE_H_
#define _SUFFIXTREE_H_
#include "node.h"

class TSuffixTree {
private:
    TNode *root;
    int n;
    int pos;
    std::vector<int> symbolpos;
    TNode *SetFirst(int value, std::string &pattern);
public:
    TSuffixTree();
    virtual ~TSuffixTree();

    void EnterPattern(int value);
    void MatchStatistic(std::vector<int> &value, std::string &text);
};

#endif
