(set-logic QF_S)

(declare-fun a () String)

(assert (ends (concat a "b") "bb" ))

(check-sat)

