from tcping import Ping
l=open('tcpdns.in','r').read().split()
str=""
for dns in l:
    if Ping(dns,53):
        str+='"'+dns+'":53,\n'
open('tcpdns.out','w').write(str)