-- Active: 1691209649688@@127.0.0.1@3306@prac1b
SELECT SUM(AMOUNT) FROM borrow;
SELECT SUM(AMOUNT) FROM deposit;
SELECT SUM(AMOUNT) FROM deposit WHERE BNAME='ANDHERI';
SELECT SUM(AMOUNT) FROM DEPOSIT WHERE ADATE > '1996-01-01';

SELECT * from deposit;
SELECT * from customer;
SELECT BNAME
    FROM BRANCH;
SELECT SUM(AMOUNT) 
FROM DEPOSIT
WHERE BNAME IN (
    SELECT BNAME
    FROM BRANCH
    WHERE CITY='NAGPUR'
);

SELECT COUNT(*) FROM customer;
SELECT COUNT(*) FROM branch;
SELECT MAX(AMOUNT) FROM borrow WHERE `BNAME`='VRCE';
SELECT SUM(AMOUNT) FROM deposit WHERE BNAME IN (
    SELECT BNAME
    FROM BRANCH
    WHERE CITY='Delhi'
);

SELECT COUNT(CITY) FROM CUSTOMER;
