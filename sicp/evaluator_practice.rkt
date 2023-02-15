#lang sicp

; ACTUAL PROGRAM
(((lambda (x) (lambda (y) (- x y))) 3) 4)

; PRETTY-PRINTED
(((lambda (x) 
    (lambda (y)
      (- x y)) )
  3)
 4)

; MY SIMPLIFICATION
(define (pro1 x)
  (lambda (y)
    (- x y)))

((pro1 3) 4)
