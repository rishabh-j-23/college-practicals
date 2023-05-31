barplot(airquality$Ozone, main = 'Ozone Concentration in Air'
        ,xlab = 'Ozone levels' , horiz = TRUE )

barplot(airquality$Ozone, main = 'Ozone Concentration in Air'
        ,xlab = 'Ozone levels' , horiz = FALSE )

boxplot(airquality$Wind, main = "Average wind speed", xlab = "miles per hour"
, ylab = "wind" , col = "deepskyblue3",border = "red" , horizontal = TRUE , notch = TRUE)

boxplot(airquality$Wind, main = "Average wind speed", xlab = "miles per hour"
, ylab = "wind" , col = "darkorchid3",border = "red" , horizontal = TRUE , notch = FALSE)

boxplot(airquality$Wind, main = "Average wind speed", xlab = "miles per hour"
, ylab = "wind" , col = "darkturquoise",border = "red" , horizontal = FALSE , notch = TRUE)


boxplot(airquality$Wind, main = "Average wind speed", xlab = "miles per hour"
, ylab = "wind" , col = "orange1",border = "red" , horizontal = FALSE , notch = FALSE)

hist(airquality$Temp , main = "lain Airport \ Maximum Temp(Daily)", xlab = "temparature (F)"
  , xlim = c(40,120) , col = "royalblue3" , freq = FALSE )

hist(airquality$Temp , main = "lain Airport \ Maximum Temp(Daily)", xlab = "temparature (F)"
  , xlim = c(40,120) , col = "chartreuse3" , freq = TRUE )

plot(airquality$Ozone , airquality$Month , main = "Scatter plot"
,xlab = "Ozone Concentration per Billion" , ylab = "Month of oberservation" , pch = 19)

x <- c(20 , 63, 54 ,33)
labels <- c("Mumbai", "Pune" , "Goa" , "Madras")

piePercentage <- round(100 * x/ sum(x), 1)

pie(x,labels = piePercentage , main = "City pie chart",
    col = rainbow(length(x)))

legend("topright", labels ,cex = 0.5 , fill = rainbow(length(x)) )

