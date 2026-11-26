# ITC Club Hub · Iteration Plan (Weeks 5–14)

**Week 5 Monday:** 2026-11-30  
**Sprint duration:** 2 weeks  
**Team capacity:** 48 hours per sprint

## 1. Gantt chart

```mermaid
gantt
    title ITC Club Hub - Iteration Plan Weeks 5 to 14
    dateFormat YYYY-MM-DD
    axisFormat %d %b
    tickInterval 1week
    weekday monday
    excludes weekends

    section Requirements
    Elicitation interview with client :req1, 2026-11-30, 5d
    SRS and product backlog           :req2, 2026-12-07, 5d

    section Models
    UML diagrams and architecture     :mod1, 2026-12-14, 5d

    section Checkpoint
    Midterm exam week                 :crit, exam, 2026-12-21, 5d
    Checkpoint 1                      :milestone, cp1, 2026-12-25, 0d

    section Sprint 1
    Sprint 1 planning                 :milestone, s1p, 2026-12-28, 0d
    Sprint 1 development and testing  :s1dev, 2026-12-28, 10d
    Sprint 1 review and retrospective :milestone, s1r, 2027-01-08, 0d

    section Sprint 2
    Sprint 2 planning                 :milestone, s2p, 2027-01-11, 0d
    Sprint 2 development and testing  :s2dev, 2027-01-11, 10d
    Sprint 2 review and retrospective :milestone, s2r, 2027-01-22, 0d

    section Hardening
    Feature freeze and bug fixing     :crit, hard, 2027-01-25, 5d

    section Submission
    Submission and demo               :milestone, sub, 2027-02-05, 0d

    section Labs
    Lab-05                            :lab5, 2026-11-30, 10d
    Lab-06                            :lab6, 2026-12-14, 5d
    Lab-07                            :lab7, 2026-12-21, 5d
    Lab-08                            :lab8, 2026-12-28, 5d
    Lab-09                            :lab9, 2027-01-04, 5d
    Lab-10                            :lab10, 2027-01-11, 10d
    Lab-11                            :lab11, 2027-01-25, 5d
```
## 2. Iteration goals

| Iteration | Weeks | Goal | Candidate features | Capacity | Exit criterion |
|---|---|---|---|---|---|
| Requirements | 5–6 | Understand and document the project requirements. | Requirements elicitation, SRS, product backlog | N/A | SRS and prioritized backlog completed |
| Models | 7 | Prepare the system design before implementation. | UML diagrams, class diagrams, architecture | N/A | Models reviewed by the team |
| Checkpoint | 8 | Demonstrate initial planning and design progress. | Requirements, SRS, UML diagrams | N/A | Checkpoint 1 completed |
| Sprint 1 | 9–10 | A student can browse upcoming events and register through the CLI. | Browse events, register for events, capacity validation, prevent duplicate registrations | 5 × 6 × 2 × 0.8 = **48 h** | Features demonstrated, tests pass and code reviewed |
| Sprint 2 | 11–12 | A student can manage registrations and the system can manage event participation. | Cancel registration, basic waitlist management, event management | 5 × 6 × 2 × 0.8 = **48 h** | Features integrated, tested and demonstrated |
| Hardening | 13 | Stabilize the application and prepare it for submission. | Bug fixes, integration testing, validation and documentation | N/A | No critical bugs and all required tests pass |
| Submission | 14 | Deliver and demonstrate the completed ITC Club Hub. | Final application, documentation and demo | N/A | Project submitted and demo completed |

## 3. Sprint capacity estimation

Formula:

**Capacity = Team members × Hours per week × Sprint duration × Focus factor**

Given:

- Team members = 5
- Hours per week = 6
- Sprint duration = 2 weeks
- Focus factor = 0.8

Calculation:

5 × 6 × 2 × 0.8 = **48 hours**

| Sprint | Duration | Estimated capacity |
|---|---|---:|
| Sprint 1 | 2 weeks | 48 hours |
| Sprint 2 | 2 weeks | 48 hours |
| Total | 4 weeks | 96 hours |

The team will prioritize small, achievable features that fit within the available capacity. Additional features will remain in the product backlog if they cannot be completed within the sprint.


## 4. Important scheduling decisions

1. Requirements are gathered during Weeks 5–6.
2. UML diagrams and architecture are prepared in Week 7.
3. Week 8 is reserved for the midterm exam and Checkpoint 1. No sprint development is scheduled.
4. Sprint 1 runs during Weeks 9–10.
5. Sprint 2 runs during Weeks 11–12.
6. Week 13 is reserved for hardening, bug fixing and final integration. No new features should be introduced.
7. Week 14 is reserved for final submission and demonstration.

## 5. Review and approval

- Scrum Master: Siem Khattyavatey
- Product Owner: Lay pichrattanak
<<<<<<< HEAD
- Team member 1: [member names]
- Team member 2: Kheng Daniza
=======
- Developer: Ouk Sovanvisal
- Team member 2: [member names]
>>>>>>> cd8eee7aa241f2729ec6bf3a12b5f818a865e462
- Team member 3: Saroeun Mengheng
- Review date: [Date]
- Status: Proposed