import Data.List (maximumBy, subsequences)
import Data.Ord (comparing)

main :: IO ()
main = do
  line <- getLine
  let noPalindromes = filter (\w -> w /= reverse w) $ subsequences line
  case noPalindromes of
    [] -> print 0
    _ -> print (length (maximumBy (comparing length) noPalindromes))
