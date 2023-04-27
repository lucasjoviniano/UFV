module Main
  ( main
  ) where

import           Control.Arrow

distance2 :: Floating a => (a, a) -> (a, a) -> a
distance2 (x1, y1) (x2, y2) = sqrt (x' * x' + y' * y')
 where
  x' = x1 - x2
  y' = y1 - y2

distance :: Floating a => [(a, a)] -> a
distance []          = 0
distance xa@(_ : xs) = sum (zipWith distance2 xa xs)

nextPermutation :: Ord a => [a] -> [a]
nextPermutation =
  uncurry (++)
    . uncurry swap
    . (fmap fst *** fmap fst)
    . span (uncurry (>=))
    . (<*>) zip (\ls -> head ls : ls)
    . reverse
 where
  swap rpost []             = ([], rpost)
  swap rpost (pivot : rpre) = (reverse rpre, ins . span (<= pivot) $ rpost)
   where
    ins (le, []    ) = le ++ [pivot]
    ins (le, a : as) = a : le ++ pivot : as

main :: IO ()
main = do
  putStrLn "hello world"
