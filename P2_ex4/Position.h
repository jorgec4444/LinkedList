/* 
 * File:   Position.h
 * Author: JORGEC
 *
 * Created on 9 de abril de 2020, 16:28
 */


#ifndef POSITION_H
#define POSITION_H
#include "NodeList.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

using namespace std;

template <class Element>
class Position {
public:
    Position(NodeList<Element>* node) {
        _node = node;
    }

    Position<Element> next() const {
        if (_node->getNext() == nullptr)
            throw range_error("No hi ha següent node.");
        Position<Element> next_position(_node->getNext());
        return next_position;
    }

    Position<Element> previous() const {
        if (_node->getPrevious() == nullptr)
            throw range_error("No hi ha node previ.");
        Position<Element> next_position(_node->getNext());
        return next_position;

    }

    const Element& element() const {
        return _node->getElement();
    }

    void setPrevious(NodeList<Element>* node) {
        _node->setPrevious(node);
    }

    void setNext(NodeList<Element>* node) {
        _node->setNext(node);
    }

    Position<Element> operator++() const {
        return Position<Element>(_node->getNext());
    }

    bool operator==(const Position& other) const {
        return (other == _node);
    }

    bool operator!=(const Position& other) const {
        return (other != _node);
    }

    const Element& operator *() const {
        return _node->getElement();
    }
    
    NodeList<Element>* getNode(){
        return _node;
    }
    
private:
    NodeList<Element>* _node;
};

#endif /* POSITION_H */

