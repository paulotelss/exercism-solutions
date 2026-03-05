#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {

class scheduler {
public:
    scheduler(int month, int year);

    // Gerador de métodos usando Boost::Date
    #define WEEKDAY_METHODS(day_name, day_index) \
        boost::gregorian::date day_name##teenth() const { return find_day(13, 19, day_index); } \
        boost::gregorian::date first_##day_name() const { return find_day(1, 7, day_index); } \
        boost::gregorian::date second_##day_name() const { return find_day(8, 14, day_index); } \
        boost::gregorian::date third_##day_name() const { return find_day(15, 21, day_index); } \
        boost::gregorian::date fourth_##day_name() const { return find_day(22, 28, day_index); } \
        boost::gregorian::date last_##day_name() const { return find_last(day_index); }

    WEEKDAY_METHODS(monday, boost::gregorian::Monday)
    WEEKDAY_METHODS(tuesday, boost::gregorian::Tuesday)
    WEEKDAY_METHODS(wednesday, boost::gregorian::Wednesday)
    WEEKDAY_METHODS(thursday, boost::gregorian::Thursday)
    WEEKDAY_METHODS(friday, boost::gregorian::Friday)
    WEEKDAY_METHODS(saturday, boost::gregorian::Saturday)
    WEEKDAY_METHODS(sunday, boost::gregorian::Sunday)

    // Aliases para os nomes curtos que o Catch2 exige
    boost::gregorian::date monteenth() const { return mondayteenth(); }
    boost::gregorian::date tuesteenth() const { return tuesdayteenth(); }
    boost::gregorian::date wednesteenth() const { return wednesdayteenth(); }
    boost::gregorian::date thursteenth() const { return thursdayteenth(); }
    boost::gregorian::date friteenth() const { return fridayteenth(); }
    boost::gregorian::date saturteenth() const { return saturdayteenth(); }
    boost::gregorian::date sunteenth() const { return sundayteenth(); }

private:
    int m_month, m_year;
    boost::gregorian::date find_day(int start, int end, int target_dw) const;
    boost::gregorian::date find_last(int target_dw) const;
};

} // namespace meetup