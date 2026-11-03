# Lab-02 · Quality attribute scenarios for ITC Club Hub 
Version 1.0 · 2026-__-__ · Reviewed by (Scrum Master): Siem Khattyavtey
## QAS-01 · Availability · written by Lay Pichrattanak
Scenario: The ITC Club Hub system should remain available when students want to check any news or annountments.
| Part             | Content |
|------------------|---------|
| Source           | Students using the ITC Club Hub system. |
| Stimulus         | Students attempt to access the news and announcements section to check the latest updates.|
| Environment      | During normal operation, including periods when many students access the system simultaneously. |
| Artifact         | The ITC Club Hub application, announcement module, and database.|
| Response         | The system retrieves and displays the latest club news and announcements to students.|        
| Response measure | The system should maintain 99.5% uptime and display news and announcements within 3 seconds for 95% of requests. |
## QAS-02 · Performance of check-in at the door · written by Mengheng Saroeun

## QAS-03 · Usability · written by Kheng Daniza
Scenario: The ITC Club Hub system should provide an easy-to-use interface that allows students to find clubs, view upcoming events, and read announcements without confusion.
| Part             | Content |
|------------------|---------|
| Source           | Students using the ITC Club Hub system. |
| Stimulus         | A student tries to find information about a club or an upcoming event.    |
| Environment      | During normal operation, when students access the system using a computer or mobile device. |
| Artifact         | The user interface, navigation menu, club directory, and event calendar.    |
| Response         | The system provides clear navigation and displays relevant information so students can easily find what they need.| | Response measure | At least 90% of first-time users should be able to find a club or event within 1 minute without assistance |

## QAS-04 · Security  · written by Ouk Sovanvisal
Scenario: The ITC Club Hub system should protect students' personal information and prevent unauthorized users from accessing private data.
| Part             | Content |
|------------------|---------|
| Source           | An unauthorized user attempting to access the system.            |
| Stimulus         | The user attempts to access another student's personal information without permission.|
| Environment      | While the system is operating normally.|
| Artifact         | Authentication system, user accounts, and student database.          |
| Response         | The system denies unauthorized access and records the security attempt.  |        
| Response measure | 100% of unauthorized access attempts to protected student information must be denied.  |
## QAS-05 · Modifiability · written by Ouk Sovanvisal
Scenario: The ITC Club Hub system should allow developers to easily update club information and add new features without affecting existing functions.
| Part             | Content |
|------------------|---------|
| Source           |Development team or system administrator.         |
| Stimulus         |The development team needs to add a new feature or modify an existing function.         |
| Environment      |During system maintenance or a planned software update.         |
| Artifact         |Application source code, database, and system modules.         |
| Response         | The system allows developers to make changes without disrupting existing features.        |        
| Response measure |A minor feature update should be completed and tested within 4 hours without causing errors in existing functions.         |
## QAS-06 · Portability · written by Siem Khattyavtey
Scenario: The ITC Club Hub system should work properly across different devices and operating systems so students can access it conveniently.
| Part             | Content | 
|------------------|---------| 
| Source           |Students and club leaders.         | 
| Stimulus         | A user accesses ITC Club Hub using a different device or operating system.        |
| Environment      | When accessing the system through different browsers and devices, such as laptops, tablets, and smartphones.         |
| Artifact         |ITC Club Hub application and user interface.         |
| Response         | The system displays its features and information correctly across supported devices and browsers.        |         
| Response measure |All core functions should work correctly on the latest two major versions of Chrome, Firefox, Safari, and Edge, on supported desktop and mobile devices.         |
## Priorities 
| Scenario | Business importance | Technical risk | Protects | First? | 
|----------|---------------------|----------------|----------|--------| 
| QAS-01 Availability  | High   |Medium| Students	         |Yes     |
| QAS-02 Performance   | High   |Medium|Students and club leaders| No |
| QAS-03 Usability	   | High   | Low  | Students	         | No     |
| QAS-04 Security      | High   | High |Students and administrators	|Yes|
| QAS-05 Modifiability | Medium |Medium|  Development team   |	No    |
| QAS-06 Portability   | Medium |Medium|Students and club leaders| No |  
