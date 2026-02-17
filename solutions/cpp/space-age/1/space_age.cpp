#include "space_age.h"

namespace space_age {

// Coeficientes orbitais em relação à Terra
double space_age::on_earth() const   { return calculate_age(1.0); }
double space_age::on_mercury() const { return calculate_age(0.2408467); }
double space_age::on_venus() const   { return calculate_age(0.61519726); }
double space_age::on_mars() const    { return calculate_age(1.8808158); }
double space_age::on_jupiter() const { return calculate_age(11.862615); }
double space_age::on_saturn() const  { return calculate_age(29.447498); }
double space_age::on_uranus() const  { return calculate_age(84.016846); }
double space_age::on_neptune() const { return calculate_age(164.79132); }

}  // namespace space_age