import pandas

data = pandas.read_csv("corelation_ip.csv")

A = data['A'].tolist()
B = data['B'].tolist()
C = data['C'].tolist()
D = data['D'].tolist()

n = len(A)
prob_A = 0
prob_B = 0
prob_A_B = 0
prob_C = 0
prob_B_C = 0
prob_D = 0
prob_C_D = 0

for i in range(n):
    if A[i] and B[i]:
        prob_A_B += 1
    if A[i] == 1:
        prob_A += 1
    if B[i] == 1:
        prob_B += 1


for i in range(n):
    if B[i] and C[i]:
        prob_B_C += 1
    if B[i] == 1:
        prob_B += 1
    if C[i] == 1:
        prob_C += 1
        

for i in range(n):
    if C[i] and D[i]:
        prob_C_D += 1
    if C[i] == 1:
        prob_C += 1
    if D[i] == 1:
        prob_D += 1        

ans = (prob_A_B)/(prob_A*prob_B)
ans1 = (prob_B_C)/(prob_B*prob_C)
ans2 = (prob_C_D)/(prob_C*prob_D)

print("Corelation coefficient of column A and B ", ans)
print("Corelation coefficient of column B and C ", ans1)
print("Corelation coefficient of column C and D ", ans2)
