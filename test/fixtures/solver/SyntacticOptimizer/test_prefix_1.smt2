(set-logic QF_S)

(declare-fun a () String)

(assert (= (concat "a" a) "a"))

(check-sat)
