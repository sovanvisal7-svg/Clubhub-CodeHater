# Ethics case analyses · ITC Club Hub
Version 1.0 · 2026-11-10 · Leads: A = Siem Khattyavatey, B = Lay Pichrattanak

## Scenario A: "Just a small report"


| Step | Analysis |
|---|---|
| **1 Facts** | **Known:** The Robotics Club leader wants to see which students attend other clubs' events for recruitment purposes. **To find out:** Does the administrator approve this request, and what do existing student privacy policies allow? |
| **2 Stakeholders and harms** | **Students:** Lose personal privacy and face unwanted recruitment or profiling. **Club Leaders:** Risk misusing restricted data beyond its intended scope. **Administrators & Developers:** Face damaged institutional trust and policy violations. |
| **3 Codes, law, policy** | **ACM Code:** 1.6 (Respect privacy). **SE Code:** 3.00 (Maintain product quality and professional responsibility). **GDPR Principle:** Article 5(1)(a) Lawfulness, fairness, and transparency; Article 5(1)(b) Purpose limitation. |
| **4 Options** | **(a)** Build and deliver the detailed student attendance report immediately. **(b)** Outright reject the Robotics Club leader's request. **(c)** Escalate the request to the administrator for formal approval. **(d)** Provide aggregated, anonymous attendance statistics instead of individual student records. |
| **5 Tests** | **(a)** Fails the harm, rights, and publicity tests by exposing private student data without consent. **(b)** Protects student privacy completely, though it may be overly restrictive if safe alternatives exist. **(c)** Passes ethical and policy tests only if formal administrative authorization and privacy compliance are confirmed. **(d)** Passes all ethical tests as long as individual students cannot be re-identified. |
| **6 Decision and action** | **Choose Options (c) and (d):** Confirm policy boundaries with the administrator first, then offer aggregated, anonymous attendance statistics instead of identifiable student records. |
| **7 Reflection** | **Core Lesson:** Having technical access to user data does not grant ethical or legal permission to repurpose it; developers must actively safeguard student privacy by design. |


**Message sent:**

Hi Robotics Club Leader,

Thank you for your suggestion. However, sharing students' attendance records across clubs may affect their privacy. We need administrator approval before developing this feature. As an alternative, we suggest an anonymous attendance report that shows overall participation without identifying individual students.

Thank you for understanding.

**Preventive change:** Restrict cross-club attendance reports to authorized users

**GitHub issue:** (Label: `ethics`)

## Scenario B: "Don't mention it in the demo"

| Step | Analysis |
|---|---|
| **1 Facts** | **Known:** Cancellations within 24 hours are being processed erroneously as valid attendances in monthly reports. The Sprint 1 review is in two days. The Scrum Master explicitly requested hiding this flaw from the client during the demo to patch it later. **To find out:** Are decisions driven by this report legally binding or financially active? |
| **2 Stakeholders and harms** | **Client/Product Owner:** Deceived regarding product readiness, receives incorrect business metrics. **The Team:** Eroded trust with stakeholders; professional integrity compromised. **Scrum Master:** Avoids short-term embarrassment but faces massive liability later. |
| **3 Codes, law, policy** | **ACM Code:** 1.3 (Be Honest and Trustworthy). **SE Code:** 1.06 (Be proud of software product; do not misrepresent data or capabilities). **GDPR Principle:** Article 5(1)(d) Accuracy (Reporting inaccurate metrics derived from incorrectly handled personal configurations). |
| **4 Options** | **(a)** Follow the Scrum Master's instruction and conceal the bug during the live demo. **(b)** Refuse to participate in the demo unless the bug is fixed immediately. **(c)** Include the issue transparently in the "Known Issues" slide/log during the demo, outlining the clear remediation timeline planned for Sprint 2. |
| **5 Tests** | **Harm:** (a) Severe long-term reputational harm if exposed; (b) Delays demo and strains team relations; (c) Minor short-term embarrassment, zero trust loss. <br>**Rights:** (a) Violates client's right to honest assessment; (b) Protects team; (c) Respects client choices. <br>**Fairness:** (a) Highly unfair to client; (b) Disruptive; (c) Completely fair and accurate. <br>**Publicity:** (a) Looks like a fraudulent cover-up; (b) Rigid; (c) Celebrated for transparency. |
| **6 Decision and action** | **Decision:** Choose Option (c). Present the current state honestly. Transparency strengthens project partnerships and protects engineering integrity from sudden disclosure. <br>**Action:** Inform the Scrum Master and Product Owner immediately via an official message, log the item into the repository's open issues, and list it clearly in the status presentation. |
| **7 Reflection** | Suppressing software bugs during milestones compromises code quality and professional ethics. Engineering honesty must always override temporary administrative convenience or cosmetic sprint success metrics. |

**Message sent:** 
"Hi Robotics Club Leader, during pre-demo testing we identified an issue where registration cancellations inside the 24-hour window are incorrectly counted as active attendance. While we understand the timeline is tight, hiding this error during the demo compromises our professional integrity and delivery trust. We have formally created issue to track this. We plan to present this transparently on our 'Known Issues' slide during the Sprint 1 review and detail our definitive fix scheduled for Sprint 2." 

**Preventive change:** Add automated regression tests validating that cancellations within the 24-hour boundary explicitly fail to trigger an attendance increment, tracked under issue 105.
