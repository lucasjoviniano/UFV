module SelectionSort
  ( selectionSort
  ) where

selectionSort :: Ord a => [a] -> [a]
selectionSort [] = []
selectionSort (x : xs) =
  let (y, ys) = leastUnsorted (x : xs) in y : selectionSort ys

leastUnsorted :: Ord a => [a] -> (a, [a])
leastUnsorted [x] = (x, [])
leastUnsorted (x : xs) =
  let (y, ys) = leastUnsorted xs in if x <= y then (x, xs) else (y, x : ys)
