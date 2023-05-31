#4.1
mean = 22
sd = 5

pnorm(27.5, mean, sd) - pnorm(16.2, mean, sd)
pnorm(29, mean, sd, lower.tail = FALSE)
pnorm(17, mean, sd)
pnorm(15, mean, sd) + pnorm(25, mean, sd, lower.tail = FALSE)

#4.2
p = 0.5
n = 60
dbinom(c(20, 25, 30), prob = p, size = 60)
pbinom(20, n, p)
pbinom(30, n, p) - pbinom(20, n, p)

#4.3
mean = 7
ppois(4, 7)
ppois(10, 7, lower.tail = FALSE)
ppois(16, 7) - ppois(4, 7)

#4.4
n = 10
p = 0.6
dbinom(5, n, p)

#4.5
n = 3
p = 0.5
dbinom(2, n, p)

#4.6
n = 5
p = 0.4
dbinom(0:5, n, p)

#4.7
n = 10
p = 0.45
dbinom(8, n, p)
pbinom(4, n, p, lower.tail = FALSE)
pbinom(6, n, p)

#4.8
l = 7
dpois(0:3, l)
dpois(5, l)
ppois(4, l, lower.tail = FALSE)

#4.9
m = 6.4
sd = 2.7
pnorm(5, m, sd) - pnorm(4, m, sd)
pnorm(2, m, sd, lower.tail = FALSE)
pnorm(7.2, m, sd)
pnorm(3, m, sd) + pnorm(9, m, sd, lower.tail = FALSE)

#4.10
m = 17.46
sd = sqrt(375.67)
pnorm(19, m, sd, lower.tail = FALSE)



