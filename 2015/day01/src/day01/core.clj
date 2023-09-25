(ns day01.core
  (:gen-class)
  (:require [day01.solution :refer [solver-01 solver-02]]
            [clojure.string :refer [trim]]))

(defn -main
  "I don't do a whole lot ... yet."
    [& args]
  (let [input (trim (slurp "src/day01/input.txt"))]
    {:part1 (solver-01 input)
     :part2 (solver-02 input)}))

(-main)
