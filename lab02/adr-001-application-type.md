# ADR-001 · Application types for ITC Club Hub
Version 1.0 · 2026-__-__ · Status: Proposed | Accepted (date) · Deciders: __

## User groups
| Group          | Device | Where | Connectivity | How often | Must never fail |
|----------------|--------|-------|--------------|-----------|-----------------|
| Students       | Smartphones (iOS/Android) | Home, Campus, at events, in lecture halls | Mobile Data / Campus Wi-Fi | A few times a week, more on event days | Event registration and RSVP browsing |
| Organisers     | Laptop, tablet and phone |Event Entrance Gates | weak 3G, Flaky/ congested Wi-Fi| Daily at events or weekly | Offline ticket scanning at the door |
| Administrators | Laptops / Desktops PCs (Windows) | Student union office | Stable Wired LAN | Monthly | Global club approval and data backup |

## Options
A. Native Apps (Android + iOS)   B. Responsive Web App   C. Progressive Web App (PWA)   D. Desktop Application

## Weighted comparison (score 1-5 x weight)
| Criterion (weight) | why this weight | A | B | C | D |
|--------------------|-----------------|---|---|---|---|
| Cost for our team in one semester (3) | High weight because we only have 12 weeks to deliver a working system from scratch. | 2 | 5 | 4 | 3 |
| Reach (3)                             | Crucial because students will abandon the system if forced to download large store files. | 3 | 5 | 5 | 1 |
| Offline check-in at the door (2)      | Important because entrance gate Wi-Fi routinely fails during crowded student rushes. | 5 | 1 | 4 | 2 |
| Reminders (1)                         | Low weight because basic email notifications can serve as a backup fallback. | 5 | 2 | 4 | 2 |
| Dashboard management for administrators (2) | Admins need complete visibility over mass data entries and configurations. | 3 | 5 | 5 | 5 |
| Total                             | | 34 | 41 | 49 | 27 |

*Arithmetic Verification:*
*   A (Native): (2x3) + (3x3) + (5x2) + (5x1) + (3x2) = 6 + 9 + 10 + 5 + 6 = 34
*   B (Responsive Web): (5x3) + (5x3) + (1x2) + (2x1) + (5x2) = 15 + 15 + 2 + 2 + 10 = 44
*   C (PWA): (4x3) + (5x3) + (4x2) + (4x1) + (5x2) = 12 + 15 + 8 + 4 + 10 = 49
*   D (Desktop): (3x3) + (1x3) + (2x2) + (2x1) + (5x2) = 9 + 3 + 4 + 2 + 10 = 28

Deal-breaker check: Option B (Responsive Web App) fails completely because it cannot work without an active internet connection, meaning check-ins fail instantly if Wi-Fi drops. Option D (Desktop) fails the reach requirement because mobile-first students will not bring laptops to scan into physical events.

## Decision
We chose Option C: Progressive Web App (PWA). It scored the highest overall (49 points) because it offers full web reach via an instant URL link for students, while utilizing Service Workers to cache offline data so organisers can scan attendee barcodes even when the campus network completely goes down.

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