import matplotlib.pyplot as plt

# отрисовка данных файла, созданного в main.cpp
with open('output.txt', 'r') as f:
    X, Y = [], []
    lines = f.readlines()
    for line in lines:
        x, y, res = line.split()
        x = float(x)
        y = float(y)
        if res.endswith('\n'):
            res = res[:-1]
        if res == 'In':
            X.append(x)
            Y.append(y)
plt.scatter(X, Y)
plt.savefig('1.png')
