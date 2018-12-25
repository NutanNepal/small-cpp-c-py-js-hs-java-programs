main :: IO()
main = do
    putStrLn "Enter the first argument: "
    input1 <- getLine
    let x = (read input1 :: Int)
    putStrLn "Enter the seconf argument: "
    input2 <- getLine
    let y = (read input2 :: Int)
    print (cw x y)

cw :: Int -> Int -> [Int]
cw x y = [ x^n | n <- [2^(z - 1) | z <- [1..y] ] ]