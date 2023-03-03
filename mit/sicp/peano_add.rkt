#lang sicp
(define (add x y)
  (if (= x 0) y
      (add (- x 1) (+ y 1))))      