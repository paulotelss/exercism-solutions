#pragma once

namespace space_age {

class space_age {
public:
    explicit space_age(long long seconds) : age_seconds(seconds) {}

    long long seconds() const { return age_seconds; }

    // Métodos exigidos pelos testes
    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;

private:
    long long age_seconds;
    static constexpr double earth_year_in_seconds = 31557600.0;
    
    // Função auxiliar centralizada
    double calculate_age(double orbital_period) const {
        return age_seconds / (earth_year_in_seconds * orbital_period);
    }
};

}  // namespace space_age