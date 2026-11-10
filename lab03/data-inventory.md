# Data inventory · ITC Club Hub
Version 0.1 · 2026-11-06 · Authors: <names>

| Field | Subject | Purpose | Legal basis / consent | Retention | Who can see it | Stored in | Decision |
|---|---|---|---|---|---|---|---|
| studentId | student | identify; block double registration | necessary for the service | graduation | all roles | data/students.csv | Keep |
| name | student | personalization; readable rosters | necessary for the service | account deletion | all roles | data/students.csv | Keep |
| email | student | notifications; event updates | necessary for the service | account deletion | all roles | data/students.csv | Keep |
| phone | student | urgent contacts during events | consent (opt-in) | 30 days post-term | organiser, admin | data/students.csv | Mask | Mask for organisers: high risk if leaked; masking protects privacy while remaining usable for emergencies |
| clubMemberships | student | enforce access control lists | necessary for the service | active enrollment | all roles | data/memberships.csv | Keep |
| attendance | student | verify compliance for funding | legitimate interest: validate active status for grants | 1 year raw, then aggregate | organiser, leader, admin | data/registrations.csv | Keep |
| dateOfBirth | student | verify event venue age limits | consent: explicit checkbox | immediate clear post-check | admin | data/interim.csv | Drop |
| telegramHandle | student | voluntary event group chats | consent (opt-in) | until user deletes | student, organiser, leader | data/socials.csv | Keep optional |
| photo | student | display profile picture avatar | consent (opt-in) | until user deletes | all roles | data/avatars/ | Drop |

## Copies of personal data

| Copy | Rule |
|---|---|
| log files | only redacted() output, never name, email or phone |
| CSV exports | completely omit the phone field and pseudonymize the studentId columns |
| test fixtures | rely entirely on mock engines like Faker; never import production database snapshots |
| backups | encrypt at rest via AES-256 and enforce a rolling 30-day auto-purge timeline |
| screenshots in docs | obscure all real names, emails, and identifiers with solid black redaction blocks |

## Lifecycle of the phone field
flowchart LR
    C["Collect: Obtain optional opt-in via a explicit form checkbox"] --> S["Store: Encrypt at rest and mask middle digits in active columns"]
    S --> U["Use: Restrict lookup access to emergency response scenarios only"]
    U --> SH["Share: Strict block on third-party transmission or export boundaries"]
    SH --> D["Delete: Absolute hard-purge from active disks and overwrite backups within 30 days"]

## Client feedback
- The Product Owner walked the teaching assistant through the Drop decisions (dateOfBirth and photo). The client raised no objections regarding these minimization strategies.