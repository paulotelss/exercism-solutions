#include "crypto_square.h"

#include <cctype>
#include <cmath>
#include <string>
#include <vector>

namespace crypto_square {

    static bool is_alnum(unsigned char ch) {
        return std::isalnum(ch) != 0;
    }

    std::string normalized_plaintext(const std::string& text) {
        std::string out;
        out.reserve(text.size());

        for (unsigned char ch : text) {
            if (is_alnum(ch)) {
                out.push_back(static_cast<char>(std::tolower(ch)));
            }
        }
        return out;
    }

    std::size_t square_size(const std::string& text) {
        const std::string norm = normalized_plaintext(text);
        const std::size_t n = norm.size();
        if (n == 0) return 0;

        // c = ceil(sqrt(n))
        const double root = std::sqrt(static_cast<double>(n));
        return static_cast<std::size_t>(std::ceil(root));
    }

    std::vector<std::string> plaintext_segments(const std::string& text) {
        const std::string norm = normalized_plaintext(text);
        const std::size_t n = norm.size();
        if (n == 0) return {};

        const std::size_t c = square_size(text);
        const std::size_t r = (n + c - 1) / c;  // ceil(n / c)

        std::vector<std::string> rows;
        rows.reserve(r);

        for (std::size_t i = 0; i < r; ++i) {
            const std::size_t start = i * c;
            const std::size_t len = (start < n) ? std::min(c, n - start) : 0;

            std::string row = norm.substr(start, len);
            if (row.size() < c) row.append(c - row.size(), ' '); // padding
            rows.push_back(row);
        }

        return rows;
    }

    std::string ciphertext(const std::string& text) {
        const auto rows = plaintext_segments(text);
        if (rows.empty()) return "";

        const std::size_t r = rows.size();
        const std::size_t c = rows[0].size();

        std::string out;
        out.reserve(r * c);

        // ler por colunas
        for (std::size_t col = 0; col < c; ++col) {
            for (std::size_t row = 0; row < r; ++row) {
                out.push_back(rows[row][col]);
            }
        }
        return out;
    }

    std::string normalized_ciphertext(const std::string& text) {
        const auto rows = plaintext_segments(text);
        if (rows.empty()) return "";

        const std::size_t r = rows.size();
        const std::size_t c = rows[0].size();

        // c chunks, cada um com tamanho r
        std::vector<std::string> chunks;
        chunks.reserve(c);

        for (std::size_t col = 0; col < c; ++col) {
            std::string chunk;
            chunk.reserve(r);

            for (std::size_t row = 0; row < r; ++row) {
                chunk.push_back(rows[row][col]);
            }
            chunks.push_back(chunk);
        }

        std::string out;
        for (std::size_t i = 0; i < chunks.size(); ++i) {
            if (i) out.push_back(' ');
            out += chunks[i];
        }
        return out;
    }

    // Alias compatível com vários testes do Exercism
    std::string cipher_text(const std::string& text) {
        return normalized_ciphertext(text);
    }

}  // namespace crypto_square
