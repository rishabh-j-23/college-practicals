-- Active: 1691209649688@@127.0.0.1@3306
CREATE TABLE Customers (
    ID INT PRIMARY KEY,
    C_NAME VARCHAR(255),
    AGE INT,
    C_ADDRESS VARCHAR(255),
    SALARY DECIMAL(10, 2)
);

INSERT INTO customers (ID, C_NAME, AGE, C_ADDRESS, SALARY)
VALUES
    (1, 'Ramesh', 32, 'Ahmedabad', 2000.00),
    (2, 'Khilan', 25, 'Delhi', 1500.00),
    (3, 'Kaushik', 23, 'Kota', 2000.00),
    (4, 'Chaitali', 25, 'Mumbai', 6500.00),
    (5, 'Hardik', 27, 'Bhopal', 8500.00),
    (6, 'Komal', 22, 'MP', 4500.00),
    (7, 'Muffy', 24, 'Indore', 10000.00);

CREATE VIEW CustomerNameAndAge AS
SELECT C_Name AS CustomerName, AGE
FROM CUSTOMERS;

UPDATE CustomerNameAndAge
SET AGE = 25
WHERE CustomerName= 'KOMAL';

DROP VIEW customernameandage;

SELECT * FROM CustomerNameAndAge;


