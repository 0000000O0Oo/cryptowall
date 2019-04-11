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
    //rename(file.c_str(), new_name.c_str());
    cout << "renamed: " << file << " -> " << new_name << endl;
  }
}
