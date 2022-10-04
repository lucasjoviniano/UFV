(ns trabalho-um.azar (:gen-class))

(defn toss-coin "Joga moeda" [] (rand-nth '(:cara :coroa)))

(defn azar
  [first-amount second-amount]
  (loop [v1 first-amount v2 second-amount rounds 1]
    (let [coin (toss-coin)]
      (if (or (zero? v1) (zero? v2))
        rounds
        (if (= coin :cara)
          (recur (dec v1) v2 (inc rounds))
          (recur v1 (dec v2) (inc rounds)))))))
