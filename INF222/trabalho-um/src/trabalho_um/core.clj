(ns trabalho-um.core
  (:gen-class))
(require '[clojure.data.csv :as csv]
         '[clojure.java.io :as io]
         '[trabalho-um.azar :as azar]
         '[clojure.set :as set])

(defrecord Player [name aim])

(defn get-probabilities []
  "Gera uma tupla de tentativas"
  (repeatedly 2 rand))

(defn battle
  [probability player-one player-two]
  (cond
    (< (first probability) (:aim player-one)) :player-one
    (< (second probability) (:aim player-two)) :player-two
    :else :none))

(defn duel-battle
  "Define qual jogador ganhou um duelo (qual acertou primeiro)"
  [player-one player-two]
  (loop [p (get-probabilities)]
    (let [winner (battle p player-one player-two)]
      (if (= winner :none)
        (recur (get-probabilities))
        winner))))

(defn truel_battle
  [strategy player-one player-two player-three]
  (loop [p-one player-one
         p-two player-two
         p-three player-three
         probability (get-probabilities)
         one-dead false]
    (let [winner (battle probability p-one p-two)]
      (if one-dead
        (case winner
          :player-one (:name p-one)
          :player-two (:name p-two)
          :none (recur p-one p-two p-three (get-probabilities) true))
        (case winner
          :player-one (recur p-three p-one p-two (get-probabilities) true)
          :player-two (recur p-three p-two p-one (get-probabilities) true)
          :none (case strategy
                  1 (recur p-three p-one p-two (get-probabilities) false)
                  2 (recur p-one p-two p-three (get-probabilities) false)))))))

(defn duel [amount player-one player-two]
  (frequencies (repeatedly amount (fn [] (duel-battle (Player. "A" player-one)
                                                      (Player. "B" player-two))))))

(defn truel [strategy amount player-one player-two player-three]
  (frequencies (repeatedly amount (fn [] (truel_battle strategy
                                                       (Player. "A" player-one)
                                                       (Player. "B" player-two)
                                                       (Player. "C" player-three))))))

  (defn -main
    "Decide a atividade e escreve os resultados em arquivos \".csv\""
    [& args]
    (case (first args)
      "duelo" (let [[amount f-n f-d s-n s-d] (map #(Integer/parseInt %) (rest args))]
                (with-open [writer (io/writer (format "duelo-%d.csv" amount) )]
                  (csv/write-csv writer (set/rename-keys
                                          (duel amount (/ f-n f-d) (/ s-n s-d))
                                          {:player-one "A" :player-two "B"}))))

      "truelo" (let [[amount s f-n f-d s-n s-d t-n t-d] (map #(Integer/parseInt %) (rest args))]
                 (with-open [writer (io/writer (format "truelo-%d-%d.csv" amount s))]
                   (csv/write-csv writer (truel s amount (/ f-n f-d) (/ s-n s-d) (/ t-n t-d)))))


      "azar" (let [[amount v-one v-two] (map #(Integer/parseInt %) (rest args))
                   runs (repeatedly amount (fn [] (azar/azar v-one v-two)))
                   columns [:winner :rounds :one-swaps :two-swaps]
                   headers (map name columns)
                   rows (mapv #(mapv % columns) runs)]
               (with-open [writer (io/writer (format "azar-%d.csv" amount) )]
                 (csv/write-csv writer (cons headers rows))))))
