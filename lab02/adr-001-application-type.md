# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-__-__ · Status: Proposed | Accepted (date) · Deciders: __

## User groups
| Group          | Device | Where | Connectivity | How often | Must never fail |
|----------------|--------|-------|--------------|-----------|-----------------|
| Students       |        |       |              |           |                 |
| Organisers     |        |       |              |           |                 |
| Administrators |        |       |              |           |                 |

## Options
A. __   B. __   C. __   D. __

## Weighted comparison (score 1-5 x weight)
| Criterion (weight) | why this weight | A | B | C | D |
|--------------------|-----------------|---|---|---|---|
| Cost for our team in one semester (_) | | | | | |
| Reach (_)                             | | | | | |
| Offline check-in at the door (_)      | | | | | |
| Reminders (_)                         | | | | | |
| __ for administrators (_)             | | | | | |
| **Total**                             | | = | = | = | = |

Deal-breaker check: __

## Decision
## Consequences
+ __
+ __
- __
- __
## Rejected options
## How the front ends reach the C++ core
The PWA frontend will communicate over the local network via an asynchronous **HTTP REST API**. A lightweight web server (such as Crow or Civetweb) will be hosted alongside our backend. This server accepts the incoming HTTP JSON payloads sent by the frontend, unpacks the parameters, passes them directly into our compiled compiled C++ business logic core execution methods, and returns structured JSON responses straight back to the client interface.