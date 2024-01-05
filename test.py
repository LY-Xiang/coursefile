for times in range(1,10):
    password = int(input("Password plz"))
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
        if c == 2:
            d=a-b
            print("The answer is",d)
