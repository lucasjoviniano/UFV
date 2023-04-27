import           BubbleSort                     ( bubbleSort )
import           SelectionSort                  ( selectionSort )
import           Test.QuickCheck

prop_idempotent :: [Integer] -> Bool
prop_idempotent xs =
  BubbleSort.bubbleSort (BubbleSort.bubbleSort xs) == BubbleSort.bubbleSort xs

prop_length :: [Integer] -> Bool
prop_length xs = length xs == length (BubbleSort.bubbleSort xs)

prop_minimum :: [Integer] -> Property
prop_minimum xs = not (null xs) ==> head (bubbleSort xs) == minimum xs

idempotent :: [Integer] -> Bool
idempotent xs = selectionSort (selectionSort xs) == selectionSort xs

checkLength :: [Integer] -> Bool
checkLength xs = length xs == length (selectionSort xs)

main :: IO ()
main = do
  quickCheck prop_idempotent
  quickCheck prop_length
  quickCheck prop_minimum
  quickCheck idempotent
  quickCheck checkLength
  putStrLn "Done!"
