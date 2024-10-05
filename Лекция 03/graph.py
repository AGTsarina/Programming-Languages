import matplotlib.pyplot as plt

with open('output.txt', 'r') as f:
    lines = f.readlines()
    eps, N1, N2, N3 = [], [], [], []
    for line, i in zip(lines, range(len(lines))):
        e, n1, n2, n3 = map(float, line.split())
        eps.append(e)
        N1.append(n1)
        N2.append(n2)
        N3.append(n3)

    plt.plot(eps, N1)
    plt.plot(eps, N2)
    plt.plot(eps, N3)
    plt.xscale('log')
    plt.show()