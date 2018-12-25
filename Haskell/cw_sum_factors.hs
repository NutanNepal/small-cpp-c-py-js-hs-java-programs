import Data.List

main :: IO()
main = do
    let inp = [15,21,24,30,45]
    print (sumOfDivided inp) 

sumOfDivided :: [Integer] -> [(Integer, Integer)]
sumOfDivided inp = a where
    ys = sort [ n | x <- inp, n <- [2..x-1], x `rem` n == 0 ]                   --factors
    xs = diff (nub ys) (nub [ n | n <- ys, z <- ys, n > z, n `rem` z == 0 ])    --prime factors
    a = [ (p, r) | p <- xs, r <- inp, r `rem` p == 0 ]                          --pairs of factors and input numbers


rmdups2 :: [(Integer, Integer)] -> [(Integer, Integer)]
rmdups2 = map head . group . sort
diff :: [Integer] -> [Integer] -> [Integer]
diff x y = [ z | z <- x, z `notElem` y]
diff2 :: [(Integer, Integer)] -> [(Integer, Integer)] -> [(Integer, Integer)]
diff2 x y = [ z | z <- x, z `notElem` y]
add :: (Integer, Integer) -> (Integer, Integer) -> (Integer, Integer)
add x y = (fst x, snd x + snd y)