import math
import operator
import string
def eD(i1, i2, len):
        dist= 0
        for x in range(len):
                dist += pow((i1[x] - i2[x]), 2)
        return math.sqrt(dist)


def getResponse(neighbors):
        classVotes = {}
        
        for x in range(len(neighbors)):
                response = neighbors[x][0][-1]
                if response in classVotes:
                        classVotes[response] += 1

                else:
                        classVotes[response] = 1

        sortedVotes = sorted(classVotes.iteritems(), key=operator.itemgetter(1), reverse=True)

        print sortedVotes

        return sortedVotes[0][0]

def getAccuracy(testSet, predictions):
        correct = 0
        for x in range(len(testSet)):
                if testSet[x][-1] == predictions[x]:
                        correct += 1
        return (correct/float(len(testSet))) * 100.0


def getNeighbors(trainingSet, testInstance, k):
        distances = []
        length = len(testInstance)-1
        for x in range(len(trainingSet)):
                dist = eD(testInstance, trainingSet[x], length)
                distances.append((trainingSet[x], dist))
        distances.sort(key=operator.itemgetter(1))

        neighbors = []
        for x in range(k):
                neighbors.append(distances[x])

        return neighbors


def main():
        # prepare data
        
        file_obj=open("dataset/weights/weights.txt",'r')
        c=file_obj.read()
        a=string.split(c,'\n')
      #  print a
        for u in a:
            if u=='':
                del u
        d=[]
        trainingSet=[]
        for j in a :
            #print j
            if j=='':
                continue
            v=string.split(j,',')
       #     print v
            d=[]
            for i in range(0,len(v)-1):
                
                    #print j[i]
                d.append(string.atof(v[i]))
            d.append(v[len(v)-1])
       #     print d 
            trainingSet.append(d)

       # print trainingSet
        
        testSet=[[2411.54,8365.85,6744.63,-231.478,744.896,1049.53,2434.3,2901.86,3012.83,-2013.86,-109.429,-1793.89,-250.734,-1090.49,-1246.61,"1"],
[1919.36,6688.57,5684.48,521.941,293.341,1142.62,2359.05,1785.61,1862.61,-2028.31,-217.632,-1501.62,-760.057,-1890.04,-178.406,"2"],
[600.965,7801.1,3845.3,-116.957,-1446.54,2153.13,1074.36,2540.71,2859.12,-545.17,466.044,-2179.57,620.105,-1856.48,-106.937,"3"],
[745.943,7132.74,5064.73,-1769.6,-1211.77,2885.23,1449.77,2918.48,1567.2,-2356.15,-100.728,-1641.2,-1048.46,-935.731,-390.359,"4"],
[1034.01,8714.69,4405.02,-2111.04,94.3337,1791.95,1529.26,1963,2964.68,-2496.8,-78.2933,-2528.31,60.8306,-1483.22,-385.706,"5"],
[-1105.03,9484.04,4164.84,-1503.71,1893.57,2887.57,834.622,2329.81,2825.59,-2213.78,-180.141,-1884.35,-374.791,-1683.64,-276.224,"6"],
[-742.835,7623.1,5181.46,1413.27,340.319,1693.02,-380.82,2042.77,2893.86,-2542.44,205.503,-2346.28,-577.551,-1046.77,-277.942,"7"],
[-310.548,6962.33,7437.09,-885.735,-78.5295,2383.68,1484.73,3810.51,2709.08,-3060.37,804.27,-2367.31,-210.179,-1452.6,-123.927,"8"],
[-573.441,7117.77,2851.29,-736.859,-539.635,2548.91,2436.69,3039.99,2268.41,-2617.21,-316.294,-2694.69,66.9475,-475.831,-87.8414,"9"],
[-2183.19,6325.95,3933.38,-198.029,624.003,272.911,2181.53,3215.74,2327.52,-1165.56,-123.302,-2764.51,-379.21,-967.941,-732.688,"10"],
[762.253,4999.57,6268.98,-958.394,-174.317,3292.66,415.135,2915.18,1880.57,-1598.32,-1187.41,-2359.89,-652.114,-638.024,-270.432,"11"],
[2034.99,7757.86,5056.8,-1451.67,-1286.64,401.16,687.644,2437.35,2442.6,-3131.3,-1025.23,-1542.42,584.263,-1449.4,39.8447,"12"],
[3312.23,9185.08,5441.28,-1838.56,265.844,1496.73,477.395,2829.34,1838.37,-1481.56,124.405,-2785.15,-727.597,-556.513,-75.9551,"13"],
[4414.56,5936.36,3221.19,-60.4323,1031.49,2015.63,1556.07,2934.87,2988.87,-2688.7,179.394,-1625.93,-331.621,-941.859,1421.07,"14"],
[1025.54,6526.88,5060.86,568.841,1036.17,3004.01,1848.79,1642.57,1852.23,-2125.89,214.79,-1739.21,973.735,-387.075,-510.394,"15"]]
        # generate predictions
        predictions=[]
        k = 7
        for x in range(len(testSet)):
                neighbors = getNeighbors(trainingSet, testSet[x], k)
                result = getResponse(neighbors)
                predictions.append(result)
                print('> predicted=' + "Person"+repr(result))
        accuracy = getAccuracy(testSet, predictions)
        print('Accuracy: ' + repr(accuracy) + '%')

main()
