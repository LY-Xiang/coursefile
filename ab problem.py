def max(l: "list") -> int:
    m = l[0]
    for i in l:
        if i > m:
            m = i
    return m

raw = input()
num = list()
op = list()

t = max([raw.find('+'), raw.find('-'), raw.find('*'), raw.find('/')])
while t != -1:
    num.append(float(raw[ :t]))
    del raw[ :t]
    op.append(raw[0])
    t = max([raw.find('+'), raw.find('-'), raw.find('*'), raw.find('/')])
num.append(float(raw))

t=max([op.find('*'), op.find('/')])
while t != -1:
    if op[t] == '*':
        num[t] *= num[t + 1]
    else:
        num[t] /= num[t + 1]
    del op[t]
    del num[t + 1]
    t=max([op.find('*'), op.find('/')])

t=max([op.find('+'), op.find('-')])
while t != -1:
    if op[t] == '+':
        num[t] += num[t + 1]
    else:
        num[t] -= num[t + 1]
    del op[t]                                              
    del num[t + 1]                                         
    t=max([op.find('+'), op.find('-')])

print('%.02f' % (int(num[0] * (10 ** 2) + 0.5) / (10 ** 2)))
