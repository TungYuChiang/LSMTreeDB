#include "file_manager.h"
#include <string.h>
#include <filesystem>

namespace fs = std::filesystem;


Status FileManager::Create(const std::string &dbpath, FileType ft) {
    if (ft == T_DIR) {
        if (!fs::exists(dbpath)) {
            fs::create_directory(dbpath);
        } else {
            return S_EXISTS;
        }
    } else if (ft == T_FILE) {
        // TODO
        return S_ERROR;
    }
    return S_OK;
}

Status FileManager::Delete(const std::string &dbpath) {
    if (fs::exists(dbpath) && fs::is_directory(dbpath)) {
        fs::remove_all(dbpath);
    } else {
        return S_NOTFOUND;
    }
    return S_OK;
}