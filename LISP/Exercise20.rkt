;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Exercise20) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Define the function string-delete, which consumes a string plus a number i and deletes the ith position from str.
; Assume i is a number between 0 (inclusive) and the length of the given string (exclusive).

(define (string-delete str i)
  (if (> i (sub1 (string-length str)))
      (error "the second argument is larger than the string length")
      (string-append (substring str 0 i) (substring str (add1 i)))))

(string-delete "hello" 1)