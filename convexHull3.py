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
        x = pointNumbers[i][0] - pointNumbers[index][0]
        y = pointNumbers[i][1] - pointNumbers[index][1]
        if (x == 0) and (y > 0) ):
            return float("inf")
        elif (x == 0) and (y < 0 ):
            return float("-inf")
        else:
            return y/x

    def maxslopeIndex(index, pointNumbers):
        maxSlope = float("-inf")
        maxSlopeIndex = 0
        for i in range (index + 1, len(pointNumbers) - 1):
            slope = getSlope(index, i, pointNumbers)
            if slope >= maxSlope:
                if (slope == float("inf")) and not (pointNumbers[0][0] == pointNumbers[i][0]):
                    pass
                elif slope < getSlope(len(pointNumbers) - 1, 0, pointNumbers):
                    pass
                else:
                    maxSlope = slope
                    maxSlopeIndex = i
        print("max slope is ", maxSlope, " on index ", maxSlopeIndex)
        return maxSlopeIndex

    def minslopeIndex(index, pointNumbers):
        minSlope = float("inf")
        minSlopeIndex = 0
        for i in range (index-1, 0, -1):
            slope = getSlope(i, index, pointNumbers)
            if slope <= minSlope:
                if (slope == float("-inf")) and not (pointNumbers[len(pointNumbers) - 1][0] == pointNumbers[i][0]):
                    pass
                elif slope > getSlope(0, len(pointNumbers) - 1, pointNumbers):
                    pass
                else:
                    minSlope = slope
                    minSlopeIndex = i
        print("min slope is ", minSlope, " on index ", minSlopeIndex)
        return minSlopeIndex

    def maxslopeIndex2(index, pointNumbers):
        maxSlope = float("-inf")
        maxSlopeIndex = 0
        for i in range (index-1, 0, -1):
            slope = getSlope(index, i, pointNumbers)
            if slope >= maxSlope:
                if (slope == float("inf")) and not (pointNumbers[0][0] == pointNumbers[i][0]):
                    pass
                elif slope < getSlope(0, len(pointNumbers) - 1, pointNumbers):
                    pass
                else:
                    maxSlope = slope
                    maxSlopeIndex = i
        print("max slope is ", maxSlope, " on index ", maxSlopeIndex)
        return maxSlopeIndex

    def minslopeIndex2(index, pointNumbers):
        minSlope = float("inf")
        minSlopeIndex = 0
        for i in range (index + 1, len(pointNumbers) - 1):
            slope = getSlope(index, i, pointNumbers)
            if slope <= minSlope:
                if (slope == float("-inf")) and not (pointNumbers[0][0] == pointNumbers[i][0]):
                    pass
                elif slope > getSlope(0, len(pointNumbers) - 1, pointNumbers):
                    pass
                else:
                    minSlope = slope
                    minSlopeIndex = i
        print("min slope is ", minSlope, " on index ", minSlopeIndex)
        return minSlopeIndex

    leftindex = 0
    rightindex = len(pointNumbers) - 1

    indexes = []
    indexes.append(leftindex)
    indexes.append(rightindex)
    print(indexes)

    while True:

        print("calculating points above")
        nextleftIndex = maxslopeIndex(leftindex, pointNumbers)
        if nextleftIndex == rightindex:
            print("o really?")
            break
        else:
            if nextleftIndex not in indexes:
                indexes.append(nextleftIndex)
                leftindex = nextleftIndex
            else:
                print("oops")
                pass

        print(leftindex, rightindex)

        print(indexes)

        nextrightIndex = minslopeIndex(rightindex, pointNumbers)
        if leftindex == nextrightIndex:
            print("o really?")
            break
        if nextrightIndex not in indexes:
            indexes.append(nextrightIndex)
            rightindex = nextrightIndex
        else:
            print("oops")
            pass
        print(indexes)

    leftindex = 0
    rightindex = len(pointNumbers) - 1

    while True:

        print("calculating points below")
        nextleftIndex = minslopeIndex2(leftindex, pointNumbers)
        if not nextleftIndex == rightindex:
            if nextleftIndex not in indexes:
                indexes.append(nextleftIndex)
                leftindex = nextleftIndex
            else:
                print("oops")
                pass
            print(indexes)
        else:
            print("o really?")
            break

        print(leftindex, rightindex)
        nextrightIndex = maxslopeIndex2(rightindex, pointNumbers)
        if not leftindex == nextrightIndex:
            if nextrightIndex not in indexes:
                indexes.append(nextrightIndex)
                rightindex = nextrightIndex
            else:
                print("oops")
                pass
            print(indexes)
        else:
            print("o really?")
            break
        print(leftindex, rightindex)

    output =[]
    for x in indexes:
        output.append(pointNumbers[x])
    return sorted(output)
print(hull_method([[2, 31], [10, 0], [11, 38], [22, 68], [25, 40], [32, 32], [37, 44], [41, 0], [46, 83], [47, 88], [48, 35], [55, 54], [57, 47], [64, 22], [65, 0], [67, 94], [68, 39], [79, 41], [80, 12], [88, 61], [96, 26], [96, 61], [96, 86]]))
