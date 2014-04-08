#ifndef MAP_H
#define MAP_H

#include <utility>          // pair

/**
Map interface, to be implemented by other classes.

@tparam KEY the key type of the map
@tparam VAL the value type value of the map.
@todo Add a key value iterator interface and implement str() in terms of it.
*/
template<class KEY,class VAL>
class Map {
    /**
    Initialize hash map with single key value pair
    */
    Map(const KEY& key, const VAL& val,
        size_t keyCountInitial = Map::keyCountInitialDefault,
        float loadFactor = 0.7
    ) : Map(keyCountInitial, loadFactor)
    { this->add(key, val); }

    /**
    Initialize map with many key value pairs.
    */
    Map(std::initializer_list<std::pair<KEY,VAL>> pairs) : Map() {
        for (auto& pair : pairs)
            this->add(pair);
    }

    virtual bool add(const KEY& key, const VAL& val) = 0;
    virtual bool del(const KEY& key) = 0;
    virtual bool find(const KEY& key, VAL& val) const = 0;
    virtual bool operator==(const Map<KEY,VAL>& other) const = 0;
    virtual bool operator!=(const Map<KEY,VAL>& other) const = 0;
    virtual std::string str() const = 0;

    /**
    std::pair add based on add(key,val).
    */
    bool add(const std::pair<KEY,VAL>& pair) { return add(std::get<0>(pair), std::get<1>(pair)); }

    /**
    ostream << operator. Based on str.
    */
    friend std::ostream& operator<<(std::ostream& os, const Map<KEY,VAL>& rhs) { return os << rhs.str(); }
};

#endif
