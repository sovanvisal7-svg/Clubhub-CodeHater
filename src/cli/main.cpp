int listEvents(const std::string& path) {
    std::ifstream file{path};
    if (!file) {
        std::cerr << "error: cannot open " << path << '\n';
        return 2;
    }
    auto [events, errors] = clubhub::loadEventsCsv(file);

    std::ranges::sort(events, {}, &clubhub::Event::start);

    std::size_t idW = 2, titleW = 5, locW = 8;
    for (const auto& e : events) {
        idW = std::max(idW, e.id().size());
        titleW = std::max(titleW, e.title().size());
        locW = std::max(locW, e.location().size());
    }
    constexpr int startW = 16;

    std::cout << std::left
              << std::setw(static_cast<int>(idW)) << "ID" << "  "
              << std::setw(static_cast<int>(titleW)) << "TITLE" << "  "
              << std::setw(startW) << "START" << "  "
              << std::setw(static_cast<int>(locW)) << "LOCATION" << "  "
              << "CAPACITY" << '\n';
    for (const auto& e : events) {
        std::cout << std::left
                  << std::setw(static_cast<int>(idW)) << e.id() << "  "
                  << std::setw(static_cast<int>(titleW)) << e.title() << "  "
                  << std::setw(startW) << clubhub::formatTimePoint(e.start())
                  << "  "
                  << std::setw(static_cast<int>(locW)) << e.location() << "  "
                  << e.capacity() << '\n';
    }

    std::cout << events.size() << " event(s)\n";
    for (const auto& err : errors) {
        std::cerr << path << ':' << err.line << ": skipped: " << err.message
                  << '\n';
    }
    return errors.empty() ? 0 : 1;
}