#ifndef MYCOLLECTION_H
#define MYCOLLECTION_H

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Collection {
public:
    //all methods are pure virtual (Collection now is an interface)
    virtual void add(const T& item) = 0;
    virtual void addAll(const Collection<T>& items) = 0;
    virtual bool remove(const T& item) = 0;
    virtual bool removeAll(const Collection<T>& items) = 0;
    virtual bool contains(const T& item) const = 0;
    virtual bool containsAll(const Collection<T>& items) const = 0;
    virtual bool equals(const Collection<T>& items) const = 0;
    virtual void clear() = 0;
    virtual size_t size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual const T& operator[](size_t index) const = 0;
    virtual T& operator[](size_t index) = 0;
    virtual ~Collection() {}
};

#endif //RESCUETHEPROJECT_MYCOLLECTION_H
