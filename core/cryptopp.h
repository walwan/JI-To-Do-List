#ifndef CRYTPOPP_H
#define CRYTPOPP_H

#include "aes.h"
using CryptoPP::AES;

#include <string>
using std::string;

extern string pwdHashKey;
extern string iv;

string encode_hex(const string &text);

string encode_hex(const char *text, size_t len);

string decode_hex(const string &hex);

string decode_hex(const char *hex, size_t len);

string randomPool(const size_t len = AES::BLOCKSIZE);

string sha1(const string &text, const int len = AES::DEFAULT_KEYLENGTH);

string encrypt(const string data, const string key, const string ivHex);

string decrypt(const string cipherhex, const string key, const string ivHex);

#endif // CRYTPOPP_H
