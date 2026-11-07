// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team CodeHater, ITC Club Hub contributors
#include "clubhub/event.hpp"

#include <chrono>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

namespace clubhub {

Event::Event(std::string id, std::string title, TimePoint start,
             std::string location, int capacity)
    : id_{std::move(id)}, title_{std::move(title)}, start_{start},
      location_{std::move(location)}, capacity_{capacity} {
    if (id_.empty()) {
        throw std::invalid_argument{"Event id must not be empty"};
    }
    if (title_.empty()) {
        throw std::invalid_argument{"Event title must not be empty"};
    }
    if (capacity_ <= 0) {
        throw std::invalid_argument{"Event capacity must be positive"};
    }
}

TimePoint parseTimePoint(const std::string& text) {
    using namespace std::chrono;
    const auto bad = [&text] {
        return std::invalid_argument{"bad date-time '" + text + "'"};
    };

    std::istringstream in{text};
    int y{}, mo{}, d{}, h{}, mi{};
    char dash1{}, dash2{}, colon{};
    in >> y >> dash1 >> mo >> dash2 >> d >> h >> colon >> mi;

    // Stream must have extracted everything, with the right separators.
    if (in.fail() || dash1 != '-' || dash2 != '-' || colon != ':') {
        throw bad();
    }
    // Nothing may follow the minutes (reading to the end sets eofbit,
    // which peek() handles fine).
    if (in.peek() != std::istringstream::traits_type::eof()) {
        throw bad();
    }
    // Range-check before narrowing into chrono's unsigned char fields,
    // otherwise values like 257 would wrap into a valid month/day.
    if (mo < 1 || mo > 12 || d < 1 || d > 31 ||
        h < 0 || h > 23 || mi < 0 || mi > 59) {
        throw bad();
    }

    const year_month_day date{year{y}, month{static_cast<unsigned>(mo)},
                              day{static_cast<unsigned>(d)}};
    if (!date.ok()) {  // e.g. 2026-02-30
        throw bad();
    }
    return sys_days{date} + hours{h} + minutes{mi};
}

// Given: TimePoint -> "2026-10-14 14:00"
std::string formatTimePoint(TimePoint t) {
    using namespace std::chrono;
    const auto midnight = floor<days>(t);
    const year_month_day date{midnight};
    const hh_mm_ss time{t - midnight};
    std::ostringstream out;
    out << std::setfill('0') << static_cast<int>(date.year()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.month()) << '-'
        << std::setw(2) << static_cast<unsigned>(date.day()) << ' '
        << std::setw(2) << time.hours().count() << ':'
        << std::setw(2) << time.minutes().count();
    return out.str();
}

} // namespace clubhub