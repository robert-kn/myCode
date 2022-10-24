;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Exercise13) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Define the function string-first, which extracts the first 1String from a non-empty string.
; ; A 1String is a String of length 1

(define (string-first str)
  (if (> (string-length str) 1)
      (string-ith str 0)
      (error "The string is too short")))

(string-first "hello")