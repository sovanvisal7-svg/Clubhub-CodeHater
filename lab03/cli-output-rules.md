# CLI output rules · ITC Club Hub

| # | Rule | Bad | Good |
|---|------|-----|------|
| 1 | No colour-only meaning | `Hackathon` in red | `FULL  Hackathon` |
| 2 | Honour `NO_COLOR` and `--no-color` | `NO_COLOR=1` still prints colour codes | `NO_COLOR=1` or `--no-color` prints plain text |
| 3 | Errors say what failed, why, next step | `Error: failed` | `Error: can't import events.csv. Line 7 has 3 columns, expected 5. Fix line 7 and re-run.` |
| 4 | Non-zero exit code on error | `student not found` → exit code `0` | `student not found` → exit code `1` |
| 5 | Prompts state the expected format | `Enter date:` | `Enter date (YYYY-MM-DD HH:MM):` |
| 6 | Unambiguous dates | `10/14/26 5:30 PM` | `2026-10-14 17:30` |