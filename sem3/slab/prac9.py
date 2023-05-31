from sympy import *

a = Rational(5, 8)
print("value of a is :" + str(a))
b = Integer(3.579)
print("value of b is :" + str(b))

# you can't get any numerical value
p = pi**3
print("value of p is :" + str(p))
# evalf method evaluates the expression to
# a floating-point number
q = pi.evalf()
print("value of q is :" + str(q))
# equivalent to e ^ 1 or e ** 1
r = exp(1).evalf()
print("value of r is :" + str(r))
s = (pi + exp(1)).evalf()
print("value of s is :" + str(s))
rslt = oo + 10000
print("value of rslt is :" +
str(rslt))
if oo > 9999999 :
    print("True")
else:
    print("False")
# import everything from sympy module
from sympy import *
x = Symbol('x')
y = Symbol('y')
z = (x + y) + (x-y)
print("value of z is :" + str(z))
# import everything from sympy module
from sympy import *
# make a symbol
x = Symbol('x')
# make the derivative of sin(x)*e ^ x
ans1 = diff(sin(x)*exp(x), x)
print("derivative of sin(x)*e ^ x :", ans1)
# Compute (e ^ x * sin(x)+ e ^ x *cos(x))dx
ans2 = integrate(exp(x)*sin(x) +exp(x)*cos(x), x)
print("indefinite integration is :", ans2)
# Compute definite integral of sin(x ^ 2)dx
# in b / w interval of ? and ?? .
ans3 = integrate(sin(x**2), (x, -oo, oo))
print("definite integration is :", ans3)
# Find the limit of sin(x) / x given x tends to 0
ans4 = limit(sin(x)/x, x, 0)
print("limit is : ", ans4)
# Solve quadratic equation like, example :x ^ 2?2 = 0
ans5 = solve(x**2 - 2, x)
print("roots are : ", ans5)