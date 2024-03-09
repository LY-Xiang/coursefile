from os import system, path
import hashlib as hash
from base64 import standard_b64decode as b64decode, standard_b64encode as b64encode
from ast import literal_eval as eval
from platform import system as sys

if "win" in sys().lower():
    from ctypes import windll

    k = windll.kernel32
    k.SetConsoleMode(k.GetStdHandle(-11), 7)


def csi(e, *c):
    print(end="\033[")
    if c != ():
        print(c[0], end="")
        c = c[1:]
        for i in c:
            print(end=";")
            print(i, end="")
    print(e, end="")


def color(fore: "int" = 39, back: "int" = 49):
    csi("m", fore, back)


def style(style: "int" = 0):
    csi("m", style)


def cl():
    style(0)


def color256(mode: "int", r: "int", g: "int", b: "int"):
    print("m", mode, 2, r, g, b)


def cls():
    csi("J", 2)
    csi("H")


try:
    from Crypto.Cipher import AES
except ImportError:
    print("开始安装依赖库")
    system(
        "python -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple --upgrade pip"
    )
    system(
        "python -m pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple"
    )
    system(
        'python -m pip config set global.extra-index-url "https://mirrors.cernet.edu.cn/pypi/simple https://mirrors.cernet.edu.cn/pypi/web/simple https://mirrors.mirrorz.org/pypi/simple https://mirrors.mirrorz.org/pypi/web/simple"'
    )
    system("python -m pip install pycryptodome")
    color(33)
    style(1)
    print("请重新启动!")
    cl()
    exit(0)


def setPassword() -> bytes:
    cls()
    password = input("设置密码: \033[1m")
    cl()
    for i in range(2, -1, -1):
        check = input("确认密码: \033[1m")
        cl()
        if check == password:
            return hash.pbkdf2_hmac(
                "sha256", password.encode(), b"114514hfsz1919810", 500_000
            )
        else:
            color(31)
            print(f"密码错误!你还有{i}次机会.")
            cl()
    return b"\0"


def checkPassword(key: "bytes") -> bool:
    cls()
    for i in range(2, -1, -1):
        check = hash.pbkdf2_hmac(
            "sha256", input("输入密码: \033[1m").encode(), b"114514hfsz1919810", 500_000
        )
        cl()
        if check == key:
            return True
        else:
            color(31)
            print(f"密码错误!你还有{i}次机会.")
            cl()
    return False


def en(key: "bytes", dat: "str") -> str:
    dat = dat.encode()
    while len(dat) % 16 != 0:
        dat += b"\x00"
    return b64encode(AES.new(key, AES.MODE_ECB).encrypt(dat)).decode()


def de(key: "bytes", dat: "str") -> str:
    return AES.new(key, AES.MODE_ECB).decrypt(b64decode(dat.encode())).decode()


if not path.exists("scoresys.dat"):
    key = setPassword()
    if key != b"\0":
        file = open("scoresys.dat", "w")
        file.write(b64encode(key).decode())
        file.write("\n")
        file.write(en(key, str({})))
        file.close()
    else:
        exit(-1)
file = open("scoresys.dat", "r")
key = b64decode(file.readline()[:-1].encode())
if not checkPassword(key):
    exit(-1)


def pause():
    input("按Enter键继续...")


data = de(key, file.readline()).encode()
while data[-1] == 0:
    data = data[:-1]
data = eval(data.decode())
menu = ["保存并退出", "分数查询", "分数修改", "小组修改", "修改密码"]
while True:
    cls()
    print("┌────┬──────────────────────────────┐")
    for i in range(len(menu)):
        print(f"│{i: > 4d}┆{menu[i]:\u3000<15}│")
    print("└────┴──────────────────────────────┘")
    choose = input("请选择: \033[1m")
    cl()
    cls()
    if choose == "0":
        file = open("scoresys.dat", "w")
        file.write(b64encode(key).decode())
        file.write("\n")
        file.write(en(key, str(data)))
        exit(0)
    elif choose == "1":
        k = 0
        print("┌────┬──────────────────────────────┬─────┐")
        for i, j in sorted(data.items(), key=lambda kv: (kv[1], kv[0])):
            k = k + 1
            print(f"│{k: > 4d}┆{i: ^30}┆{j: < 5d}│")
        print("└────┴──────────────────────────────┴─────┘\n")
    elif choose == "2":
        group = input("输入小组代号: \033[1m")
        cl()
        if group in data:
            score = input("输入加/减分(正数加分,负数减分): \033[1m")
            cl()
            if (score if score[0] != "-" else score[1:]).isdecimal():
                confirm = input("确认修改?(再次输入小组代号以确认): \033[1m")
                cl()
                if confirm == group:
                    data[group] += int(score)
                    color(32)
                    print("修改成功.")
                else:
                    color(33)
                    print("修改失败.")
            else:
                color(31)
                print("分数输入不正确!")
        else:
            color(31)
            print("小组不存在!")
    elif choose == "3":
        group = input("输入小组代号(未有小组将被创建,已有小组将被删除): \033[1m")
        cl()
        if group.isalnum():
            if group in data:
                confirm = input("确认删除?(再次输入小组代号以确认): \033[1m")
                cl()
                if confirm == group:
                    data.pop(group)
                    color(32)
                    print("删除成功.")
                else:
                    color(33)
                    print("删除失败.")
            else:
                confirm = input("确认创建?(再次输入小组代号以确认): \033[1m")
                cl()
                if confirm == group:
                    data[group] = 0
                    color(32)
                    print("创建成功.")
                else:
                    color(33)
                    print("创建失败.")
        else:
            color(31)
            print("小组代号不合规!(由字母和数字组成,30字符以内)")
    elif choose == "4":
        if checkPassword(key):
            newkey = setPassword()
            if newkey != b"\0":
                key = newkey
                color(32)
                print("密码修改成功.")
            else:
                color(33)
                print("密码修改失败.")
        else:
            color(31)
            print("密码修改失败.")
    else:
        color(31)
        print("错误的选项,请重新输入!")
    cl()
    pause()
