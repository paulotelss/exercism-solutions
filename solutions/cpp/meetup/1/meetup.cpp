#include "meetup.h"

namespace meetup {

scheduler::scheduler(int month, int year) : m_month(month), m_year(year) {}

boost::gregorian::date scheduler::find_day(int start, int end, int target_dw) const {
    for (int d = start; d <= end; ++d) {
        boost::gregorian::date d_obj(m_year, m_month, d);
        if (d_obj.day_of_week() == target_dw) {
            return d_obj;
        }
    }
    return boost::gregorian::date(); 
}

boost::gregorian::date scheduler::find_last(int target_dw) const {
    // Para o "last", pegamos o último dia do mês e voltamos até achar o dia da semana
    boost::gregorian::date last_day = boost::gregorian::date(m_year, m_month, 1).end_of_month();
    int d = last_day.day();
    return find_day(d - 6, d, target_dw);
}

} // namespace meetup