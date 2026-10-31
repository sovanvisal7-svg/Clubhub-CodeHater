# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-__-__ · Status: Proposed | Accepted (date) · Deciders: __

## User groups
| Group          | Device | Where | Connectivity | How often | Must never fail |
|----------------|--------|-------|--------------|-----------|-----------------|
| Students       | Smartphones (iOS/Android) | Home, Campus, at events, in lecture halls | Mobile Data / Campus Wi-Fi | A few times a week, more on event days | Event registration and RSVP browsing |
| Organisers     | Laptop, tablet and phone |Event Entrance Gates | weak 3G, Flaky/ congested Wi-Fi| Daily at events or weekly | Offline ticket scanning at the door |
| Administrators | Laptops / Desktops PCs (Windows) | Student union office | Stable Wired LAN | Monthly | Global club approval and data backup |

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

## Consequences
+ Rapid single-codebase development using standard web frameworks (React/Vue), keeping semester costs minimal.
+ Uses Service Workers and Background Sync API to handle seamless offline ticket scanning at event gates.
- Push notification support is restricted on older iOS devices compared to native builds.
- Demands additional structural development to handle local data synchronization conflicts once network connectivity resumes.

## Rejected options
*   Option A (Native Apps): Rejected because handling individual Apple App Store and Google Play deployments is too time-consuming for our strict single-semester schedule.
*   Option B (Responsive Web App): Rejected because it provides zero operational capabilities when network connectivity drops at gate check-ins.
*   Option D (Desktop Application): Rejected because it completely lacks the mobility required for students and event gates.

## How the front ends reach the C++ core
The PWA frontend will communicate over the local network via an asynchronous **HTTP REST API**. A lightweight web server (such as Crow or Civetweb) will be hosted alongside our backend. This server accepts the incoming HTTP JSON payloads sent by the frontend, unpacks the parameters, passes them directly into our compiled compiled C++ business logic core execution methods, and returns structured JSON responses straight back to the client interface.