(ns trabalho-um.core
  (:gen-class))

(defn get-probabilities "Gera uma quantidade definina por amounts de tentativas"
  [amount]
  (take amount (repeatedly rand)))

(defn get-num-hits
  "Retorna a quantidade de tentativas feitas antes de acertar"
  [aim, probs] (count (take-while #(> % aim) probs)))

(defn duel [amount, player-one, player-two]
  (let [probs (get-probabilities amount),
        p-one (get-num-hits player-one (take-nth 2 probs)),
        p-two (get-num-hits player-two (take-nth 2 (rest probs)))]
    "Define qual jogador ganhou um duelo (qual acertou primeiro)"
    (cond
      (<= p-one p-two) :player-one
      (< p-two p-one) :player-two)))

(defn -main
  "I don't do a whole lot ... yet."
  [& args]
  (println "Hello, World!"))
