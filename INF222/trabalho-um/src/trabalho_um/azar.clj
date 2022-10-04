(ns trabalho-um.azar (:gen-class))

; Quantas vezes altera o jogador que está na frente
; Ficou na frente o jogo todo?
; Em quantos lançamentos ele ficou na frente

(defn toss-coin "Joga moeda" [] (rand-nth '(:cara :coroa)))

(defn azar
  [first-amount second-amount]
  (loop [v1 first-amount v2 second-amount rounds 1]
    (let [coin (toss-coin)]
      (if (zero? v1) 
        [:segundo rounds]
        (if (zero? v2)
          [:primeiro rounds]
        (if (= coin :cara)
          (recur (dec v1) (inc v2) (inc rounds))
          (recur (inc v1) (dec v2) (inc rounds))))))))
