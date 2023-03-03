#!/bin/racket
#lang sicp

; ACTUAL PROGRAM
(((lambda (x) (lambda (y) (- x y))) 3) 4)

; PRETTY-PRINTED
; (((lambda (x) 
;     (lambda (y)
;       (- x y)) )
;   3)
;  4)

; MY SIMPLIFICATION
; (define (pro1 x)
;  (lambda (y)
;    (- x y)))

; ((pro1 3) 4)

; RECURSIVELY INFINITE CONVERGENCE EXPONENTIATION FUNCTION
(define f (lambda (g)
  (lambda (x n)
    (cond ((= n 0) 1)
          (else
           (* x
              (g x (- n 1))))))))

; g SHOULD BE A SUITABLE EXPONENTIATION FUNCTION SO IF IT'S CORRECT FOR (N-1), IT'S CORRECT FOR N.
(define (g x n)
  (cond ((= 0 n) 1)
        (else (* x
                 (g x (- n 1))))))

((f g) 16 2)
