from cs50 import get_int

#creates a mario code in python


def pyramidheight():
    while True:
        height = get_int("Enter height of pyramid here: ")
        if height >= 1 and height <= 8:
            break
    return height
    

def mariopyramid(height):
    for i in range(height):
        for j in range(i + 1, height):
            print(" ", end="")
        for k in range(0, i + 1):
            print("#", end="")
        print("  ", end="")
        for a in range(i + 1):
            print("#", end="")
        print("")
        
        
height = pyramidheight()
mariopyramid(height)
