// src/event_csv.cpp
#include "clubhub/event_csv.hpp"

#include <stdexcept>
#include <string>
#include <vector>

#include "clubhub/event.hpp"

namespace clubhub {

namespace {


std::vector<std::string> splitCsvLine(const std::string& line) {
    std::vector<std::string> fields;
    std::size_t start = 0;
    while (true) {
        const std::size_t comma = line.find(',', start);
        if (comma == std::string::npos) {
            fields.push_back(line.substr(start));
            break;
        }
        fields.push_back(line.substr(start, comma - start));
        start = comma + 1;
    }
    return fields;
}


int parseCapacity(const std::string& text) {
    std::size_t pos = 0;
    int value = 0;
    try {
        value = std::stoi(text, &pos);
    } catch (const std::logic_error&) {  // invalid_argument or out_of_range
        throw std::invalid_argument{"bad capacity '" + text + "'"};
    }
    if (pos != text.size()) {
        throw std::invalid_argument{"bad capacity '" + text + "'"};
    }
    return value;
}

} // namespace

EventLoadResult loadEventsCsv(std::istream& in) {
    EventLoadResult result;
    std::string line;
    int lineNo = 1;
    std::getline(in, line);  
    while (std::getline(in, line)) {
        ++lineNo;
        
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        try {
            
            const auto fields = splitCsvLine(line);
            if (fields.size() != 5) {
                throw std::invalid_argument{
                    "expected 5 fields, got " + std::to_string(fields.size())};
            }
            
            result.events.emplace_back(fields[0], fields[1],
                                       parseTimePoint(fields[2]), fields[3],
                                       parseCapacity(fields[4]));
        } catch (const std::invalid_argument& e) {
            
            result.errors.push_back({lineNo, e.what()});
        }
    }
    return result;
}

} // namespace clubhub
