(set-logic QF_S)

(declare-fun a () String)
(declare-fun b () String)

(assert (= (concat "a" a) (concat "a" b)))

(check-sat)
