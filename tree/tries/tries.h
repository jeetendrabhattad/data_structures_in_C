#include <iostream>
#include <map>
#include <memory>

class Trie {
public:
    Trie();
    ~Trie();
    void insert(const std::string input_string);
    bool search(const std::string search_string);
    void Display();
private:
    void DisplayMap(std::map<char, Trie* >);
    void Free(std::map<char, Trie*>);
    std::map<char, Trie*> trie_root;
    bool last;
};
