#ifndef FILE_MANAGER_H_
#define FILE_MANAGER_H_

#include <string>
#include "../include/status.h"

enum FileType {
    T_DIR,
    T_FILE,
};

class FileManager {
   public:
    static Status Create(const std::string &path, FileType ft);
    static Status Delete(const std::string &path);
    static Status Exists(const std::string &path);

   private:
    std::string path_;
};


#endif