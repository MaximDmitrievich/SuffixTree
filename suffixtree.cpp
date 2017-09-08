#include "suffixtree.h"

TSuffixTree::TSuffixTree()
{
    this->n = 0;
    this->pos = 0;
    this->root = new TNode(0, INFINITY, nullptr);
    this->root->SetParent(this->root);
}

TSuffixTree::~TSuffixTree()
{
    if (this->root != nullptr) {
        delete this->root;
    }
    this->n = 0;
    this->pos = 0;
    this->symbolpos.clear();
}

void TSuffixTree::EnterPattern(int value)
{
    symbolpos.push_back(value);
    this->n++;
    this->pos++;
    TNode *curr = this->root;
    TNode *last = this->root;
    while (this->pos > 0) {
        while ((curr->GetLink().find(this->symbolpos[this->n - this->pos]) != curr->GetLink().end()) &&
            (this->pos > curr->GetLink()[this->symbolpos[this->n - this->pos]]->GetEdgeLength())) {
            curr = curr->GetLink()[this->symbolpos[this->n - this->pos]];
            this->pos -= curr->GetEdgeLength();
        }
        int edge = this->symbolpos[this->n - this->pos];
        std::map<int, TNode *>::iterator it = curr->GetLink().find(edge);
        int temp = (it == curr->GetLink().end()) ? -1 : symbolpos[it->second->GetFirstPos() + this->pos - 1];
        if (it == curr->GetLink().end()) {
            curr->SetLink(edge, new TNode(this->n - this->pos, INFINITY, curr));
            last->SetSuffixLink(curr);
            last = this->root;
        } else if (temp == value) {
            last->SetSuffixLink(curr);
            return;
        } else {
            TNode *splitnode = new TNode(it->second->GetFirstPos(), this->pos - 1, it->second->GetParent());
            splitnode->SetLink(value, new TNode(this->n - 1, INFINITY, splitnode));
            splitnode->SetLink(temp, it->second);
            it->second->SetFirstPos(it->second->GetFirstPos() + this->pos - 1);
            it->second->SetEdgeLength(it->second->GetEdgeLength() - this->pos - 1);
            it->second->SetParent(splitnode);
            it->second = splitnode;
            last->SetSuffixLink(splitnode);
            last = splitnode;
        }
        if (curr == this->root) {
            --this->pos;
        } else {
            curr = curr->GetSuffixLink();
        }
    }
}

TNode *TSuffixTree::SetFirst(int value, std::string &pattern)
{
    int another = pattern.find(pattern[0]);
    TNode *curr = this->root;
    if (another != std::string::npos) {
        std::map<int, TNode *>::iterator it = curr->GetLink().find(pattern[0]);
        while (another < pattern.size()) {
            if (it != curr->GetLink().end()) {
                for (int j = 0, i = it->second->GetFirstPos(); j < it->second->GetEdgeLength() && i < this->n && another < pattern.size(); i++, another++, j++) {
                    if (pattern[another] != this->symbolpos[i]) {
                        return curr;
                    }
                    value++;
                }
                curr = it->second;
                it = it->second->GetLink().find(pattern[another]);
            } else {
                return curr;
            }
        }
    }
    return curr;
}

void TSuffixTree::MatchStatistic(std::vector<int> &value, std::string &text)
{
    this->root->SetSuffixLink(this->root);
    TNode *curr = this->SetFirst(value[0], text);
    for (int i = 1; i < value.size(); i++) {
        if (value[i - 1] == this->n) {
            std::cout << i << std::endl;
        }
        int nodeegin = curr->GetFirstPos();
        int left = this->n - curr->GetFirstPos();
        curr = (curr->GetEdgeLength() > this->n) ? curr->GetParent()->GetSuffixLink() : curr->GetSuffixLink();
        while (left > curr->GetEdgeLength()) {
            for (auto it : curr->GetLink()) {
                if (it.second->GetFirstPos() == nodeegin) {
                    curr = it.second;
                    break;
                }
            }
            left -= curr->GetEdgeLength();
            nodeegin += this->n - curr->GetFirstPos();
        }
        for (int j = i, k = nodeegin; j < text.size() && k < n; ++j, ++k) {
            if (text[j] != this->symbolpos[k]) {
                break;
            }
            ++value[i];
            if (k == curr->GetEdgeLength()) {
                std::map<int, TNode *>::iterator it = curr->GetLink().find(text[j + 1]);
                if (it != curr->GetLink().end()) {
                    curr = it->second;
                    k = curr->GetFirstPos();
                } else {
                    k = this->n + 1;
                }
            }
        }
    }
}



