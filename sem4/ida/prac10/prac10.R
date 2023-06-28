df = read.csv("C:/Users/Rishabh/codes/college/college-practicals/sem4/ida/prac10/dataset/House_Rent_Dataset.csv")
df
summary(df)
x_train = df$Rent[0:40]
y_train = df$Size[0:40]
barplot(df$Rent[0:40], df$Size[0:40])
plot(x_train, y_train)
barplot(x_train)
barplot(y_train)

hist(x_train)
hist(y_train)

rent = df$Rent
#let sample size is 100
#  H0 : average rent of the house rent is 11042.5
#  H1 : average rent of house rent is less than 11042.5
n = 40
alpha = 0.05
xbar = mean_sample = mean(x_train)
xbar
x = mean_pop = mean(rent)
x
z_obs = (xbar - x)/(sd/sqrt(n))
z_obs
z_crit = qnorm(1- alpha)
c(-z_crit, z_crit)

#for a the sample, null hypothesis is rejected ie H1 is accepted

lm = lm(formula = y_train ~ x_train)
head(df)
predict(lm , 10000)
