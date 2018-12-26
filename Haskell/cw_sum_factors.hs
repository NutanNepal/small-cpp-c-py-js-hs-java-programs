import Data.List

main :: IO()
main = do
    let inp = [400, 500, 600, 110, 126, 107, 158, 204, 159201, 50000000001]
    print (sumOfDivided inp)

sumOfDivided :: [Integer] -> [(Integer, Integer)]
sumOfDivided inp = out where
    zss = [ [n, m] | x <- inp, n <- [1,2..((floor.sqrt.abs.fromIntegral) x) + 1],
        x `rem` n == 0, m <- [quot (abs x) n]] --get all factors
    ys = (tail.sort.nub.concat) zss --remove 1 and duplicates and sort
    xs = ys \\ [ n | n <- ys, z <- ys, n > z, n `rem` z == 0 ]  --prime factors
    --for each prime factor, calculate the sum
    out = [ (p, q) | p <- xs, q <- [sum [if x `rem` p == 0 then x else 0 | x <- inp]]]