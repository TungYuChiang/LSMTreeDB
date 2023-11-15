#ifndef DB_H_
#define DB_H_

#include <atomic>
#include <string>
#include "../include/status.h"
#include "../table/memtable.h"

class DB{
  public:
    DB() = delete;
    DB(const std::string &dbpath);
    ~DB();

    static Status Create(const std::string &dbname);
    static Status Open(const std::string &dbname, DB **dbprt);
    static Status Destory(const std::string &dbname);

    Status Put(const std::string &key, const std::string &value);
    Status Delete(const std::string &key);
    Status Get(const std::string &key, std::string &value);
    Status Write(const std::string &key, const std::string &value,
                const Table::KeyType &kt);

  private:
    std::string dbname_;
    Table::MemTable *mtable_;

    std::atomic<int64_t> seq_;
};

#endif