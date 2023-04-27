module BubbleSort
  ( bubbleSort
  ) where

bubbleSort :: (Ord a) => [a] -> [a]
bubbleSort lst = if bpassed == lst then lst else bubbleSort bpassed
  where bpassed = bubblePass lst

bubblePass :: (Ord a) => [a] -> [a]
bubblePass []  = []
bubblePass [x] = [x]
bubblePass (x1 : x2 : xs) =
  if x1 < x2 then x2 : bubblePass (x1 : xs) else x1 : bubblePass (x2 : xs)
