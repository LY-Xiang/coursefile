from math import e


def encodestring(str: "str") -> str:
    from base64 import b64encode

    return b64encode(str.encode()).decode()


def decodestring(str: "str") -> str:
    from base64 import b64decode

    return b64decode(str.encode()).decode()


def ena64(pwd: "bytes", str: "str") -> str:
    from Crypto.Cipher import AES
    from base64 import b64encode
    data=str.encode()
    while len(data) % 16 != 0:
        data += b'\x00'
    #print(data)
    return b64encode(AES.new(pwd, AES.MODE_ECB).encrypt(data)).decode()


def dea64(pwd: "bytes", str: "str") -> str:
    from Crypto.Cipher import AES
    from base64 import b64decode
    #print(AES.new(pwd.encode(), AES.MODE_ECB).decrypt(b64decode(str.encode())).decode())
    return AES.new(pwd, AES.MODE_ECB).decrypt(b64decode(str.encode())).decode()


def aeseed(len:"int")->bytes:
    from random import getrandbits
    seed=b''
    for i in range(len):
        seed+=bytes([getrandbits(8)])
    return seed
#print(enaes("jYTnTZ+zBRnWjJuaeeewNle/qsA714PT", "11ff4514191ergdrgrgrdfrdhggggg9810"))
#print(aeseed(32))