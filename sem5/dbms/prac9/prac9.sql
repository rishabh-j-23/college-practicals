-- Active: 1691209649688@@127.0.0.1@3306@prac9
CREATE TABLE sample_table (
    id INT PRIMARY KEY,
    name VARCHAR(255) 
);

INSERT INTO sample_table (id, name) VALUES
(1, 'John'),
(2, 'Alice'),
(3, 'Bob');

SELECT * FROM sample_table;

START TRANSACTION;

UPDATE sample_table
SET name = 'Jane'
WHERE id = 1;

INSERT INTO sample_table (id, name) VALUES (4, 'Charlie');

SAVEPOINT my_savepoint;

SELECT * FROM sample_table;

UPDATE sample_table
SET name = 'Eve'
WHERE id = 2;

DELETE FROM sample_table WHERE id = 3;

SELECT * FROM sample_table;

ROLLBACK TO my_savepoint;

COMMIT;

SELECT * FROM sample_table;