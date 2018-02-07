def hull_method(points):
    points.sort()
    seen = set()
    pointNumbers = []
    for lst in points:
        curr = tuple(lst)
        if curr not in seen:
            pointNumbers.append(lst)
            seen.add(curr)
    print(pointNumbers)

    def getSlope(index, i, pointNumbers):
        x = (pointNumbers[i][0] - pointNumbers[index][0])
        if (x == 0) and ((pointNumbers[i][1] - pointNumbers[index][1]) > 0 ):
            return float("inf")
        elif (x == 0) and ((pointNumbers[i][1] - pointNumbers[index][1]) < 0 ):
            return float("-inf")
        else:
            return (pointNumbers[i][1] - pointNumbers[index][1])/x

    def maxslopeIndex(index, pointNumbers):
        maxSlope = float("-inf")
        maxSlopeIndex = 0
        for i in range (index + 1, len(pointNumbers) - 1):
            slope = getSlope(index, i, pointNumbers)
            if slope >= maxSlope:
                maxSlope = slope
                maxSlopeIndex = i
        print("max slope is ", maxSlope)
        if maxSlope < 0:
            return None
        else:
            return maxSlopeIndex

    def minslopeIndex(index, pointNumbers):
        minSlope = float("inf")
        minSlopeIndex = 0
        for i in range (index-1, 0, -1):
            slope = getSlope(index, i, pointNumbers)
            if slope <= minSlope:
                minSlope = slope
                minSlopeIndex = i
        print("min slope is ", minSlope)
        if minSlope > 0:
            return None
        else:
            return minSlopeIndex

    leftindex = 0
    rightindex = len(pointNumbers) - 1

    print(leftindex, rightindex)

    minIndex = pointNumbers[0]
    maxIndex = pointNumbers[rightindex]
    output = []
    output.append(pointNumbers[leftindex])
    output.append(pointNumbers[rightindex])

    print(output)

    while True:

        print("calculating points above")
        nextleftIndex = maxslopeIndex(leftindex, pointNumbers)
        if leftindex == rightindex:
            print("o really?")
            break

        if not nextleftIndex == None:
            output.append(pointNumbers[nextleftIndex])
            leftindex = nextleftIndex
        else:
            print("oops")
            break

        print(leftindex, rightindex)

        print(output)

        nextrightIndex = minslopeIndex(rightindex, pointNumbers)
        if leftindex == nextrightIndex:
            print("o really?")
            break
        if not nextrightIndex == None:
            output.append(pointNumbers[nextrightIndex])
            rightindex = nextrightIndex
        else:
            print("oops")
            break
        print(output)

    leftindex = 0
    rightindex = len(pointNumbers) - 1

    while True:

        print("calculating points below")
        nextleftIndex = minslopeIndex(leftindex, pointNumbers)
        if not leftindex == rightindex:
            if not nextleftIndex == None:
                output.append(pointNumbers[nextleftIndex])
                leftindex = nextleftIndex
            else:
                print("oops")
                break
            print(output)
        else:
            print("o really?")
            break

        print(leftindex, rightindex)
        nextrightIndex = maxslopeIndex(rightindex, pointNumbers)
        if not leftindex == nextrightindex:
            if not nextrightIndex == None:
                output.append(pointNumbers[nextrightIndex])
                rightindex = nextrightIndex
            else:
                print("oops")
                break
            print(output)
        else:
            print("o really?")
            break

    return sorted(output)
print(hull_method([[0, 7], [2, 2], [2, 11], [7, 2], [9, 8]]))
#should equal [[0, 7], [2, 2], [2, 11], [7, 2], [9, 8]]
