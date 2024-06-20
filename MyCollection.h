#ifndef MYCOLLECTION_H
#define MYCOLLECTION_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
template<typename T>
class Array : public Collection<T> {
private:
    vector<T> elements;

public:
    Array() {}

    void add(const T& item) override {
        elements.push_back(item);
    }

    void addAll(const Collection<T>& items) override {
        for (size_t i = 0; i < items.size(); ++i) {
            elements.push_back(items[i]);
        }
    }

    void clear() override {
        elements.clear();
    }

    size_t size() const override {
        return elements.size();
    }

    bool isEmpty() const override {
        return elements.empty();
    }

    const T& operator[](size_t index) const override {
        return elements[index];
    }

    T& operator[](size_t index) override {
        return elements[index];
    }
};
#endif
