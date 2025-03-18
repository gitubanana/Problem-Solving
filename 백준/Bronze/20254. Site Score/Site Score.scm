(define (calculateScore a b c d)
    (+ (+ (* 56 a) (* 24 b)) (+ (* 14 c) (* 6 d)))
)

(define a (read))
(define b (read))
(define c (read))
(define d (read))
(display (calculateScore a b c d))
