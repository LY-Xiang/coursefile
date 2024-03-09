from os import system, path
import hashlib as hash
from base64 import standard_b64decode as b64decode, standard_b64encode as b64encode
from ast import literal_eval as eval


def cl():
    print("\033[0m", end="")


try:
    from Crypto.Cipher import AES
except ImportError:
    print("开始安装依赖库")
    system(
        "python -m pip install -i https://pypi.tuna.tsinghua.edu.cn/simple --upgrade pip"
    )
    system("python -m pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple")
    system(
            'python -m pip config set global.extra-index-url "https://mirrors.cernet.edu.cn/pypi/simple https://mirrors.cernet.edu.cn/pypi/web/simple https://mirrors.mirrorz.org/pypi/simple https://mirrors.mirrorz.org/pypi/web/simple"'
    )
    system("python -m pip install pycryptodome")
    print("\033[33m\033[1m请重新启动!\033[0m")
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
            print(f"\033[31m密码错误!你还有{i}次机会.\033[0m")
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
            print(f"\033[31m密码错误!你还有{i}次机会.\033[0m")
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


def cls():
    print("\033[2J\033[H", end="")


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
                    print("\033[32m修改成功.\033[0m")
                else:
                    print("\033[33m修改失败.\033[0m")
            else:
                print("\033[31m分数输入不正确!\033[0m")
        else:
            print("\033[31m小组不存在!\033[0m")
    elif choose == "3":
        group = input("输入小组代号(未有小组将被创建,已有小组将被删除): \033[1m")
        cl()
        if group.isalnum():
            if group in data:
                confirm = input("确认删除?(再次输入小组代号以确认): \033[1m")
                cl()
                if confirm == group:
                    data.pop(group)
                    print("\033[32m删除成功.\033[0m")
                else:
                    print("\033[33m删除失败.\033[0m")
            else:
                confirm = input("确认创建?(再次输入小组代号以确认): \033[1m")
                cl()
                if confirm == group:
                    data[group] = 0
                    print("\033[32m创建成功.\033[0m")
                else:
                    print("\033[33m创建失败.\033[0m")
        else:
            print("\033[31m小组代号不合规!(由字母和数字组成,30字符以内)\033[0m")
    elif choose == "4":
        if checkPassword(key):
            newkey = setPassword()
            if newkey != b"\0":
                key = newkey
                print("\033[32m密码修改成功.\033[0m")
            else:
                print("\033[31m密码修改失败.\033[0m")
        else:
            print("\033[31m密码修改失败.\033[0m")
    else:
        print("\033[31m错误的选项,请重新输入!\033[0m")
    pause()
