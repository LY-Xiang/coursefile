for times in range(1,10):
    try:
        paswordinput("Password plz")
    except:
        if times >= 5:
            print("You have been wrong with", times, "times")
        print("Wrong password")
    else:
        if password == 1234:
            print("Password Successful")
            break
        if times >= 5:
            print("You have been wrong with",times,"times")
        print("Wrong password")
else:
    print("Failed")

if password == 1234:
    print("Welcome to caluanlar")
    none = True
    while none:
        try:
            a=int(input("The first number"))
            b=int(input("The seconed number"))
            c=int(input("The law number,\n 1.+ 2.- 3.* 4./ 5.quit"))
        except:
            print("Error")
            continue
        if c == 1:
            d=a+b
            print("The answer is",d)
        elif c == 2:
            d=a-b
            print("The answer is",d)
        elif c == 3:
            d = a*b
            print("The answer is",d)
        elif c == 4:
            if b != 0:
                d= a/b
                print("The answer is",d)
            else:
                print("The second number can't be 0")
        elif c==5:
            none=False
        else:
            print("error")
