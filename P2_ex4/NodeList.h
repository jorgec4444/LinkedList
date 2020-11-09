/* 
 * File:   NodeList.h
 * Author: JORGEC
 *
 * Created on 9 de abril de 2020, 16:52
 */

#ifndef NODELIST_H
#define NODELIST_H

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

template <class Element>
class NodeList {
public:
    NodeList(const Element data) {
        _element = data;
    }

    virtual ~NodeList() {
        if (_next->getElement() != " "){
            _next->setPrevious(_prev);
            _prev->setNext(_next);
            _next = nullptr;
            _prev = nullptr;
        } else {
            _next == nullptr;
            _prev = nullptr;
        }
        cout << "Node destructor called" << endl;
    }

    Element& getElement() {
        return _element;
    }

    NodeList<Element>* getNext() {
        return _next;
    }

    void setNext(NodeList* next) {
        _next = next;
    }

    NodeList<Element>* getPrevious() {
        return _prev;
    }

    void setPrevious(NodeList* prev) {
        _prev = prev;
    }
    
private:
    Element _element;
    NodeList* _next;
    NodeList* _prev;
};

#endif /* NODELIST_H */

