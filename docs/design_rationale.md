# Design Rationale

This document explains the high-level choices in our collision avoidance prototype:

- **SensorManager**: abstracts raw sensor I/O for lidar, radar, and camera.
- **FusionEngine**: combines multiple data sources using Kalman filters and Bayesian fusion for robust object tracking.
- **DecisionModule**: uses a timed automaton (UPPAAL) to guarantee response within 50 ms and issues brake commands.
- **SafetyMonitor**: a watchdog service to enforce system liveness and reset on timeouts.
- **Formal Verification**: UPPAAL model and Coq proofs ensure key safety properties per ISO 26262 SIL-3.

For detailed FMEA, FTA, and formal proofs, see [Appendices] in the main report.
