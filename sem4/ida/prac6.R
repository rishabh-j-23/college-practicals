#6.1
sample_mean <- 13000
population_mean <- 14500  
population_sd <- 2100
sample_size <- 25
alpha <- 0.01

z <- (sample_mean - population_mean) / (population_sd / sqrt(sample_size))
z
z.alpha.half <- qnorm(1-alpha/2)
z.alpha.half
p_value <- pnorm(z)
p_value

#6.2
sample_mean <- 83 
population_mean <- 70 
sample_sd <- 12.5
sample_size <- n <- 22 

alpha <- 0.025

z <- (sample_mean - population_mean) / (sample_sd/sqrt(sample_size))
z
z.alpha.half = qt(1-alpha, df=n-1)
z.alpha.half
p_value <- 1 - pnorm(z)
p_value

#6.3
sample_mean <- 94.3  
population_mean <- 100  
sample_sd <- 8.4  
sample_size <- 6  

alpha <- 0.05

z <- (sample_mean - population_mean) / (sample_sd / sqrt(sample_size))
z
z.alpha.half = qt(1 - alpha, df=sample_size - 1)
z.alpha.half
p_value <- pnorm(z)
p_value

#6.4
sample_mean <- 52  
population_mean <- 65  
sample_variance <- 4.2  
sample_size <- 25  

alpha <- 0.01

z <- (sample_mean - population_mean) / sqrt(sample_variance / sample_size)
z
critical_z <- qt(1 - alpha/2, df=25-1)
critical_z
pnorm(z)

