from tcping import Ping
l=open('tcpdns.in','r').read().split()
str=""
for dns in l:
    p=Ping(dns,53,3)
    p.ping(1)
    if p.__dict__['_successed']:
        str+='"'+dns+':53",\n'
open('tcpdns.out','w').write(str)