#pragma once

#include <string>
#include <vector>

namespace crypto_square {

    class cipher {
    public:
        explicit cipher(const std::string& text);

        std::string normalized_plain_text() const;
        std::vector<std::string> plain_text_segments() const;
        std::string cipher_text() const;
        std::string normalized_cipher_text() const;

    private:
        std::string text_;
        std::size_t size() const;
    };

} // namespace crypto_square
