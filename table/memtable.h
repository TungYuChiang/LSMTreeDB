#ifndef MEM_TABLE_H
#define MEM_TABLE_H

#include "../include/status.h"
#include <string>

using namespace std;

namespace Table{


enum KeyType {
    K_ADD,
    K_DELETE,
};

struct MemKey {
    string user_key_;
    int64_t seq_;
    KeyType kt_;

    MemKey(string userKey, int64_t seq, KeyType kt)
        : user_key_(userKey), seq_(seq), kt_(kt) {}

    MemKey(const string &key) : user_key_(key), seq_(INT64_MAX), kt_(K_ADD) {}

    bool operator<(const MemKey &other) const {
        if (user_key_ == other.user_key_) {
            return seq_ > other.seq_;
        }
        return user_key_ < other.user_key_;
    }
};

class MemTable{
  public:
    
};
}



#endif