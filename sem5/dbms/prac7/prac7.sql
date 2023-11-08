SELECT * FROM ProductName NATURAL JOIN Customers;

SELECT * FROM ProductName INNER JOIN Customers ON ProductName.CustomerID = Customers.CustomerID;

SELECT * FROM ProductName INNER JOIN Customers ON ProductName.ProductName = Customers.CustomerName;

SELECT * FROM ProductName NATURAL JOIN Customers;

SELECT * FROM ProductName INNER JOIN Customers ON ProductName.ProductName = Customers.Country;

SELECT * FROM ProductName LEFT JOIN Customers ON ProductName.ProductName = Customers.Country;

SELECT * FROM ProductName RIGHT JOIN Customers ON ProductName.ProductName = Customers.Country;

