(ns trabalho-um.core
  (:gen-class))
(require '[clojure.data.csv :as csv]
         '[clojure.java.io :as io]
         '[trabalho-um.azar :as azar]
         '[clojure.set :as set])

(defrecord Player [name aim alive])

(defn get-probabilities
  "Gera uma quantidade definida por amount de tentativas"
  [amount]
  (repeatedly amount rand))

(defn battle
  [probability player-one player-two]
  (cond
    (<= (first probability) player-one) :player-one
    (<= (second probability) player-two) :player-two
    :else :none))

(defn duel-battle
  "Define qual jogador ganhou um duelo (qual acertou primeiro)"
  [player-one player-two]
  (loop [p (get-probabilities 2)]
    (let [winner (battle p player-one player-two)]
      (if (= winner :none)
        (recur (get-probabilities 2))
        winner))))

(defn duel [amount player-one player-two]
  (frequencies (repeatedly amount (fn [] (duel-battle player-one player-two)))))

(defn -main
  "Decide a atividade e escreve os resultados em arquivos \".csv\""
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
