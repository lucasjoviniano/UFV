(ns trabalho-um.azar (:gen-class))

(defn toss-coin "Joga moeda" [] (rand-nth '(::head ::tail)))

(defn check-swap
  "Decide se quem estava na frente mudou. Só acontece quando ambos forem iguais"
  [v ans]
  (if (= (ans :v1) (ans :v2)) (inc v) v))

(defn clear-answer
  "Limpa os valores desnecessários de fim de jogo"
  [ans winner]
  (-> ans
      (dissoc :v1)
      (dissoc :v2)
      (assoc :winner winner)))

(defn azar
  [first-amount second-amount]
  (loop [ans {:v1 first-amount
              :v2 second-amount
              :winner ""
              :rounds 1
              :one-swaps 0
              :two-swaps 0}]
    (let [coin (toss-coin)]
      (cond
        (zero? (ans :v1)) (clear-answer ans "segundo")
        (zero? (ans :v2)) (clear-answer ans "primeiro")
        :else (case coin
                ::head (recur (-> ans
                                  (update :two-swaps check-swap ans)
                                  (update :v1 dec)
                                  (update :v2 inc)
                                  (update :rounds inc)))
                ::tail (recur (-> ans
                                  (update :one-swaps check-swap ans)
                                  (update :v1 inc)
                                  (update :v2 dec)
                                  (update :rounds inc))))))))
