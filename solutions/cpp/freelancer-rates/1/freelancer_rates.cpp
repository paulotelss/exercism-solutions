#include <cmath>

namespace freelancer_rates {

    static constexpr double hours_per_day = 8.0;
    static constexpr double billable_days_per_month = 22.0;

    double daily_rate(double hourly_rate) {
        return hourly_rate * hours_per_day;
    }

    double apply_discount(double price, double discount) {
        // discount vem em %, ex: 10.0 -> 10%
        return price * (1.0 - discount / 100.0);
    }

    int monthly_rate(double hourly_rate, double discount) {
        const double monthly = apply_discount(daily_rate(hourly_rate), discount) * billable_days_per_month;
        return static_cast<int>(std::ceil(monthly));
    }

    int days_in_budget(double budget, double hourly_rate, double discount) {
        const double discounted_day = apply_discount(daily_rate(hourly_rate), discount);
        return static_cast<int>(std::floor(budget / discounted_day));
    }

} // namespace freelancer_rates
