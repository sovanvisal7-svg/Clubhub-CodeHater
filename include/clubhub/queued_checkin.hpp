// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Team CodeHater, ITC Club Hub contributors
// include/clubhub/queued_checkin.hpp
#pragma once
#include <chrono>
#include <optional>
#include <string>
#include <vector>

namespace clubhub {

// Pending  : recorded on the phone, never uploaded
// Sent     : uploaded at least once, no answer received yet (timeout, lost reply)
// Accepted : server applied it (or had already applied it)
// Rejected : server refused it; rejectReason says why
enum class SyncState { Pending, Sent, Accepted, Rejected };

// One check-in recorded on an organiser's phone while offline.
struct QueuedCheckIn {
    // UUID v4 generated ON THE DEVICE at scan time, never regenerated.
    // Two phones with no network cannot ask the server for an id, and a random
    // UUID will not collide. Because it is created once and sent unchanged on
    // every retry, the server can recognise a repeated upload: this is the
    // idempotency key.
    std::string localId;
    std::string deviceId;                 // which door/phone produced it
    std::string eventId;
    std::string studentId;

    // Device clock. NOT trusted for decisions: it is only a hint. The server
    // stores it as-is and computes its own corrected time from the receive time
    // and the batch's "sentAt" (see offline-checkin.md, rule 5).
    std::chrono::sys_seconds scannedAt;

    int attempts = 0;                     // number of upload attempts so far
    SyncState state = SyncState::Pending;
    std::optional<std::string> rejectReason;  // set only when state == Rejected
};

class CheckInQueue {
public:
    // false if this student is already queued for this event on this phone
    // (same eventId + studentId, state Pending, Sent or Accepted).
    // A previously Rejected item does not block a new scan.
    bool enqueue(QueuedCheckIn item);

    // oldest first; what the next sync attempt uploads
    std::vector<QueuedCheckIn> pending() const;

    void markAccepted(const std::string& localId);
    void markRejected(const std::string& localId, std::string reason);

private:
    std::vector<QueuedCheckIn> items_;    // insertion order = scan order
};

} // namespace clubhub