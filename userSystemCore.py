dataBase = {}
logUser = ""


def isLogging() -> bool:
    return logUser != ""


def checkPassword(data: "str") -> bool:
    for i in range(2, -1, -1):
        check = input("Confirm the password:")
        if check == data:
            return True
        else:
            print(f"Wrong password!You have only {i} chance(s).")
    return False


def checkUser() -> str:
    for i in range(2, -1, -1):
        userName = input("Your name:")
        if userName in dataBase:
            return userName
        else:
            print(f"Wrong username!You have only {i} chance(s).")
    return ""


def signUp() -> bool:
    userName = input("Your name:")
    password = input("Your password:")
    if checkPassword(password):
        global dataBase
        dataBase[userName] = password
        print(f"Sign up:SUCCESS({userName}:{password})")
        return True
    else:
        print("Sign up:FAILED")
        return False


def signIn() -> bool:
    userName = checkUser()
    if userName != "":
        if checkPassword(dataBase[userName]):
            global logUser
            logUser = userName
            print(f"Hello,{logUser}!")
            return True
        else:
            print("Sign in:FAILED")
            return False
    else:
        return False


def logOut() -> bool:
    if isLogging():
        global logUser
        print(f"Goodbye,{logUser}!")
        logUser = ""
        return True
    else:
        return False


def changePassword() -> bool:
    if checkPassword(dataBase[logUser]):
        newPassword = input("New password:")
        if checkPassword(newPassword):
            dataBase[logUser] = newPassword
            return True
        else:
            print("Change password:FAILED")
            return False
    else:
        print("Change password:FAILED")
        return False


def loadData() -> bool:
    try:
        from dncode import dea64
        global dataBase
        dataBase = eval(dea64(b"AWPMB6du2tjwwIsgH4RQHoUu3a2viSc3", open("dataBase.dat", "r").read()))
    except:
        print("Load data:FAILED")
        return False
    else:
        return dataBase is not {}


def saveData() -> bool:
    try:
        from dncode import ena64

        open("dataBase.dat", "w").write(
            ena64(b"AWPMB6du2tjwwIsgH4RQHoUu3a2viSc3", str(dataBase))
        )
    except:
        print("Save data:FAILED")
        return False
    else:
        return dataBase is not {}