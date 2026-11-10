// tests/ConsoleOutputTest.cpp
// SPDX-License-Identifier: MIT
#include <gtest/gtest.h>

#include <string>

#include "clubhub/ConsoleOutput.h"

using namespace clubhub;

TEST(ConsoleOutput, StatusIsReadableWithoutColour) {
    std::string out = formatStatus(RegistrationStatus::Cancelled, false);
    EXPECT_EQ(out, "[CANCELLED]");
    EXPECT_EQ(out.find('\033'), std::string::npos);  // no ANSI codes
}

TEST(ConsoleOutput, ColouredStatusStillContainsTheWord) {
    std::string out = formatStatus(RegistrationStatus::CheckedIn, true);
    EXPECT_NE(out.find("CHECKED IN"), std::string::npos);
}

TEST(ConsoleOutput, ErrorContainsNextStep) {
    std::string out = formatError("could not import events.csv",
                                  "line 7 has 3 columns, expected 5",
                                  "fix line 7 and run again");
    EXPECT_NE(out.find("Next step:"), std::string::npos);
}