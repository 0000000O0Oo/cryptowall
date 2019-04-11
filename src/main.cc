#include <iostream>
#include <vector>
#include <string>

#include "file_encryptor.h"

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;

int main() {
  FileEncryptor encryptor("/home/aesophor/Temp");
  vector<string> files = encryptor.ListDirectory();

  for (const auto& file : files) {
    string new_name = file + ".fuxsc";
    cout << "encrypting: " << file << endl;
    encryptor.Encrypt(file);
    encryptor.Decrypt(file + ".fuxsc");
  }

  return EXIT_SUCCESS;
}
