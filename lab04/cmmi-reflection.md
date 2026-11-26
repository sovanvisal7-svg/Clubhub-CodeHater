# CMMI reflection · Team CodeHater


## Where we are today (level 1) and the evidence
We place ourselves at CMMI Level 1 (Initial), starting to move toward Level 2 (Managed). At Level 1 the work gets done, but it depends on individual effort and not on a defined, repeatable process. The evidence in our repository (Clubhub-CodeHater) shows this. On the positive side, our Lab 01 requirements files (problem statement, stakeholders, failure risks) are written down and versioned in Git, so part of Requirements Development exists. On the other side, changes are pushed straight to main without a pull request, no teammate is recorded as a reviewer, we have no written estimates, and tasks are tracked informally in chat. Nobody can show, from the repository alone, that a requirement was checked by a second person before it was used.

## The practice area we adopt now and why
We adopt **Peer Reviews**. The V-model says every level on the left needs a check on the right, and a review is the cheapest check available: it needs no code and no tooling. Our biggest risk is a wrong or ambiguous requirement, such as the open question whether exactly 24 hours before the event still allows cancellation. A reviewer with a checklist would catch that before it reaches a test or a sprint review. It is also small enough to start on day one of Sprint 1.

## Three actions (who, from when)
1. **Protect main.** Turn on branch protection so every change goes through a pull request with at least one approval. Owner: Ouk Sovanvisal, before Sprint 1 starts.
2. **Add a review checklist.** Create `.github/pull_request_template.md` with checks: requirement has an id, boundary values are stated, a test exists for it, no unrelated changes. Lay Pichrattanak: the quality lead, before Sprint 1 starts.
3. **Review within 24 hours, rotate reviewers.** A teammate other than the author reviews each pull request within 24 hours, and the reviewer rotates every sprint so knowledge spreads. Owner: the whole team, from the first day of Sprint 1.

## How we measure it (metric, target) and when we check
**Metric:** the percentage of merged pull requests that have at least one approving review from a teammate other than the author.
**Target:** 100% of merged pull requests in Sprint 1 (today the figure is close to 0%, because we push directly to main).
**When we check:** at the Sprint 1 retrospective. We count the merged pull requests in the GitHub repository and the reviews on each. If we are below 100%, we discuss the cause in the retrospective and decide whether to change the process or the target for Sprint 2.