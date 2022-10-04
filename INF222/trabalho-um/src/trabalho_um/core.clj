(ns trabalho-um.core
  (:gen-class))

(defn get-probabilities "Gera uma quantidade definina por amount de tentativas"
  [amount]
  (repeatedly amount rand))

(defn duel-battle
  "Define qual jogador ganhou um duelo (qual acertou primeiro)"
  [amount player-one player-two]
  (let [probs (partition 2 (get-probabilities amount))]
    (loop [p probs]
      (cond
      (<= (ffirst p) player-one) :player-one
      (<= (second (first p)) player-two) :player-two
    :else (recur (rest p))))))

(defn duel [amount player-one player-two]
  (frequencies (repeatedly amount (fn [] (duel-battle amount player-one player-two)))))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (doseq [arg args]
    (println (duel (Integer/parseInt arg) (/ 4 6) (/ 5  6)))))
