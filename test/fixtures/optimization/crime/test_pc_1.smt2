(declare-fun l () String)

(assert (= (indexOf (concat (concat "" (charAt (concat (concat "" (charAt (concat "CCCCCBBBCCCCC" l) 0)) (charAt (concat "CCCCCBBBCCCCC" l) 1)) 0)) (charAt (subString (concat (concat "" (charAt (concat "CCCCCBBBCCCCC" l) 0)) (charAt (concat "CCCCCBBBCCCCC" l) 1)) 1 (len (concat (concat "" (charAt (concat "CCCCCBBBCCCCC" l) 0)) (charAt (concat "CCCCCBBBCCCCC" l) 1)))) 0)) (concat (concat (concat (concat (concat (concat (concat (concat (concat (concat (concat (concat (subString (subString (concat (concat "" (charAt (concat "CCCCCBBBCCCCC" l) 0)) (charAt (concat "CCCCCBBBCCCCC" l) 1)) 1 (len (concat (concat "" (charAt (concat "CCCCCBBBCCCCC" l) 0)) (charAt (concat "CCCCCBBBCCCCC" l) 1)))) 1 (len (subString (concat (concat "" (charAt (concat "CCCCCBBBCCCCC" l) 0)) (charAt (concat "CCCCCBBBCCCCC" l) 1)) 1 (len (concat (concat "" (charAt (concat "CCCCCBBBCCCCC" l) 0)) (charAt (concat "CCCCCBBBCCCCC" l) 1)))))) (charAt (concat "CCCCCBBBCCCCC" l) 2)) (charAt (concat "CCCCCBBBCCCCC" l) 3)) (charAt (concat "CCCCCBBBCCCCC" l) 4)) (charAt (concat "CCCCCBBBCCCCC" l) 5)) (charAt (concat "CCCCCBBBCCCCC" l) 6)) (charAt (concat "CCCCCBBBCCCCC" l) 7)) (charAt (concat "CCCCCBBBCCCCC" l) 8)) (charAt (concat "CCCCCBBBCCCCC" l) 9)) (charAt (concat "CCCCCBBBCCCCC" l) 10)) (charAt (concat "CCCCCBBBCCCCC" l) 11)) (charAt (concat "CCCCCBBBCCCCC" l) 12)) (charAt (concat "CCCCCBBBCCCCC" l) 13))) (- 1)))
(assert (< 13 (len (concat "CCCCCBBBCCCCC" l))))

(check-sat)