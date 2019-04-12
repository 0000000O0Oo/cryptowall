#include "util.h"

#include <cryptopp/base64.h>

using std::string;
using CryptoPP::byte;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::Base64Encoder;
using CryptoPP::Base64Decoder;

namespace string_util {

string Base64Encode(const byte* bytes, size_t length) {
  string s;
  StringSource ssiv(bytes, length, true, new Base64Encoder(new StringSink(s), false));
  return s;
}

string Base64Decode(const string& str) {
  string s;
  StringSource ss(str, true, new Base64Decoder(new StringSink(s)));
  return s;
}

} // namespace string_util
