(define LEFT '())
(define RIGHT '())
(define COMMA '())

(set! LEFT (cons #\( LEFT))
(set! RIGHT (cons #\) RIGHT))
(set! COMMA (cons #\space COMMA))
(set! COMMA (cons #\, COMMA))

(define (commaOrEmpty l)
    (
        if (null? (cdr l))
            '()
            COMMA
    )
)

(define (changeFormat call)
    (
        if (list? (car call))
            (append (append (append (list (car (car call))) LEFT ) (convertToC (cdr (car call)))) RIGHT) ; 인자가 함수일 경우
            (list (car call)) ; 인자가 변수일 경우
    )
)

(define (convertToC call)
    (
        if (null? call)
            '()
            (append
                (append (changeFormat call) (commaOrEmpty call))
                (convertToC (cdr call))
            )
    )
)

(define lisp (read))
(display (car lisp))
(display "(")
(map display (convertToC (cdr lisp)))
(display ")")
