#ifndef SWAPANDSERVE_CHAININGHASHMAP_H
#define SWAPANDSERVE_CHAININGHASHMAP_H

#include <vector>
#include <list>
#include <string>
using namespace std;

template <typename K, typename V>
class ChainingHashMap {
private:
    struct HashNode {
        K key;
        V value;
        HashNode(K k, V v) : key(k), value(v) {}
    };

    vector<list<HashNode>> table;
    size_t capacity;
    size_t size;
    size_t hashFunction(const K& key) const;

public:
    ChainingHashMap(size_t cap = 100003);
    void insert(const K& key, const V& value);
    bool search(const K& key, V& outFile) const;
    size_t getSize() const;
};

#endif //SWAPANDSERVE_CHAININGHASHMAP_H