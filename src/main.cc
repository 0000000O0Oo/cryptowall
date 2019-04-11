extern "C" {
#include <stdio.h>
#include <errno.h>
#include <string.h>
}

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
  string dir = "/home/aesophor/Temp";
  vector<string> files = file_encryptor::ListDirectory(dir);

  for (const auto& file : files) {
    string new_name = file + ".fuxsc";

    int result = 0;
    result = rename(file.c_str(), new_name.c_str());

    if (result == 0) {
      cout << "renamed: " << file << " -> " << new_name << endl;
    } else {
      cout << file << endl;
      cout << "renamed failed. error code: " << result << endl;
    }
  }
}
