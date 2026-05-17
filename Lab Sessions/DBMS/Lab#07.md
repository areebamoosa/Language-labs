# Lab # 07

#### Q1. Run the statement in the lab8_1.sql script to build the MY_EMPLOYEE

```sql
CREATE TABLE my_employee (
    id NUMBER(3),
    last_name VARCHAR2(25),
    first_name VARCHAR2(25),
    userid VARCHAR2(8),
    salary NUMBER(10,2)
);
```

#### Q2. Describe the structure of the MY_EMPLOYEE table to identify the column names.

```sql
DESC my_employee;
```

#### Q3. Add the first row of data to the MY_EMPLOYEE table from the following sample data. Do not list the columns in the INSERT clause.

```
ID LAST_NAME FIRST_NAME USERID SALARY
1 Patel Ralph rpatel 895
2 Dancs Betty bdancs 860
3 Biri Ben bbiri 1100
4 Newman Chad cnewman 750
5 Ropeburn Audrey aropebur 1550
```

```sql
INSERT INTO my_employee
VALUES (1, 'Patel', 'Ralph', 'rpatel', 895);

INSERT INTO my_employee
VALUES (2, 'Dancs', 'Betty', 'bdancs', 860);

INSERT INTO my_employee
VALUES (3, 'Biri', 'Ben', 'bbiri', 1100);

INSERT INTO my_employee
VALUES (4, 'Newman', 'Chad', 'cnewman', 750);

INSERT INTO my_employee
VALUES (5, 'Ropeburn', 'Audrey', 'aropebur', 1550);
```

#### Q4. Populate the MY_EMPLOYEE table with the second row of sample data from the preceding list. This time, list the columns explicitly in the INSERT clause.

```sql
INSERT INTO my_employee (id, last_name, first_name, userid, salary)
VALUES (6, 'Smith', 'John', 'jsmith', 1200);
```

#### Q5. Write an INSERT statement in a text file named loademp.sql to load rows into the MY_EMPLOYEE table. Concatenate the first letter of the first name and the first seven characters of the last name to produce the user ID.

```sql
INSERT INTO my_employee (id, last_name, first_name, userid, salary)
VALUES (
    10,
    'Patel',
    'Ralph',
    LOWER(SUBSTR('Ralph',1,1) || SUBSTR('Patel',1,7)),
    895
);
```

#### Q6. Make the data additions permanent. Update and delete data in the MY_EMPLOYEE table.

```sql
COMMIT;
```

#### Q7. Change the last name of employee 3 to Drexler.

```sql
UPDATE my_employee
SET last_name = 'Drexler'
WHERE id = 3;
```

#### Q8. Change the salary to 1000 for all employees with a salary less than 900.

```sql
UPDATE my_employee
SET salary = 1000
WHERE salary < 900;
```

#### Q9. Delete Betty Dancs from the MY_EMPLOYEE table.

```sql
DELETE FROM my_employee
WHERE first_name = 'Betty'
AND last_name = 'Dancs';
```

#### Q10. Populate the table with the last row of sample data by modifying the statements in the script that you created in step 6. Run the statements in the script.

```sql
INSERT INTO my_employee
VALUES (8, 'Taylor', 'Alice', 'ataylor', 1300);
```

#### Q11. Mark an intermediate point in the processing of the transaction.

```sql
SAVEPOINT before_empty;
```

#### Q12. Empty the entire table.

```sql
DELETE FROM my_employee;
```

#### 13. Discard the most recent DELETE operation without discarding the earlier INSERT operation.

```sql
ROLLBACK TO before_empty;
```
