#ifndef SWAPANDSERVE_CHAININGHASHMAP_CPP
#define SWAPANDSERVE_CHAININGHASHMAP_CPP

#include "ChainingHashMap.h"

template <typename K, typename V>
ChainingHashMap<K, V>::ChainingHashMap(size_t cap) : capacity(cap), size(0) {
    table.resize(capacity);
}

template<typename K, typename V>
size_t ChainingHashMap<K, V>::hashFunction(const K& key) const {
    size_t hashValue = 0;
    for (char const &c : key) {
        hashValue = 37 * hashValue + c;
    }
    return hashValue % capacity;
}

template <typename K, typename V>
void ChainingHashMap<K, V>::insert(const K& key, const V& value) {
    size_t index = hashFunction(key);
    for (auto& node : table[index]) {
        if (node.key == key) {
            node.value = value;
            return;
        }
    }

    table[index].emplace_back(key, value);
    size++;
}

template<typename K, typename V>
bool ChainingHashMap<K, V>::search(const K& key, V& outFile) const {
    size_t index = hashFunction(key);
    for (const auto& node : table[index]) {
        if (node.key == key) {
            outFile = node.value;
            return true;
        }
    }
    return false;
}

template<typename K, typename V>
size_t ChainingHashMap<K, V>::getSize() const {
    return size;
}

#endif //SWAPANDSERVE_CHAININGHASHMAP_H