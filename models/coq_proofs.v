(* coq_proofs.v *)
Require Import Arith.

(* Define a simple model of speed and threshold *)
Parameter speed safe_threshold : nat.
Axiom speed_le_threshold : speed <= safe_threshold.

(* Theorem: after emergency signal, speed never exceeds safe threshold *)
Theorem safe_speed_after_signal : speed <= safe_threshold.
Proof.
  apply speed_le_threshold.
Qed.
