// src/banner.cpp
#include "clubhub/banner.hpp"

namespace clubhub {

std::string banner(std::string_view teamName) {
    const std::string rule(40, '=');
    std::string out;
    out += rule;
    out += '\n';
    out += "ITC Club Hub v" CLUBHUB_VERSION "\n";
    out += "Team: ";
    out += teamName;
    out += '\n';
    out += rule;
    out += '\n';
    return out;
}

}  // namespace clubhub