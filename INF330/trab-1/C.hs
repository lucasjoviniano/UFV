erdosGallai :: [Int] -> Int -> Bool
erdosGallai [] _ = True
erdosGallai [x] _ = x == 0
erdosGallai lst k = dk <= (k * (k - 1) + mdk)
  where
    dk = sum (take k lst)
    mdk = foldl min k (drop k lst)
