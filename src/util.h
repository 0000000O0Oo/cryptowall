#ifndef FUXSOCY_UTIL_H_
#define FUXSOCY_UTIL_H_

#include <string>

#include <cryptopp/config.h>

namespace string_util {

std::string Base64Encode(const CryptoPP::byte* bytes, size_t length);
std::string Base64Decode(const std::string& str);

} // namespace string_util

#endif // FUXSOCY_UTIL_H_
