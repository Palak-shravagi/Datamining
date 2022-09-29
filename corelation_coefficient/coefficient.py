import pandas

data = pandas.read_csv("corelation_ip.csv")

A = data['A'].tolist()
B = data['B'].tolist()
n = len(A)
prob_A = 0
prob_B = 0
prob_A_B = 0
for i in range(n):
    if A[i] and B[i]:
        prob_A_B += 1
    if A[i] == 1:
        prob_A += 1
    if B[i] == 1:
        prob_B += 1

ans = (prob_A_B)/(prob_A*prob_B)
print("Corelation coefficient is ", ans)
