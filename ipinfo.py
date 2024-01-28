import requests as rq

ip=input("ip:")
ipinfo=rq.get("https://ipinfo.io/"+ip+"?token=3bf40825617986").json()
print(ipinfo)