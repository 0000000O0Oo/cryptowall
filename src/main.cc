#include <iostream>
#include <vector>
#include <string>

#include "file_encryptor.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main() {
  string dir = "/home/aesophor/Temp";
  vector<string> files = file_encryptor::ListDirectory(dir);

  for (const auto& file : files) {
    cout << file << endl;
  }
}
