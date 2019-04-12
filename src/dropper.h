#ifndef FUXSOCY_DROPPER_H_
#define FUXSOCY_DROPPER_H_

#include <string>

class Dropper {
 public:
  Dropper(const std::string& install_path);
  virtual ~Dropper() = default;

  void DropNote() const;

 private:
  
};

#endif // FUXSOCY_DROPPER_H_
