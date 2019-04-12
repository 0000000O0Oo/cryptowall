#include <iostream>
#include <string>

#include "malware/file_encryptor.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char* args[]) {
  cout << "Please enter your IV: ";
  string b64_iv;
  cin >> b64_iv;

  cout << "Please enter your key: ";
  string b64_key;
  cin >> b64_key;

  FileEncryptor encryptor(b64_iv, b64_key);
  for (const auto& file : encryptor.ListDirectory("/home/aesophor/Temp")) {
    encryptor.Decrypt(file);
  }

  cout << "Decryption complete! " << endl;
  return EXIT_SUCCESS;
}
