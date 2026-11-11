# Accessibility checklist · ITC Club Hub (planned web and mobile UI)
Target: WCAG 2.2 level AA · Version 0.1 · 2026-11-11

| SC | Name | Level | Screen | How we meet it | How we test it |
|----|------|-------|--------|----------------|----------------|
| 1.4.1 | Use of Color | A | event list | status badge has text "Full" | view in greyscale |
| 2.5.8 | Target Size (Minimum) | AA | registration form | TODO | TODO |
| 1.1.1 | Non-text Content | A | club page | club logos and event posters have meaningful alt text; decorative images use empty alt | run axe DevTools; check with screen reader (NVDA / TalkBack) |
| 1.3.1 | Info and Relationships | A | registration form | every field has a programmatically linked `<label>`; related fields grouped with `<fieldset>` and `<legend>` | inspect DOM; read form in screen reader and check labels are announced |
| 1.4.1 | Use of Color | A | event list | status badge has text "Full" | view in greyscale |
| 1.4.3 | Contrast (Minimum) | AA | all screens | text and background contrast at least 4.5:1 (3:1 for large text) | check colour pairs with a contrast checker; run Lighthouse |
| 1.4.10 | Reflow | AA | event list | single-column responsive layout; no horizontal scrolling at 320 CSS px | zoom browser to 400% and test at 320 px width |
| 2.1.1 | Keyboard | A | event detail | all actions (join, cancel, share) are real buttons or links reachable and usable with Tab, Enter and Space | unplug mouse and complete each task by keyboard only |
| 2.4.7 | Focus Visible | AA | all screens | clear 2 px focus outline on every interactive element | tab through every screen and confirm focus is always visible |
| 2.4.11 | Focus Not Obscured (Minimum) | AA | event detail | sticky header and bottom "Join" bar have scroll-padding so a focused element is never fully hidden | tab through the page with sticky bars shown; check focused item stays at least partly visible |
| 2.5.7 | Dragging Movements | AA | club admin panel | reordering the club's events by drag also has "Move up" / "Move down" buttons | perform the reorder using only single clicks or taps |
| 2.5.8 | Target Size (Minimum) | AA | registration form | all buttons, checkboxes and links are at least 24×24 CSS px (we aim for 44×44 px on mobile) | measure targets in browser DevTools; run Accessibility Insights |
| 3.1.1 | Language of Page | A | all screens | `lang="en"` set on the page; `lang="km"` on Khmer text | inspect `<html>` tag; validate with axe DevTools |
| 3.2.6 | Consistent Help | A | all screens | "Help / Contact club admin" link is in the same place (footer) on every screen | compare the footer on each screen for same position and order |
| 3.3.1 | Error Identification | A | registration form | invalid fields get red border, an error icon and a text message such as "Enter your ITC student email" | submit the form with empty and wrong values; check messages appear and are announced by the screen reader |
| 3.3.7 | Redundant Entry | A | registration form | name, student ID and email are pre-filled from the member profile; no re-typing across steps | register for two events in one session and check no field is asked twice |
| 3.3.8 | Accessible Authentication (Minimum) | AA | login | no puzzle or memory test; password fields allow paste and password managers; "Sign in with ITC email link" option | test paste and password-manager autofill; confirm login needs no transcription or puzzle |
| 4.1.2 | Name, Role, Value | A | event list | custom controls (filter chips, toggles) use native elements or correct ARIA role, name and state | inspect in browser accessibility tree; check states announced by screen reader |