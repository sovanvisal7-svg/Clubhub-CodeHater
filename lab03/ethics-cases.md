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

**GitHub issue:** #TODO (Label: `ethics`)

## Scenario B: "Don't mention it in the demo"
(same table)