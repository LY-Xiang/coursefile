def loggingMenu(menu: "list") -> list:
    menu[1] = "Change password"
    menu[2] = "Log out"
    return menu


def disLoggingMenu(menu: "list") -> list:
    menu[1] = "Sign up"
    menu[2] = "Sign in"
    return menu
