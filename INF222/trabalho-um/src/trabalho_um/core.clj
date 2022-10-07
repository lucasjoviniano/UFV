(ns trabalho-um.core
  (:gen-class))
(require '[clojure.data.csv :as csv]
         '[clojure.java.io :as io]
         '[trabalho-um.azar :as azar]
         '[clojure.set :as set])

(defrecord Player [name aim])

(defn get-probabilities
  "Gera uma quantidade definida por amount de tentativas"
  [amount]
  (repeatedly amount rand))

(defn battle
  [probability player-one player-two]
  (cond
    (< (first probability) (:aim player-one)) :player-one
    (< (second probability) (:aim player-two)) :player-two
    :else :none))

(defn duel-battle
  "Define qual jogador ganhou um duelo (qual acertou primeiro)"
  [player-one player-two]
  (loop [p (get-probabilities 2)]
    (let [winner (battle p player-one player-two)]
      (if (= winner :none)
        (recur (get-probabilities 2))
        winner))))

(defn strategy-one
  [player-one player-two player-three]
  (loop [p-one player-one
         p-two player-two
         p-three player-three
         probability (get-probabilities 2)
         one-dead false]
    (let [winner (battle probability p-one p-two)]
      (if one-dead
        (case winner
          :player-one (:name p-one)
          :player-two (:name p-two)
          :none (recur p-one p-two p-three (get-probabilities 2) true))
        (case winner
          :player-one (recur p-three p-one p-two (get-probabilities 2) true)
          :player-two (recur p-three p-two p-one (get-probabilities 2) true)
          :none (recur p-three p-two p-one (get-probabilities 2) false))
        ))))

(defn strategy-two
  [player-one player-two player-three]
  (loop [p-one player-one
         p-two player-two
         p-three player-three
         probability (get-probabilities 2)
         one-dead false]
    (let [winner (battle probability p-one p-two)]
      (if one-dead
        (case winner
          :player-one (:name p-one)
          :player-two (:name p-two)
          :none (recur p-one p-two p-three (get-probabilities 2) true))
        (case winner
          :player-one (recur p-three p-one p-two (get-probabilities 2) true)
          :player-two (recur p-three p-two p-one (get-probabilities 2) true)
          :none (recur p-one p-two p-three (get-probabilities 2) false))))))

(defn duel [amount player-one player-two]
  (frequencies (repeatedly amount (fn [] (duel-battle (Player. "A" player-one)
                                                      (Player. "B" player-two))))))

(defn truel [strategy amount player-one player-two player-three]
  (case strategy
    1 (frequencies (repeatedly amount (fn [] (strategy-one (Player. "A" player-one)
                                                           (Player. "B" player-two)
                                                           (Player. "C" player-three)))))

    2 (frequencies (repeatedly amount (fn [] (strategy-two (Player. "A" player-one)
                                                           (Player. "B" player-two)
                                                           (Player. "C" player-three)))))))

(defn -main
  "Decide a atividade e escreve os resultados em arquivos \".csv\""
  [& args]
  (case (first args)
    "duelo" (let [[amount f-n f-d s-n s-d] (map #(Integer/parseInt %) (rest args))]
              (with-open [writer (io/writer "duelo.csv")]
                (csv/write-csv writer (set/rename-keys
                                        (duel amount (/ f-n f-d) (/ s-n s-d))
                                        {:player-one "player-one" :player-two "player-two"}))))

    "truelo" (let [[amount s f-n f-d s-n s-d t-n t-d] (map #(Integer/parseInt %) (rest args))]
               (with-open [writer (io/writer "truelo.csv")]
                 (csv/write-csv writer (truel s amount (/ f-n f-d) (/ s-n s-d) (/ t-n t-d)))))


    "azar" (let [[amount v-one v-two] (map #(Integer/parseInt %) (rest args))
                 runs (repeatedly amount (fn [] (azar/azar v-one v-two)))
                 columns [:winner :rounds :one-swaps :two-swaps]
                 headers (map name columns)
                 rows (mapv #(mapv % columns) runs)]
             (with-open [writer (io/writer "azar.csv")]
               (csv/write-csv writer (cons headers rows))))))