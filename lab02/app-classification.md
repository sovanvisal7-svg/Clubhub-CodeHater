# Lab-02 · Classification of five applications
Version 1.0 · 2026-2027 · Team: Code_Hater

| # | Application | Kind | Type(s) | Where the code runs, how it is delivered | Architecture | Top 3 qualities (why) | Filled by |
|---|-------------|------|---------|------------------------------------------|--------------|-----------------------|-----------|
| 1 | Mobile banking app: ABA Mobile | Application software | Mobile native, enterprise, data-intensive | Runs on phone and bank servers. Delivered via app store. | Three-tier. Evidence: Processes real-time financial balances and secure transactions. | Security (unauthorized access costs funds), Availability (outages block payments), Performance (lag causes duplicate transfers). | Ouk Sovanvisal|
| 2 | Telegram | Application software | Desktop, mobile native, cross-platform, cloud SaaS | Runs on phone, PC, and cloud backend. Delivered via app store or URL | Client-server. Evidence: Instantly matches chats across phone and laptop interfaces. | Availability (downtime cuts communication), Security (data leaks breach privacy), Usability (bad UI pushes users away). | Saroeun Mengheng |
| 3 | ABS controller in a car | System software | Embedded real-time | Runs on electronic control unit (ECU). Installed at factory. | Embedded control loop. Evidence: Monitors wheel speed in millisecond cycles. | Safety (glitches cause fatal crashes), Performance (delay skids car), Availability (system boot failure drops safe braking). | Siem Khattyavatey |
| 4 | Moodle at ITC | Application software | Web MPA, enterprise | Runs on browser and ITC servers. Delivered via web URL. | Three-tier. Evidence: Links local web browsers to a remote PHP database server. | Availability (failures during exams break submissions), Usability (confusing layouts mess up uploads), Security (flaws reveal grades). | Kheng Daniza |
| 5 | Game: Mobile Legends | Application software | Mobile native, cross-platform, game | Runs on phone hardware and match servers. Delivered via app store. | Client-server. Evidence: Handles 3D rendering locally but syncs player positions over network. | Performance (network spikes drop match wins), Availability (downtime stops matching), Security (cheating ruins fair competition). |Lay pichrattanak |


Biggest difference we found: The ABS controller operates on strict real-time embedded safety loops where a millisecond failure risks human lives, whereas Moodle at ITC focuses on standard enterprise availability where a system crash causes academic inconvenience rather than physical harm.
