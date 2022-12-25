# -----#
arithmetic = ["*", "/", "+", "-", "^"]
extra = ["if", "else"]
assign = ["="]
res = []
id = 0
temp1 = ""

expression = input("Enter expression(use space to separate each operator and operand) : ")
if expression[0] not in extra:
    x = expression.split()
    temp0 = x[-2]
    x[-2] = "$"
    end = len(x) - 2
    i = 2
    while x[i] != "$":
        if x[i] in arithmetic:
            if x[i + 1] == '-':
                temp = "T" + str(id) + " = " + x[i + 1] + x[i + 2]
                res.append(temp)
                for j in range(2):
                    del x[i + 1]
                x.insert(i + 1, "T" + str(id))
                id += 1
        i += 1
    x[-2] = temp0
    while len(x) > 3:
        if x[2] == '-':
            temp = "t" + str(id) + "=" + x[2] + x[3]
            res.append(temp)
            for i in range(2):
                del x[2]
            x.insert(2, "t" + str(id))
            id += 1

        elif '^' in x:
            oper = x.index('^')
            temp = "t" + str(id) + "=" + x[oper - 1] + x[oper] + x[oper + 1]
            res.append(temp)
            for i in range(3):
                del x[oper - 1]
            x.insert(oper - 1, "t" + str(id))
            id += 1
        elif '/' in x:
            oper = x.index('/')
            temp = "t" + str(id) + "=" + x[oper - 1] + x[oper] + x[oper + 1]
            res.append(temp)
            for i in range(3):
                del x[oper - 1]
            x.insert(oper - 1, "t" + str(id))
            id += 1
        elif '*' in x:
            oper = x.index('*')
            temp = "t" + str(id) + "=" + x[oper - 1] + x[oper] + x[oper + 1]
            res.append(temp)
            for i in range(3):
                del x[oper - 1]
            x.insert(oper - 1, "t" + str(id))
            id += 1
        elif '+' in x:
            oper = x.index('+')
            temp = "t" + str(id) + "=" + x[oper - 1] + x[oper] + x[oper + 1]
            res.append(temp)
            for i in range(3):
                del x[oper - 1]
            x.insert(oper - 1, "t" + str(id))
            id += 1
        elif '-' in x:
            oper = x.index('-')
            temp = "t" + str(id) + "=" + x[oper - 1] + x[oper] + x[oper + 1]
            res.append(temp)
            for i in range(3):
                del x[oper - 1]
            x.insert(oper - 1, "t" + str(id))
            id += 1
    for i in x:
       temp1+=str(i)

res.append(temp1)


for i in res:
    print(i)
