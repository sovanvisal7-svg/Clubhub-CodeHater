# V-model trace · REQ-12 Cancel a registration

**REQ-12:** A student can cancel a registration until 24 hours before the start of the event.
Business rule: cancellation is allowed when `start - now >= 24 h` (exactly 24 h is allowed, one second less is rejected).

Reference event: "Robotics Workshop", start 2026-11-07 14:00 (UTC), student S001 registered.

## Trace table

| Level | Left side (defines) | Right side (tests) |
|---|---|---|
| Requirement | **REQ-12** A student can cancel a registration until 24 h before the event start | **AT-12** Gherkin acceptance test (below), run by the client at the sprint review |
| System specification | **SYS-12** The system shall accept a cancellation when `start - now >= 24 h`, set the registration status to "Cancelled" and free one seat. Otherwise it shall reject it with the message "Cancellation is closed 24 hours before the event starts" and leave the registration and seats unchanged. | **ST-12a** now = 2026-11-06 14:00:00 -> status "Cancelled", seats +1<br>**ST-12b** now = 2026-11-06 14:00:01 -> rejected with the message, status stays "Registered", seats unchanged |
| Architecture design | **ARCH-12** `RegistrationService::cancel(studentId, eventId, now)` calls `CancellationPolicy::canCancel`, then `RegistrationRepository` updates the status and `Event` releases the seat | **IT-12a** service + policy + repository with now = start - 24 h -> repository holds "Cancelled", event seats +1<br>**IT-12b** now = start - 24 h + 1 s -> repository unchanged, error returned |
| Module design | **MOD-12** `canCancel(now, start)` in `include/clubhub/CancellationPolicy.hpp` | **UT-12a** now = start - 24 h -> true<br>**UT-12b** now = start - 24 h + 1 s -> false (boundary)<br>**UT-12c** now = start - 7 days -> true<br>**UT-12d** now = start + 1 s -> false |

## Acceptance test AT-12 (Gherkin)

```gherkin
Feature: Cancel a registration (REQ-12, acceptance test AT-12)

  Background:
    Given the event "Robotics Workshop" starts on 2026-11-07 at 14:00
    And student "S001" is registered for "Robotics Workshop"

  Scenario: Cancellation exactly 24 hours before the start is allowed
    Given the current time is 2026-11-06 14:00
    When student "S001" cancels the registration
    Then the registration status is "Cancelled"
    And one seat becomes free

  Scenario: Cancellation less than 24 hours before the start is rejected
    Given the current time is 2026-11-06 14:00:01
    When student "S001" cancels the registration
    Then the cancellation is rejected with the message "Cancellation is closed 24 hours before the event starts"
    And the registration status is "Registered"
    And no seat becomes free
```

Assumption to confirm with the client: exactly 24 h is still allowed.