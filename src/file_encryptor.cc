#include "file_encryptor.h"

#include <iostream>
#include <cstring>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::vector;
using std::string;

namespace file_encryptor {

vector<string> ListDirectory(string& directory) {
  // If `directory` doesn't end with a slash, then append a slash.
  directory += (directory.back() != '/') ? "/" : "";

  vector<string> files;
  queue<string> q;
  q.push(directory);

  while (!q.empty()) {
    DIR* dir;
    dirent* ent;

    if ((dir = opendir(q.front().c_str()))) {
      while ((ent = readdir(dir))) {
        // If the entry it is not "." or "..", and...
        // it is a directory then push it into the queue,
        // otherwise, add it to the vector.
        if (strcmp(ent->d_name, ".") && strcmp(ent->d_name, "..")) {
          if (ent->d_type == DT_DIR) {
            q.push(directory + ent->d_name + '/');
          } else {
            files.push_back(q.front() + ent->d_name);
          }
        }
      }
      closedir(dir);
    }
    q.pop();
  }

  return files;
}

} // namespace file_encryptor
