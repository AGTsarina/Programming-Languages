import numpy as np

A = np.array([[1, 2, 3, 4, 5],
[2, 3, 7, 10, 13],
[3, 5, 11, 16, 21],
[2, -7, 7, 7, 2],
[1, 4, 5, 3, 10]])
B = np.array([2, 12, 17, 57, 7])

print(np.linalg.solve(A, B))