import userSystemCore as uSC
from userSystemCUIMenu import *

uSC.loadData()
menu = ["Exit", "Sign up", "Sign in"]
while True:
    print("┌────┬───────────────────────────────────┐")
    for i in range(len(menu)):
        print(f"│{str(i): >4}┆{menu[i]: <35}│")
    print("└────┴───────────────────────────────────┘")
    choose = input("Your choose:")
    if choose == "0":  # Exit
        uSC.logOut()
        break
    elif choose == "1":
        if not uSC.isLogging():
            uSC.signUp()
        else:
            uSC.changePassword()
    elif choose == "2":
        if not uSC.isLogging():
            if uSC.signIn():
                menu = loggingMenu(menu)
        else:
            if uSC.logOut():
                menu = disLoggingMenu(menu)
    else:
        print(f"Unknown command:{choose}!")
uSC.saveData()
