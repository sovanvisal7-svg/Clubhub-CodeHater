# Ethics case analyses · ITC Club Hub
Version 1.0 · 2026-11-10 · Leads: A = Siem Khattyavatey, B = Lay Pichrattanak

## Scenario A: "Just a small report"

| Step | Analysis |
|------|----------|
| 1. Facts | The Robotics Club leader wants to see students attending other clubs' events for recruitment. We need to check administrator approval and student privacy policies. |
| 2. Stakeholders and harms | Students may lose privacy. Club leaders may misuse information. Administrators and developers may lose trust. |
| 3. Codes, law, policy | SE Code 3: Product quality and responsibility. ACM 1.6: Respect privacy. GDPR 5(1)(a): Lawfulness, fairness and transparency. GDPR 5(1)(b): Purpose limitation. |
| 4. Options | (a) Build the report immediately. (b) Reject the request. (c) Ask the administrator for approval. (d) Provide anonymous attendance statistics instead. |
| 5. Tests | (a) Fails harm, rights and publicity tests. (b) Protects privacy but may be too restrictive. (c) Passes if proper authorization is obtained. (d) Passes if students cannot be identified. |
| 6. Decision and action | Choose (c) and (d). Confirm permission first and offer anonymous attendance statistics instead of individual records. |
| 7. Reflection | Having access to data does not mean having permission to use it. Developers must protect student privacy. |

**Message sent:**

Hi Robotics Club Leader,

Thank you for your suggestion. However, sharing students' attendance records across clubs may affect their privacy. We need administrator approval before developing this feature. As an alternative, we suggest an anonymous attendance report that shows overall participation without identifying individual students.

Thank you for understanding.

**Preventive change:** Restrict cross-club attendance reports to authorized users.

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
"Hi Robotics Club Leader, during pre-demo testing we identified an issue where registration cancellations inside the 24-hour window are incorrectly counted as active attendance. While we understand the timeline is tight, hiding this error during the demo compromises our professional integrity and delivery trust. We have formally created issue #105 to track this. We plan to present this transparently on our 'Known Issues' slide during the Sprint 1 review and detail our definitive fix scheduled for Sprint 2." 

**Preventive change:** Add automated regression tests validating that cancellations within the 24-hour boundary explicitly fail to trigger an attendance increment, tracked under issue #105.
