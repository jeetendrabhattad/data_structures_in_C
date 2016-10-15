#include "tries.h"

Trie::Trie() : last(false)
{
    //std::cout<<"Constructor\n";
}

void Trie::Free(std::map<char, Trie*> it)
{
    for(auto t = it.begin() ; t != it.end() ; t++)
    {
        //std::cout<<(*t).first<<":"<<(*t).second->last<<std::endl;
        delete (*t).second;
    }
}

Trie::~Trie()
{
    //std::cout<<"Destructor\n";
    Free(trie_root);
}

void Trie::insert(const std::string input_string)
{
    int index = 0;
    auto it = &trie_root;
    int length = input_string.length();
    while(index < length)
    {   
        //std::cout<<input_string[index]<<std::endl;
        std::map<char, Trie*>::iterator new_it = (*it).find(input_string[index]);
        if(new_it != (*it).end())
        {
           it = &(*new_it).second->trie_root;
           if(index == length - 1)
           {
                (*new_it).second->last = true;
           }
        }
        else
        {
            Trie *temp = new Trie;
            if(index == length - 1)
                temp->last = true;
            //std::cout<<input_string[index]<<" inserting."<<std::endl;
            
            (*it).insert(std::pair<char, Trie* >(input_string[index], temp));
            it = &temp->trie_root;
        }
        index++;
    }
}

bool Trie::search(const std::string search_string)
{
    auto it = trie_root;
    int index = 0;
    int length = search_string.length();
    Trie *temp = NULL;
    while(index < length)
    {
        auto new_it = it.find(search_string[index]);
        if(new_it == it.end())
            break;
        temp = (*new_it).second;
        it = temp->trie_root;
        index++;
    }
    if(index == length && temp && temp->last)
        return true;
    return false;
}

void Trie::DisplayMap(std::map<char, Trie* > it)
{
    for(auto t = it.begin() ; t != it.end() ; t++)
    {
        std::cout<<(*t).first<<":"<<(*t).second->last<<":"<<(*t).second<<std::endl;
        DisplayMap((*t).second->trie_root);
    }
}

void Trie::Display()
{
    DisplayMap(trie_root);
}
int main()
{
    Trie t;
    t.insert("Tree");
    //t.Display();
    t.insert("Lloyd");
    //t.Display();
    t.insert("Trend");
    //t.Display();
    t.insert("Swaraj");
    //t.Display();
    t.insert("Swar");
    std::cout<<"Searching Lloyd "<<t.search("Lloyd")<<std::endl;
    std::cout<<"Searching Lloyd Electric"<<t.search("Lloyd Electric")<<std::endl;
    std::cout<<"Searching Llo "<<t.search("Llo")<<std::endl;
    std::cout<<"Searching Swaraj "<<t.search("Swaraj")<<std::endl;
    std::cout<<"Searching Swar "<<t.search("Swar")<<std::endl;
    t.Display();
    return 0;
}
