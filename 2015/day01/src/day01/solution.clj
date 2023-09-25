(ns day01.solution)

(defn solver-01 [input]
  (loop [current-input input
         result 0]
    (if (= current-input "")
      result
      (recur (subs current-input 1)
             (if (= (first current-input) \()
               (+ result 1)
               (- result 1))))))

(defn solver-02 [input]
  (loop [current-input input
         current-floor 0
         input-position 0]
    (if (= current-floor -1)
      input-position
      (recur (subs current-input 1)
             (if (= (first current-input) \()
               (+ current-floor 1)
               (- current-floor 1))
             (inc input-position)))))
