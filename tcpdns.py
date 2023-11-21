from tcping import Ping
str=""
while True:
    dns=input()
    if dns=='0':
        break
    if Ping(dns,53):
        str+=dns+'\n'
print(str)