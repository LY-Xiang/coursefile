with open("result.csv", "r") as r, open("nekoray.txt") as w:
    for l in r.readlines()[1:]:
        s = l.split(",")[0].split(":")
        w = {
            "local_address": ["0.0.0.0/0", "::/0"],
            "peer_public_key": "bmXOC+F1FxEMF9dyiK2H5/1SUtzH0JuVo51h2wPfgyo=",
            "private_key": "8CcDc9rZEliwTjXySP+geXHWLaQ77f2bk4LhzzXe8Fg=",
            "server": s[0],
            "server_port": int(s[1]),
            "type": "wireguard",
        }

    pass
