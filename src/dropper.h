#ifndef FUXSOCY_DROPPER_H_
#define FUXSOCY_DROPPER_H_

#include <string>

class Dropper {
 public:
  Dropper(const std::string& install_path);
  virtual ~Dropper() = default;

  void DropNote() const;

 private:
  static const std::string kHtmlFilename_;
  static const std::string kCssFilename_;
  static const std::string kLogoFilename_;

  std::string install_path_;
};

#endif // FUXSOCY_DROPPER_H_
