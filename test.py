#declaring variables
num = 4
print(num)

num1 =3.9754
print(num1)

num2 = "strings"
print(num2)

#list
num3 = []
num3.append(21)
num3.append(34.532)
num3.append("just add something")
print(num3)

#dictionary
num4 = []
num4 = {1: 'get',2:'to',3:'know',4:'about',5:'dict'}
print(num4)

#tuples
num5 = ("add","multiple","records")
print(num5)

#sets
num6 = set(["multiple","words","will","combine","into","single","words"])
print(num6)

#getting input from user
num7 = input("Enter your name:")
print("My name is ",num7)

#accepting integer from user
num8 = int(input("your age:"))
print("i am ",num8,"years old...")

#selection or condition statement
num9 = 5
if(num9 > 4):
    print("Num1 is bigger than num2")
elif(num9 == 4):
    print("Num1 and Num2 are equal")
else:
    print("Num2 is bigger than num1")

#functions
def op():
    print("just testing the functions")

op()#calling function

#main function

def Main():

    n1 = int(input("Enter the first number:"))
    n2 = int(input("Enter the second number:"))
    n = n1 + n2
    

    print(n)

if __name__=="__main__":
   Main()    

#iteration

for n in range(5):
    print(n)

m = 0
while(m < 5):
    print("checked...")
    m= m + 1    

#multiple inputs using split

name , age = input("Enter two values:"). split()
print("my name is ",name)
print("i am ", age,"years old.....")

#encoding

string = "ooohhh"
tobytes = string.encode('utf-8')
print (tobytes)
string = tobytes.decode('utf-8')
print (string)

#decode

string = "\u20B9"
print (string)
tobytes = string.encode('utf-8')
print (tobytes)
string = tobytes.decode('utf-8')
print (string)
