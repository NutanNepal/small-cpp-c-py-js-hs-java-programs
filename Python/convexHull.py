def getSlope(point1, point2, pointNumbers):
    if(pointNumbers[point1][0] == pointNumbers[point2][0]):
        return "infinite"
    return float(pointNumbers[point2][1] - pointNumbers[point1][1])/ (pointNumbers[point2][0] - pointNumbers[point1][0])

def hull_method(pointList):
    xCoords = []
    yCoords = []
    n = 0
    pointNumbers = {}
    for point in pointList:
        xCoords.append(point[0])
        yCoords.append(point[1])
        pointNumbers[n] = point
        n += 1

    minX = min(xCoords)
    maxX = max(xCoords)

    if x.count(minX) > 1:
       count = 0
       maxY = float("-inf")
       while(count < len(xCoords)):
           if xCoords[count] == minX and yCoords[count] > maxY:
              minXIndex = count
           count += 1
    else:
        minXIndex = xCoords.index(minX)


    if x.count(maxX) > 1:
       count = 0
       maxY = float("-inf")
       while(count < len(xCoords)):
           if xCoords[count] == minX and yCoords[count] > maxY:
              maxXIndex = count
           count += 1
    else:
        maxXIndex = xCoords.index(maxX)

    currentLeftPoint = minXIndex
    currentRightPoint = maxXIndex
    topHalfLeft = []
    topHalfRight = []
    while(True):
        if(currentLeftPoint == currentRightPoint):
            topHalfLeft.append(pointList[currentLeftPoint])
            topHalfLeft.extend(topHalfRight)
            break
        topHalfLeft.append(pointList[currentLeftPoint])
        topHalfRight.insert(0, pointList[currentRightPoint])
        slopesLeft = []
        slopesRight = []
        count = 0
        while(count < len(pointList)):
            if(not(currentLeftPoint == count)):
                m = getSlope(currentLeftPoint, count, pointNumbers)
                slopesLeft.add(m)

            if(not(currentRightPoint == count)):
                m = getSlope(currentRightPoint, count, pointNumbers)
                slopesRight.add(m)

        count = 0
        maxLeftSlope = float("-inf")
        maxLeftSlopeIndex = 0
        while(count < len(slopesLeft)):
            if (slopesLeft[count] > maxLeftSlope):
                maxLeftSlope = slopesLeft[count]
                maxLeftSlopeIndex = count
            elif ((slopesLeft[count] == maxLeftSlope) and (xCoords[count] > xCoords[maxLeftSlopeIndex])):
                maxLeftSlope = slopesLeft[count]
                maxLeftSlopeIndex = count

        count = 0
        minRightSlope = float("inf")
        minRightSlopeIndex = 0
        while(count < len(slopesRight)):
            if (slopesRight[count] < minRightSlope):
                minRightSlope = slopesLeft[count]
                minRightSlopeIndex = count
            elif ((slopesRight[count] == minRightSlope) and (xCoords[count] < xCoords[minRightSlopeIndex])):
                minRightSlope = slopesRight[count]
                minRightSlopeIndex = count

        currentLeftPoint = maxLeftSlopeIndex
        currentRightPoint = minRightSlopeIndex


"""
    #sort by x
    pointList.sort(key=lambda pair: pair[0])

    def getSlope(index, i, pointNumbers):
        x = (pointNumbers[i][0] - pointNumbers[index][0])
        if x == 0:
            return float("infinite")
        else:
            return (pointNumbers[i][1] - pointNumbers[index][1])/x

    '''for point in pointList:
        x.append(point[0])
        y.append(point[1])'''

    '''#xCoords = dict(enumerate(x))
    #yCoords = dict(enumerate(y))'''

    def maxslopeIndex(index, pointNumbers)
        maxSlope = 0
        maxSlopeIndex = 0
        for i in range (index + 1, len(pointNumbers))
            slope = getSlope(index, i, pointNumbers)
            if slope >= maxSlope:
                maxSlope = slope
                maxSlopeIndex = i
        return maxSlopeIndex

    def minslopeIndex(index, pointNumbers)
        minSlope = 0
        minSlopeIndex = 0
        for i in range (index-1, 0, -1))
            slope = getSlope(index, i, pointNumbers)
            if slope <= maxSlope:
                minSlope = slope
                minSlopeIndex = i
        return minSlopeIndex

leftindex = 0
rightindex = len(pointNumbers) - 1

minIndex = pointNumbers[0]
maxIndex = pointNumbers[]
output = []
while True:
    if leftindex == rightindex:
        break
    nextleftIndex = maxslopeIndex(leftindex, pointNumbers)
    output.append(pointNumbers(nextleftIndex))
    leftindex = nextleftIndex
    if leftindex == rightindex:
        break
    nextrightIndex = minslopeIndex(rightindex, pointNumbers)
    output.append(pointNumbers(nextrightIndex))
    rightindex = nextrightIndex

leftindex = 0
rightindex = len(pointNumbers) - 1

while True:
    if leftindex == rightindex:
        break
    nextleftIndex = minslopeIndex(leftindex, pointNumbers)
    output.append(pointNumbers(nextleftIndex))
    leftindex = nextleftIndex
    if leftindex == rightindex:
        break
    nextrightIndex = maxslopeIndex(rightindex, pointNumbers)
    output.append(pointNumbers(nextrightIndex))
    rightindex = nextrightIndex
"""
