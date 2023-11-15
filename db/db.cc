#include "db.h"
#include <memory>
#include "file_manager.h"


DB::DB(const std::string &dbpath)
    : dbname_(dbpath), mtable_(new Table::MemTable) {}

DB::~DB() { delete mtable_; }

Status DB::Create(const std::string &dbname) {
    return FileManager::Create(dbname, T_DIR);
}

Status DB::Destory(const std::string &dbname) {
    return FileManager::Delete(dbname);
}

Status DB::Open(const std::string &dbname, DB **dbptr) {
    if (S_OK != FileManager::Exists(dbname)) {
        return S_NOTFOUND;
    }
    DB *db = new DB(dbname);
    *dbptr = db;
    return S_OK;
}