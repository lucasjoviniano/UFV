(ns trabalho-um.azar (:gen-class))

; Quantas vezes altera o jogador que está na frente
; Ficou na frente o jogo todo?
; Em quantos lançamentos ele ficou na frente

(defn toss-coin "Joga moeda" [] (rand-nth '(::head ::tail)))

(defn azar
  [first-amount second-amount]
  (loop [ans {:v1 first-amount :v2 second-amount :winner "" :rounds 1 :one-swaps 0 :two-swaps 0}]
    (let [coin (toss-coin)]
      (cond
        (zero? (get ans :v1)) (assoc ans :winner "segundo")
        (zero? (get ans :v2)) (assoc ans :winner "primeiro")
        :else (case coin
                ::head (recur (-> ans
                                  (update :two-swaps #(if (= (get ans :v1) (get ans :v2)) (inc %) %))
                                  (update :v1 dec)
                                  (update :v2 inc)
                                  (update :rounds inc)))
                ::tail (recur (-> ans
                                  ; Quem está na frente só altera se os valores forem iguais
                                  (update :one-swaps #(if (= (get ans :v1) (get ans :v2)) (inc %) %))
                                  (update :v1 inc)
                                  (update :v2 dec)
                                  (update :rounds inc))))))))
