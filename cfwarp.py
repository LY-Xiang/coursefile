from base64 import b64encode
from json import dumps

with open("result.csv", "r") as r, open("nekoray.txt", "w") as w:
    for l in r.readlines()[1:]:
        s = l.split(",")
        s, loss, delay = s[0].split(":"), s[1].split("%"), s[2].split(".")
        i = dumps(
            {
                "_v": 0,
                "addr": "127.0.0.1",
                "cmd": [""],
                "core": "internal",
                "cs": dumps(
                    {
                        "local_address": ["0.0.0.0/0", "::/0"],
                        "peerVGpublic_key": "bmXOC+F1FxEMF9dyiK2H5/1SUtzH0JuVo51h2wPfgyo=",
                        "private_key": "8CcDc9rZEliwTjXySP+geXHWLaQ77f2bk4LhzzXe8Fg=",
                        "server": s[0],
                        "server_port": int(s[1]),
                        "type": "wireguard",
                    }
                ),
                "mapping_port": 0,
                "name": f"CfWarp-{s[0]}-{delay[0]}-{loss[0]}",
                "port": 1080,
                "socks_port": 0,
            }
        )
    w.write(f"nekoray://custom#{b64encode(str(i).encode('utf-8')).decode('utf-8')}\n")
