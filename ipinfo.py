import requests as rq
import json as js

ip = input("ip:")
ipinfo = rq.get("https://ipinfo.io/" + ip + "?token=3bf40825617986").json()
print("IPinfo:\n" + js.dumps(ipinfo, sort_keys=True, indent=4))