main :: IO()
main = do
    let inp = [12, 15]
    print (cw inp)

cw :: [Int] -> [[Int]]
cw inp = xs where
    y = [ n -> [1..x] | x <- inp, ]
    xs = [x]