y = sp = c(89.5,69.9,83.1,56.9,67.6,82.5,122.3,78.3,118.9,87.6,112.6,123.8,78.5,74.3,74.8)
x = size = c(20.0,13.8,20.5,12.5,17.0,14.3,23.5,15.5,22.3,20.2,22.0,24.019,12.3,14.0,16.7)

summary(sp)
summary(size)
plot = plot(size, sp)

df=data.frame(size, sp)
lm = lm(y ~ x)
b = lm$coefficients[1]
a = lm$coefficients[2]
c(a, b)

df2=data.frame(x = 21.8)
predict(lm, df2)


x1=c(45,42,44,45,43,46,44,45,44,43)
x2=c(16,14,15,13,13,14,16,16,15,15)
x3=c(71,70,72,71,75,74,76,69,74,73)
y=c(29,24,27,25,26,28,30,28,28,27)

df = data.frame(x1=48, x2=14,x3=72)
lm = lm(y ~ x1 + x2 + x3)
predict(lm, df)









