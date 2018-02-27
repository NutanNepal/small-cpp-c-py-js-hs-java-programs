function doubles(maxk, maxn) {
    total = 0
    for (k = 1; k <= maxk; k++) {
        for (n = 1; n <= maxn; n++) {
            j = Math.pow(k * (n + 1), (2 * k))
            total += 1 / j
        }
    }
    return total
}

console.log(doubles(100, 1000))