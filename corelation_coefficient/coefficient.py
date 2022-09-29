import pandas

data = pandas.read_csv("corelation_ip.csv")
print(type(data))


X = data['A'].tolist()
# B = data['B'].tolist()
# C = data['C'].tolist()
# D = data['D'].tolist()

n = len(X)
# print(data.shape)
# print(len(data.axes[1]))
print("number of column present ", len(data.axes[1]))

col1 = input("enter the index of column 1 : ")
col2 = input("enter the index of column 2 : ")
# A = df.iloc[col1,col1+1]
# B = df.iloc[col2,col2+1]


col1 = data.iloc[:, int(col1)-1]
col2 = data.iloc[:, int(col2)-1]


prob_A = 0
prob_B = 0
prob_A_B = 0

for i in range(n):
    if col1[i] and col2[i]:
        prob_A_B += 1
    if col1[i] == 1:
        prob_A += 1
    if col2[i] == 1:
        prob_B += 1

ans = (prob_A_B)/(prob_A*prob_B)

print("Corelation coefficient of columns is : ", ans)
