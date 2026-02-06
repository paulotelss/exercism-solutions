#include "difference_of_squares.h"

namespace difference_of_squares {

    static std::int64_t to_i64(int x) {
        return static_cast<std::int64_t>(x);
    }

    // (1 + 2 + ... + n)^2, onde soma = n(n+1)/2
    std::int64_t square_of_sum(int n) {
        const std::int64_t nn = to_i64(n);
        const std::int64_t sum = (nn * (nn + 1)) / 2;
        return sum * sum;
    }

    // 1^2 + 2^2 + ... + n^2 = n(n+1)(2n+1)/6
    std::int64_t sum_of_squares(int n) {
        const std::int64_t nn = to_i64(n);
        return (nn * (nn + 1) * (2 * nn + 1)) / 6;
    }

    std::int64_t difference(int n) {
        return square_of_sum(n) - sum_of_squares(n);
    }

}  // namespace difference_of_squares
