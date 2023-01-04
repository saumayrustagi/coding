#lang sicp

;(define (cons a b)
;  (lambda (pick)
;    (cond ((= pick 1) a)
;          ((= pick 2) b))))

;(define (car x) (x 1))

;(define (cdr x) (x 2))

(define (make-rat n d)
  (let ((g (gcd n d)))
    (let ((num (/ n g))
          (den (/ d g)))
      ;(display num)
      ;(display #\space)
      ;(display den)
      (cons num den))))
      
           

(define numer car)

(define denom cdr)

;(define pi (make-rat 22 7))

(car (make-rat 9 3))
(cdr (make-rat 9 3))
