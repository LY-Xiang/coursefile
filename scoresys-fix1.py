from base64 import standard_b64encode as en
with open('scoresys.dat','r') as f:
    k,d=map(lambda i:i[:-1],f.readlines())
with open('scoresys.dat','w') as f:
    f.write(f'{en(b'114514hfsz1919810').decode()}\n{d}\n')