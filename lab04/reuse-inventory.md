# ITC Club Hub · Reuse Inventory

**Task:** Lab 04 – Task 5  
**Repository licence:** MIT  
**Storage format:** CSV

## 1. Make-or-reuse decisions

| Need | Options considered | Decision | Reason | Licence | Pinned version | Last release |
|---|---|---|---|---|---|---|
| Unit testing | GoogleTest, Catch2, manual testing | Reuse | GoogleTest provides assertions and test discovery. | BSD-3-Clause | v1.17.0 | 30 Apr 2025 |
| File storage (CSV) | rapidcsv, manual parsing, JSON | Reuse | rapidcsv provides convenient CSV reading without writing a parser from scratch. | BSD-3-Clause | v9.07 | 14 Sep 2026 |
| Date and time | C++20 chrono, date library | Build | Use the standard C++20 chrono library and implement the project's 24-hour validation rules. | Standard library; no separate licence | C++20 | N/A |
| CLI input handling | CLI11, standard C++ input | Build | The current CLI is simple enough to implement with cin and getline. | Standard library; no separate licence | C++20 | N/A |
| Registration rules | Custom implementation, external booking library | Build | Registration rules are specific to Club Hub, including capacity and duplicate prevention. | MIT (project code) | N/A | N/A |
| Reminders | External notification service, custom implementation | Defer | Notifications are not essential for the initial CLI version. | N/A | N/A | N/A |
| Monthly report | CSV reporting library, custom implementation | Build | The report has specific Club Hub requirements and can be generated using CSV output. | MIT (project code) | N/A | N/A |
| Logging | spdlog, standard console output | Defer | A separate logging dependency is unnecessary for the current development stage. | N/A | N/A | N/A |

## 2. Licence compatibility check

The repository uses the MIT licence.

### Reused libraries

**GoogleTest – BSD-3-Clause**
- Compatible with our MIT-licensed repository.
- Keep the original copyright notice.
- Include the BSD licence conditions and disclaimer when redistributing the library.

**rapidcsv – BSD-3-Clause**
- Compatible with our MIT-licensed repository.
- Preserve the original copyright notice.
- Include the BSD-3-Clause licence and disclaimer when redistributing the library.

### Licence decision

MIT and BSD-3-Clause are permissive open-source licences and can be used together.

A GPL-licensed dependency would require additional care. In particular, distributing a combined or derivative work may require compliance with GPL obligations, including making the corresponding source code available under the applicable GPL terms. We will avoid introducing GPL dependencies without reviewing their exact licence and distribution implications.

**Conclusion:** GoogleTest and rapidcsv are compatible with our MIT repository, provided their licence notices and conditions are preserved.

## 3. Maintenance evidence

- GoogleTest: Official GitHub releases include v1.17.0, released on 30 April 2025. The project also has a newer v1.18.0 release. We retain v1.17.0 to follow the provided lab starter.
- rapidcsv: The project provides release tags and active repository development. Version v9.07 is the selected pinned version, with a September 2026 release record.

References:
- https://github.com/google/googletest/releases
- https://github.com/d99kris/rapidcsv/releases

## 4. Verification

**Compiler:** [Enter your compiler and version]  
**CMake:** [Enter your CMake version]  
**Build configuration:** [Debug or Release]

Command executed:

```powershell
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

### CTest summary

Paste the actual output from your terminal here.

Expected result:

```text
Test project
    Start 1: CsvSmokeTest.ReadsEventTitlesAndCapacities
1/1 Test #1: CsvSmokeTest.ReadsEventTitlesAndCapacities ... Passed

100% tests passed, 0 tests failed out of 1
```

**Verification status:** Pending actual clean build and test execution.

## 5. Conclusion

The project will reuse GoogleTest for unit testing and rapidcsv for CSV reading. Other features will be implemented using C++20 standard library facilities or custom Club Hub logic. Reminders and additional logging are deferred to avoid unnecessary dependencies during the initial development stage.