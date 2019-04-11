#include <iostream>
#include <vector>
#include <string>

#include "file_encryptor.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char* args[]) {
  FileEncryptor encryptor("/home/aesophor/Temp");
  vector<string> files = encryptor.ListDirectory();

  for (const auto& file : files) {
    cout << "encrypting: " << file << endl;
    encryptor.Encrypt(file);
    encryptor.Decrypt(file + ".fuxsc");
  }

  cout << encryptor.Export() << endl;
  return EXIT_SUCCESS;
}
