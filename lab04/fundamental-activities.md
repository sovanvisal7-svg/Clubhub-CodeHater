# Fundamental activities · Team [Codehater] · v1.0 ([2026-11-13])

| Activity | What happens in Club Hub | Who leads (role ,name) | Weeks | Artifact | Done when |
| :--- | :--- | :--- | :--- | :--- | :--- |
| Specification | Write user stories for member registration and event creation; define capacity and waitlist rules. | Product Owner, [Lay pichrattanak] | 5–6 | lab05/srs.md | The TA approves the SRS document via email or pull request. |
| Design and implementation | Design database schema for clubs and events; implement RegistrationService::register() and cancel(). | Tech Lead / Developer, [Kheng daniza] | 7–11 | src/ | All core features compile cleanly and pass code review on main. |
| Validation | Write unit tests for registration rules; run integration tests for event capacity limits. | QA Lead / Tester, [Ouk sovanvisal] | 8–12 | tests/ | All GoogleTest suites pass green in CI with zero critical bugs. |
| Evolution | Update waitlist priority logic based on sprint feedback; refactor notification services for v2.0. | Product Owner, [Lay pichrattanak] | 11–14 | CHANGELOG.md | Updated features are deployed and documented in the release notes. |

## Sub-activities and ISO/IEC/IEEE 12207 processes
- **Specification:** Requirements elicitation, requirements analysis, requirements specification, requirements validation · **12207:** Stakeholder needs and requirements definition, System/software requirements definition.
- **Design and implementation:** Architectural design, interface design, component coding, unit debugging · **12207:** Architecture definition, Design definition, Implementation.
- **Validation:** Component testing, system integration testing, user acceptance testing · **12207:** Verification, Validation.
- **Evolution:** Change request evaluation, system modification, regression testing, release maintenance · **12207:** Maintenance, Configuration management
## Overlaps and loops
1. **Sprint 1 review (week 10) produces new stories → specification again in week 11:** Feedback from demonstrating the basic club registration flow uncovers missing edge cases for waitlists, requiring the Product Owner to update the requirements before Sprint 2 coding begins.
2. **Validation failures (week 9) trigger rework → design and implementation in week 9–10:** Failing GoogleTest cases on concurrent event sign-ups reveal a race condition, sending the developers back to adjust the RegistrationService locking logic.