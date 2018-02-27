def integerpartitions(n):
    partitions = [[1]]
    for i in range(1, n+1):
        for j in range (i-1, -1, -1):
            get = []
            for items in partitions[j]:
                get.append([j] + items)
            
