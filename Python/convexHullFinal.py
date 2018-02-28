def hull_method(points):
    points.sort()
    seen = set()
    pointNumbers = []
    for lst in points:
        curr = tuple(lst)
        if curr not in seen:
            pointNumbers.append(lst)
            seen.add(curr)

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
        return maxSlopeIndex

    def minslopeIndex(index, pointNumbers):
        minSlope = float("inf")
        minSlopeIndex = 0
        for i in range (index-1, 0, -1):
            slope = getSlope(i, index, pointNumbers)
            if slope <= minSlope:
                if (slope == float("-inf")) and not (pointNumbers[len(pointNumbers) - 1][0] == pointNumbers[i][0]):
                    pass
                elif slope > getSlope(len(pointNumbers) - 1, 0, pointNumbers):
                    pass
                else:
                    minSlope = slope
                    minSlopeIndex = i
        return minSlopeIndex

    def maxslopeIndex2(index, pointNumbers):
        maxSlope = float("-inf")
        maxSlopeIndex = 0
        for i in range (index-1, 0, -1):
            slope = getSlope(i, index, pointNumbers)
            if slope >= maxSlope:
                if (slope == float("inf")) and not (pointNumbers[len(pointNumbers) - 1][0] == pointNumbers[i][0]):
                    pass
                elif slope < getSlope(len(pointNumbers) - 1, 0, pointNumbers):
                    pass
                else:
                    maxSlope = slope
                    maxSlopeIndex = i
        return maxSlopeIndex

    def minslopeIndex2(index, pointNumbers):
        minSlope = float("inf")
        minSlopeIndex = 0
        for i in range (index + 1, len(pointNumbers) - 1):
            slope = getSlope(index, i, pointNumbers)
            if slope <= minSlope:
                if (slope == float("-inf")) and not (pointNumbers[0][0] == pointNumbers[i][0]):
                    pass
                elif slope > getSlope(len(pointNumbers) - 1, 0, pointNumbers):
                    pass
                else:
                    minSlope = slope
                    minSlopeIndex = i
        return minSlopeIndex

    leftindex = 0
    rightindex = len(pointNumbers) - 1

    indexes = []
    indexes.append(leftindex)
    indexes.append(rightindex)

    while True:
        nextleftIndex = maxslopeIndex(leftindex, pointNumbers)
        if nextleftIndex == rightindex:
            break
        else:
            if nextleftIndex not in indexes:
                indexes.append(nextleftIndex)
                leftindex = nextleftIndex
            else:
                pass

        nextrightIndex = minslopeIndex(rightindex, pointNumbers)
        if leftindex == nextrightIndex:
            break
        else:
            if nextrightIndex not in indexes:
                indexes.append(nextrightIndex)
                rightindex = nextrightIndex
            else:
                pass

    leftindex = 0
    rightindex = len(pointNumbers) - 1

    while True:
        nextleftIndex = minslopeIndex2(leftindex, pointNumbers)
        if nextleftIndex == rightindex:
            break
        else:
            if nextleftIndex not in indexes:
                indexes.append(nextleftIndex)
                leftindex = nextleftIndex
            else:
                pass

        nextrightIndex = maxslopeIndex2(rightindex, pointNumbers)
        if leftindex == nextrightIndex:
            break
        else:
            if nextrightIndex not in indexes:
                indexes.append(nextrightIndex)
                rightindex = nextrightIndex
            else:
                pass

    output =[]
    for x in indexes:
        output.append(pointNumbers[x])
    return sorted(output)
