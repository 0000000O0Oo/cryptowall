#include "file_encryptor.h"

#include <iostream>
#include <cstring>
#include <queue>

#include <cryptopp/osrng.h>
#include <cryptopp/modes.h>
#include <cryptopp/filters.h>

using std::queue;
using std::vector;
using std::string;

using CryptoPP::byte;
using CryptoPP::AES;
using CryptoPP::byte;
using CryptoPP::AutoSeededRandomPool;


FileEncryptor::FileEncryptor(const string& directory) : iv_(), key_(), directory_(directory) {
  AutoSeededRandomPool rnd;

  // Generate iv.
  iv_ = new byte[AES::BLOCKSIZE+1];
  rnd.GenerateBlock(iv_, AES::BLOCKSIZE);
  iv_[AES::BLOCKSIZE] = 0x00;

  // Generate key.
  key_ = new byte[AES::DEFAULT_KEYLENGTH + 1];
  rnd.GenerateBlock(key_, AES::DEFAULT_KEYLENGTH);
  key_[AES::DEFAULT_KEYLENGTH] = 0x00;

  // If `directory` doesn't end with a slash, then append a slash.
  directory_ += (directory_.back() != '/') ? "/" : "";
}

FileEncryptor::~FileEncryptor() {
  delete[] iv_;
  delete[] key_;
}


vector<string> FileEncryptor::ListDirectory() const {
  vector<string> files;
  queue<string> q;
  q.push(directory_);

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
            q.push(directory_ + ent->d_name + '/');
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
