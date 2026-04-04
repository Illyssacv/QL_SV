#ifndef PASSWORD_HASHER_HPP
#define PASSWORD_HASHER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <openssl/evp.h>
#include <openssl/rand.h>

class PasswordHasher
{
private:
    static const int SALT_LEN = 16;
    static const int ITERATIONS = 100000;
    static const int HASH_LEN = 32;

    // Chuyển byte array sang chuỗi Hex để lưu trữ DB
    static std::string to_hex(const unsigned char *data, size_t len)
    {
        std::stringstream ss;
        for (size_t i = 0; i < len; ++i)
            ss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
        return ss.str();
    }

    // Chuyển Hex ngược lại byte array để kiểm tra
    static std::vector<unsigned char> from_hex(const std::string &hex)
    {
        std::vector<unsigned char> bytes;
        for (unsigned int i = 0; i < hex.length(); i += 2)
        {
            std::string byteString = hex.substr(i, 2);
            unsigned char byte = (unsigned char)strtol(byteString.c_str(), NULL, 16);
            bytes.push_back(byte);
        }
        return bytes;
    }

public:
    struct HashResult
    {
        std::string hash;
        std::string salt;
    };

    // Hàm băm mật khẩu mới
    static HashResult hashPassword(const std::string &password)
    {
        unsigned char salt[SALT_LEN];
        RAND_bytes(salt, SALT_LEN);

        unsigned char hash[HASH_LEN];
        PKCS5_PBKDF2_HMAC(password.c_str(), password.length(),
                          salt, SALT_LEN,
                          ITERATIONS, EVP_sha256(),
                          HASH_LEN, hash);

        return {to_hex(hash, HASH_LEN), to_hex(salt, SALT_LEN)};
    }

    // Hàm kiểm tra mật khẩu nhập vào với hash/salt đã lưu
    static bool verifyPassword(const std::string &password, const std::string &storedHash, const std::string &storedSalt)
    {
        std::vector<unsigned char> salt = from_hex(storedSalt);
        unsigned char newHash[HASH_LEN];

        PKCS5_PBKDF2_HMAC(password.c_str(), password.length(),
                          salt.data(), salt.size(),
                          ITERATIONS, EVP_sha256(),
                          HASH_LEN, newHash);

        return to_hex(newHash, HASH_LEN) == storedHash;
    }
};

#endif