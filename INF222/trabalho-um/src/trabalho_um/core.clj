(ns trabalho-um.core
  (:gen-class))
(require '[clojure.data.csv :as csv]
         '[clojure.java.io :as io]
         '[trabalho-um.azar :as azar]
         '[clojure.set :as set])

(defn get-probabilities
  "Gera uma quantidade definina por amount de tentativas"
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
  "Decide a atividade e escreve os resultados em arquivos .csv"
  [& args]
  (case (first args)
    "duelo" (let [[amount f-n f-d s-n s-d] (map #(Integer/parseInt %) (rest args))]
              (with-open [writer (io/writer "duelo.csv")]
                (csv/write-csv writer (set/rename-keys
                                        (duel amount (/ f-n f-d) (/ s-n s-d))
                                        {:player-one "player-one" :player-two "player-two"}))))

    "azar" (let [[amount v-one v-two] (map #(Integer/parseInt %) (rest args))
                 runs (repeatedly amount (fn [] (azar/azar v-one v-two)))
                 columns [:winner :rounds :one-swaps :two-swaps]
                 headers (map name columns)
                 rows (mapv #(mapv % columns) runs)]
             (with-open [writer (io/writer "azar.csv")]
               (csv/write-csv writer (cons headers rows))))))
