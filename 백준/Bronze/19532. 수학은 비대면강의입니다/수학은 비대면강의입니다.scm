(define (det a b c d) (- (* a d) (* b c)))
(define (cramer a b c d deno) (/ (det a b c d) deno))

(define a (read))
(define b (read))
(define c (read))
(define d (read))
(define e (read))
(define f (read))
(define detSaved (det a b d e))

(display (cramer c b f e detSaved))
(display " ")
(display (cramer a c d f detSaved))
