#ifndef SINGLY_H
#define SINGLY_H

template <class T>
class ListElement {
public:
    ListElement(T val) : data(val), next(0) {}
    ~ListElement() {}
    void setNext(ListElement *element) {
        this->next = element;
    }
    ListElement* getNext() const {
        return this->next;
    }

    const T& getData() const{
        return this->data;
    }
    void setData(T value) {
        this->data = value;
    }
private:
    T data;
    ListElement *next;
};
#endif
