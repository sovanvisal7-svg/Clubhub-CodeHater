# PDR-001: Software Development Process Selection

* Status: Proposed
* Date: 2026-11-22
* Deciders: Lay Pichrattanak, Siem Khattyavatey, Ouk Sovanvisal, Kheng Daniza, Saroeun Mengheng

## 1. Context

The selection of our team's development methodology is driven by the following project constraints and team realities:

1. Team Size and Capacity: The team consists of [X] members, each committing approximately [Y] hours per week to the project (Source: *Team Charter*).
2. Client Availability: The client is available for scheduled check-ins and feedback [e.g., once per week / bi-weekly / at fixed checkpoints] rather than daily on-site collaboration (Source: *Project Brief*).
3. Fixed Milestones: The project has hard, non-negotiable academic deadlines at Checkpoint 1 in Week 8 and final submission in Week 14 (Source: *Project Brief*).
4. Requirements Clarity: Core functional goals are outlined, though [e.g., edge cases, UI/UX details, and performance thresholds] remain partially ambiguous and subject to refinement (Source: *Problem Statement*).
5. Technical Experience: The team has [e.g., varying / introductory / moderate] experience with C++, CMake build configurations, and structured Agile sprints, introducing a learning curve early in the semester (Source: *Team Charter / Skills Matrix*).

## 2. Options Considered

| Option | Process Model | Weighted Score (Task 2) | Key Advantage (Pro) | Key Drawback (Con) |
| :--- | :--- | :--- | :--- | :--- |
| Option A | [e.g., Scrum] | [X.X / 5.0] | Enforces regular delivery increments, clear roles, and continuous feedback loops. | Standard 2–4 week sprints and heavy ceremony overhead do not fit a short 14-week academic schedule with part-time hours. |
| Option B | [e.g., Waterfall / V-Model] | [X.X / 5.0] | Aligns cleanly with fixed milestones (Weeks 8 & 14) and front-loads architectural design. | High risk of late integration failures if C++ and CMake issues surface near Week 14. |
| Option C | [e.g., Kanban] | [X.X / 5.0] | Maximizes flexibility and minimizes meeting overhead for part-time contributors. | Lacks time-boxed boundaries and forced checkpoints needed to hit hard academic deadlines. |
| Option D | No Defined Process (Ad-hoc) | N/A (Baseline) | Zero upfront planning or process overhead; members can start coding immediately. | Leads to uncoordinated work, CMake merge conflicts, missed milestones, and uneven workload distribution. |

## 3. Decision

We will adopt a Tailored Hybrid Iterative Process (Water-Scrum-Fall) combining structured up-front requirements and modeling (Weeks 5–7), weekly time-boxed Scrum sprints for core implementation (Weeks 8–12), and a dedicated hardening and release phase (Weeks 13–14).

> Rationale for deviating from Task 2 winner: While [Task 2 Winner] scored highest in isolation, a pure implementation did not account for our fixed up-front modeling deadline in Week 7 or the dedicated stabilization buffer needed in Week 13 to resolve C++ memory and cross-platform CMake build issues.

### Process Tailoring

| Element | Reference Practice (Standard Scrum) | Our Tailoring |
| :--- | :--- | :--- |
| Up-front work | Minimal up-front design; architecture emerges iteratively across sprints. | Dedicated Requirements phase (Weeks 5–6) and System Modeling phase (Week 7) to establish C++ class structure and CMake setup before Sprint 1. |
| Iteration length | 2 to 4 weeks per sprint. | 1-week sprints (Weeks 8–12) to match our compressed 14-week timeline and part-time weekly university schedule. |
| Meetings | Daily 15-minute stand-ups plus separate Planning, Review, and Retrospectives. | Twice-weekly async stand-ups (Discord/Slack) and one combined 60-minute weekly ceremony covering Sprint Review, Retrospective, and next Sprint Planning. |
| Roles | Dedicated full-time Product Owner, Scrum Master, and Developers. | One Product Owner (manages backlog/client), one Scrum Master / Build Lead (facilitates process & CMake CI), and all members act as Developers/Testers. |
| Documents | Lightweight artifacts; working software prioritized over formal documentation. | Maintain lightweight living docs alongside required academic deliverables (PDRs, UML models, and test reports) for Week 8 and Week 14 milestones. |
| Definition of Done (DoD) | Code complete, unit tested, reviewed, and potentially shippable. | Code compiles cleanly via CMake with zero warnings, passes automated unit tests, passes peer PR review, and updates relevant docs. |
| Hardening | No separate hardening sprint; every sprint produces release-ready code. | Dedicated Hardening phase in Week 13 strictly for integration testing, C++ memory-leak checks, bug fixing, and packaging before Week 14 submission. |

