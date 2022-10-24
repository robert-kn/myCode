;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Exercise14) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
; Define the function string-last, which extracts the last 1String from a non-empty string. 
; A 1String is a String of length 1

(define (string-first str)
  (if (> (string-length str) 1)
      (string-ith str (sub1 (string-length str)))
      (error "String entered is too short")))
  

(string-first "")