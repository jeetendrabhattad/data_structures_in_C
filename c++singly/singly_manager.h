#ifndef SINGLY_MANAGER_H
#define SINGLY_MANAGER_H
#include "singly.h"
#include <iostream>

template <class T>
class SinglyManager {
public:
    SinglyManager();
    ~SinglyManager();
    void Insert(const T data);
    void DisplayList();
    void DeleteNode(const T data);
    void DeleteByPosition(const unsigned int position);
    bool Search(const T data);
private:
    ListElement<T> *head;
};
template <class T>
SinglyManager<T>::SinglyManager() : head(0) {
    std::cout<<"SinglyManager Constructor\n";    
}

template <class T>
SinglyManager<T>::~SinglyManager() {
    ListElement<T> *traverse = head;
    while(head)
    {
        head = head->getNext();
        delete traverse;
        traverse = head;
    }
}

template <class T>
void SinglyManager<T>::Insert(const T data) {
    ListElement<T> *element = new ListElement<T>(data);
    if(!head)
    {
        head = element;
    }
    else
    {
        ListElement<T> *traverse;
        for(traverse = head ; traverse->getNext() ; traverse = traverse->getNext());
        traverse->setNext(element);
    }
}

template <class T>
void SinglyManager<T>::DisplayList() {
    ListElement<T> *traverse;
    for(traverse = head ; traverse ; traverse = traverse->getNext())
    {
        std::cout<<"Data:"<<traverse->getData()<<std::endl;
    }
}

template <class T>
void SinglyManager<T>::DeleteNode(const T data) {
    ListElement<T> *temp;
    if(head->getData() == data)
    {
        temp = head;
        head = head->getNext();
        delete temp;
    }
    else
    {
        ListElement<T> *traverse;
        ListElement<T> *previous;
        for(traverse = head ; traverse && traverse->getData() != data ; traverse = traverse->getNext())
        {
            previous = traverse;
        }
        if(traverse) {
            temp = traverse;
            previous->setNext(temp->getNext());
            temp->setNext(0);
            delete temp;
        }
        else {
            std::cout<<"No Node to delete\n";
        }
    }
}

template <class T>
void SinglyManager<T>::DeleteByPosition(const unsigned int position) {

}

template <class T>
bool SinglyManager<T>::Search(const T data) {

}
#endif