## 4. Consequences

### Positive Consequences
1. Predictable Milestone Alignment: Front-loading requirements and modeling ensures we meet Checkpoint 1 (Week 8) with a validated architecture.
2. Early Technical Risk Reduction: Weekly sprints force regular C++ compilation and CMake integration, preventing last-minute "integration hell."
3. Sustainable Part-Time Cadence: Combining ceremonies and using asynchronous updates protects limited weekly student hours for actual coding and testing.

### Negative Consequences & Mitigations
1. Risk: Ceremony Compression — Combining Review, Retrospective, and Planning into one 60-minute weekly meeting could cause superficial retrospectives.
   * *Mitigation:* Time-box each segment strictly (15 min Review, 15 min Retro, 30 min Planning) and collect retro notes asynchronously beforehand.
2. Risk: Feature Creep During Sprints — Weekly iterations with ambiguous requirements may tempt the team to add unapproved features.
   * *Mitigation:* Enforce a strict scope freeze on the Sprint Backlog once planned; new client feedback goes to the Product Backlog for PO prioritization.
3. Risk: Technical Debt Accumulation Before Week 13 — Rushing to finish weekly sprint goals may lead to skipped edge-case tests or messy CMake scripts.
   * *Mitigation:* Strictly enforce the Definition of Done on every Pull Request and reserve Week 13 exclusively for bug fixes and stabilization (no new features).

## 5. Process Diagram

flowchart TD
    Backlog[("Product Backlog<br/><i>(Product Owner)</i>")]
    Req["Requirements Phase<br/>Weeks 5–6<br/><i>(Product Owner & Team)</i>"]
    Model["System Modelling<br/>Week 7<br/><i>(Architect / Dev Team)</i>"]
    CP1{"Checkpoint 1<br/>Week 8<br/><i>(Product Owner & Client)</i>"}

    subgraph SprintLoop ["Sprint Loop (Weeks 8–12)"]
        Plan["Sprint Planning<br/><i>(Scrum Master & Team)</i>"]
        DevTest["Development & Testing<br/><i>(Dev Team)</i>"]
        Review["Sprint Review<br/><i>(Product Owner & Client)</i>"]
        Retro["Sprint Retrospective<br/><i>(Scrum Master & Team)</i>"]
        MoreSprints{"More Sprints?<br/>(Before Week 13)<br/><i>(Scrum Master)</i>"}

        Plan --> DevTest
        DevTest --> Review
        Review --> Retro
        Retro --> MoreSprints
        MoreSprints -- "Yes (Next Sprint)" --> Plan
    end

    Harden["Hardening & Stabilization<br/>Week 13<br/><i>(QA / Dev Team)</i>"]
    Submit(["Final Submission<br/>Week 14<br/><i>(Product Owner)</i>"])

    Backlog --> Req
    Req --> Model
    Model --> CP1
    CP1 --> Plan
    Review -. "Client Feedback &<br/>Backlog Refinement" .-> Backlog
    MoreSprints -- "No (Week 13 Reached)" --> Harden
    Harden --> Submit
## 6. Approvals

-** [Lay pichrattanak] (Product Owner):** — Approved on [2026-11-25]
- **Siem Khattyavatey (Scrum Master):** Approved (2026-11-25)
* [ ] [Member 3 Name] (Developer) — Approved on [YYYY-MM-DD]
* [ ] [Member 4 Name] (Developer) — Approved on [YYYY-MM-DD]
- **Saroeun Mengheng (Developer):** Approved (2026-11-25)