(set-logic ALL)
(declare-const symb_repl String)
(assert (let ((.def_0 (= ( str.replace symb_repl "a" "b" ) "cbne"))) .def_0))
(check-sat)
(get-model)
