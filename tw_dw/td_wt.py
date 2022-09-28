import pandas as pd
df = pd.read_csv(
    't&d_wt.csv', names=['A', 'B'])
data = df.values.tolist()
print(data)
print(len(data[0]))
c1_tot = 0
c2_tot = 0
r1_tot = 0
r2_tot = 0
for i in range(2):
    for j in range(2):
        if (i == 0):
            r1_tot = r1_tot+int(float(data[i][j]))
        if (i == 1):
            r2_tot = r2_tot+int(float(data[i][j]))
        if (j == 0):
            c1_tot = c1_tot+int(float(data[i][j]))
        if (j == 1):
            c2_tot = c2_tot+int(float(data[i][j]))
print("Row 1 Total :", r1_tot)
print("Row 2 Total :", r2_tot)
print("Col 1 Total :", c1_tot)
print("Col 2 Total :", c2_tot)
print("")
for i in range(2):
    for j in range(2):
        if (i == 0):
            print("t_weight for data " +
                  str(data[i][j]) + " is: ", float((data[i][j]/r1_tot) * 100))
        if (i == 1):
            print("t_weight for data " +
                  str(data[i][j]) + " is: ", float((data[i][j]/r2_tot) * 100))
        if (j == 0):
            print("d_weight for data " +
                  str(data[i][j]) + " is: ", float((data[i][j]/c1_tot) * 100))
        if (j == 1):
            print("d_weight for data " +
                  str(data[i][j]) + " is: ", float((data[i][j]/c2_tot) * 100))
