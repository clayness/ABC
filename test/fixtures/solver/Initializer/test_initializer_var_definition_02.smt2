(set-logic QF_S)

(declare-fun abc () Int)
(declare-fun def () Int)

(assert (= abc def))

(check-sat abc)

