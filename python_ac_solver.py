xj = list(map(lambda x:int(x),input().split(" ")))
n = xj[0]
m = xj[1]

deck1 = [(1,-1) for x in range(0,n)]
# upper2 = ["a","c","e","g","i","k"]
# lower2 = ["b","d","f","h","j","l"]

#uncomment this
upper2 = list(map(lambda x:int(x),input().split(" ")))
lower2 = list(map(lambda x:int(x),input().split(" ")))

deck2 = []
for i in range(0,len(upper2)):
    deck2.append((upper2[i],lower2[i]))

def move1(L,R):
    # print(deck2)
    for i in range(L-1,R):
        deck2[i] = deck2[i][::-1]
    
    if (R-L)%2 != 0:
        R2 = R-1
        for i in range(L-1,int((R-L)/2)+2):
            # print(i)
            deck2[i],deck2[R2] = deck2[R2],deck2[i]
            R2 -=1
    else:
        R2 = R-1
        for i in range(L-1,int((R-L)/2)+1):
            # print(i)
            deck2[i],deck2[R2] = deck2[R2],deck2[i]
            R2 -=1

    # print(deck2)

def move2(R):
    L = 1
    for i in range(L-1,R):
        deck1[i] = deck1[i][::-1]
    if (R-L)%2 != 0:
        R2 = R-1
        for i in range(L-1,int((R-L)/2)+2):
            # print(i)
            deck1[i],deck1[R2] = deck1[R2],deck1[i]
            R2 -=1
    else:
        R2 = R-1
        for i in range(L-1,int((R-L)/2)+1):
            # print(i)
            deck1[i],deck1[R2] = deck1[R2],deck1[i]
            R2 -=1

    # print(deck1)

def move3(a,b,c,d):
    # print(deck1)
    # print(deck2)
    sm = 0
    while(c!=d+1 and a!=b+1):
        # print(deck1[c-1][0]*deck2[a-1][0])
        sm += deck1[c-1][0]*deck2[a-1][0]
        c+=1
        a+=1
    # print(sm)
    return sm
answers = []

for i in range(0,m):
    curMov = list(map(lambda x:int(x),input().split(" ")))
    if len(curMov) == 5:
        answers.append(move3(curMov[1],curMov[2],curMov[3],curMov[4]))
    elif len(curMov) == 3:
        move1(curMov[1],curMov[2])
    elif len(curMov) == 2:
        move2(curMov[1])

for i in answers:
    print(i)
