#include <cmath>

double daily_rate(double hourly_rate) {
    return hourly_rate * 8.0;
}

double apply_discount(double price, double discount) {
    return price * (1.0 - discount / 100.0);
}

int monthly_rate(double hourly_rate, double discount) {
    double monthly = daily_rate(hourly_rate) * 22.0;
    double discounted = apply_discount(monthly, discount);
    return static_cast<int>(std::ceil(discounted));
}

int days_in_budget(double budget, double hourly_rate, double discount) {
    double discounted_daily = apply_discount(daily_rate(hourly_rate), discount);
    return static_cast<int>(std::floor(budget / discounted_daily));
}
