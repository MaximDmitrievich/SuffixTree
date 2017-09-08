#include "suffixtree.h"

int main(int argc, char** argv)
{
    std::string pattern, text;
    TSuffixTree st;
    std::cin >> pattern;
    for (int i = 0; i < pattern.size(); i++) {
        st.EnterPattern(pattern[i]);
    }
    while (std::cin >> text) {
        std::vector<int> matchstatistic (text.size(), 0);
        st.MatchStatistic(matchstatistic, text);
    }
    return 0;
}
