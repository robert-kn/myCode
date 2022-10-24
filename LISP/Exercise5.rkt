;; The first three lines of this file were inserted by DrRacket. They record metadata
;; about the language level of this file in a form that our tools can easily process.
#reader(lib "htdp-beginner-reader.ss" "lang")((modname Exercise5) (read-case-sensitive #t) (teachpacks ()) (htdp-settings #(#t constructor repeating-decimal #f #t none #f () #f)))
(require 2htdp/image)

;; create the image of a simple boat or tree

(define TREE-SIZE 400)

(overlay/xy    (triangle (/ TREE-SIZE 2) "solid" "seagreen")
               (/ TREE-SIZE 5) (/ TREE-SIZE 10)
               (rectangle (/ TREE-SIZE 10)(/ TREE-SIZE 2) "solid" "brown"))


;; create the image of a simple tree


(define BOAT-SIZE 100)

;the mast and sail are adapted from tree above
(above (overlay/xy    (triangle (* BOAT-SIZE 1.5) "solid" "red")
                      (* BOAT-SIZE .75) (/ BOAT-SIZE 10)
                      (rectangle (/ BOAT-SIZE 25) (* BOAT-SIZE 1.25) "solid" "brown"))
;the hull
       (beside (triangle/sas (/ BOAT-SIZE 4) 90 (/ BOAT-SIZE 4) "solid" "blue")
               (rectangle (* BOAT-SIZE 1.25) (/ BOAT-SIZE 4) "solid" "blue")
               (triangle/ass 90 (/ BOAT-SIZE 4) (/ BOAT-SIZE 4) "solid" "blue")))



