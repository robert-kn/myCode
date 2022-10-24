;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Exercise1) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Exercise 1. Add the following definitions for x and y to DrRacket’s definitions area:
; The expected result for these values is 5, but your expression should produce the correct result even after you change these definitions.

(define x 3)
(define y 4)
(define distance (sqrt (+ (sqr (- x 0)) (sqr (- y 0)))))
distance




