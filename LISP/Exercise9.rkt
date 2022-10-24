;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Exercise9) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)
; Add the following line to the definitions area of DrRacket:

(define in 0.0)

(if (number? in)
    (abs in)
    (if (string? in)
        (string-length in)
        (if (image? in)
            (* (image-width in) (image-height in))
            (if (boolean? in)
                (if (equal? #true in)
                    10
                    20)
                (error "not supported data type")))))