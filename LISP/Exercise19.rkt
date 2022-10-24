;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Exercise19) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Define the function string-insert, which consumes a string str plus a number i and inserts "_" at the ith position of str. Assume i is a number between 0 and the length of
; the given string (inclusive).

(define (string-insert str i)
  (if (> i (sub1 (string-length str)))
      (error "the second argument is larger than the string length")
      (string-append (substring str 0 i) "_" (substring str i))))

(string-insert "helloworld" 5)