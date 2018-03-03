main = do
    let primes = 2 : [x | x <- [3,5..100], y <- primes, x `mod` y \=0]
    print(primes)
