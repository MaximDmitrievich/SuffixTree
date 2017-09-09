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

    inline void SetFirstPos(const int& value) 
    { 
        this->firstpos = value; 
    }
    inline const int& GetFirstPos() {
        const int& result = this->firstpos;
        return result;
    }

    inline void SetEdgeLength(const int& value)
    {
        this->edgelength = value;
    }
    inline const int& GetEdgeLength()
    {
        const int& result = this->edgelength;
        return result;
    }

    inline void SetParent(TNode *value)
    {
        this->parent = value;
    }
    inline TNode *GetParent()
    {
        return this->parent;
    }

    inline void SetLink(const int& value, TNode* nodevalue)
    {
        this->link.insert(std::pair<int, TNode *>(value, nodevalue));
    }
    inline std::map<int, TNode *> &GetLink()
    {
        return this->link;
    }

    inline void SetSuffixLink(TNode *value)
    {
        this->suffixlink = value;
    }
    inline TNode *GetSuffixLink()
    {
        return this->suffixlink;
    }
};

#endif
