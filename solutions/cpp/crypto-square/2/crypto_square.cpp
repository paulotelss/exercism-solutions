#include "crypto_square.h"

#include <cctype>
#include <cmath>

namespace crypto_square {

    cipher::cipher(const std::string& text) : text_(text) {}

    std::string cipher::normalized_plain_text() const {
        std::string result;
        for (char c : text_) {
            if (std::isalnum(static_cast<unsigned char>(c))) {
                result += std::tolower(static_cast<unsigned char>(c));
            }
        }
        return result;
    }

    std::size_t cipher::size() const {
        auto len = normalized_plain_text().size();
        return static_cast<std::size_t>(std::ceil(std::sqrt(len)));
    }

    std::vector<std::string> cipher::plain_text_segments() const {
        std::vector<std::string> segments;
        auto normalized = normalized_plain_text();
        auto c = size();

        for (std::size_t i = 0; i < normalized.size(); i += c) {
            segments.push_back(normalized.substr(i, c));
        }

        return segments;
    }

    std::string cipher::cipher_text() const {
        auto segments = plain_text_segments();
        auto c = size();
        std::string result;

        for (std::size_t col = 0; col < c; ++col) {
            for (const auto& row : segments) {
                if (col < row.size()) {
                    result += row[col];
                }
            }
        }

        return result;
    }

    std::string cipher::normalized_cipher_text() const {
        auto segments = plain_text_segments();
        auto c = size();
        std::string result;

        for (std::size_t col = 0; col < c; ++col) {
            if (col > 0) result += ' ';
            for (const auto& row : segments) {
                if (col < row.size()) {
                    result += row[col];
                }
                else {
                    result += ' ';
                }
            }
        }

        return result;
    }

} // namespace crypto_square
