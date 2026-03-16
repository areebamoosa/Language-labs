# Lab # 03

#### Q : Write a query that displays the employee’s last names with the first letter capitalized and all other letters lowercase and the length of the names, for all employees whose name starts with J , A , or M . Give each column an appropriate label. Sort the results by the employees’ last names.

```sql
SELECT INITCAP(last_name) AS "Last Name", LENGTH(last_name) AS "Length"
FROM hr.EMPLOYEES
WHERE last_name LIKE 'A%'
OR last_name LIKE 'J%'
OR last_name LIKE 'M%'
ORDER BY (last_name);
```

#### Q : For each employee, display the employee’s last name, and calculate the number of months between today and the date the employee was hired. Label the column MONTHS_WORKED . Order your results by the number of months employed. Round the number of months up to the closest whole number.

```sql
SELECT last_name AS "Employee Name",
CEIL (MONTHS_BETWEEN(SYSDATE, hire_date)) AS MONTHS_WORKED
from hr.EMPLOYEES
ORDER BY MONTHS_WORKED;
```

#### Q : Write a query that produces the following for each employee < employee last name> earns <salary> monthly but wants <3 times salary > Label the column Dream Salaries

```sql
SELECT last_name || ' earns' || salary || ' but wants ' || (salary*3) AS "Dream Salaries"
from hr.Employees;
```

#### Q : Create a query to display the last name and salary for all employees. Format the salary to be 15 characters long, left-padded with $. Label the column SALARY .

```sql
SELECT last_name , LPAD (salary, 15, '$') AS "Salary"
from hr.Employees;
```

#### Q : Display each employee’s last name, hire date, and salary review date, which is the first Monday after six months of service. Label the column REVIEW. Format the dates to appear similar to “Monday, the Thirty-First of July, 2000.”

```sql
SELECT last_name , hire_date ,
TO_CHAR(
    NEXT_DAY(ADD_MONTHS(hire_date,6) , 'MONDAY' ),
    'Day, "the" DDSP "of" Month, YYYY'
) AS REVIEW
from hr.Employees;
```

#### Q : Display the last name, hire date, and day of the week on which the employee started. Label the column DAY . Order the results by the day of the week starting with Monday.

```sql
SELECT last_name, hire_date ,
TO_CHAR(hire_date,'Day') AS DAY
FROM hr.EMPLOYEES
ORDER BY TO_CHAR(hire_date,'D');
```

#### Q : Create a query that displays the employees’ last names and commission amounts. If an employee does not earn commission, put “No Commission.” Label the column COMM.

```sql
SELECT last_name, NVL(TO_CHAR(commission_pct), 'No Commision' ) AS "COMM"
FROM hr.EMPLOYEES;
```

#### Q : Create a query that displays the employees’ last names and indicates the amounts of their annual salaries with asterisks. Each asterisk signifies a thousand dollars. Sort the data in descending order of salary. Label the column EMPLOYEES_AND_THEIR_SALARIES.

```sql
SELECT last_name , RPAD ('*', TRUNC(salary/ 1000), '*') AS "Employees_And _Their_ Salaries"
FROM hr.EMPLOYEES
ORDER BY salary DESC;
```

#### Q : Using the DECODE function, write a query that displays the grade of all employee s based on the value of the column JOB_ID , as per the following data:

#### Job Grade

#### A AD_PRES

#### B ST_MAN

#### C IT_PROG

#### D SA_REP

#### E ST_CLERK

#### None of the above 0

```sql
SELECT last_name, job_id, DECODE(
    job_id,
    'AD_PRES','A',
    'ST_MAN','B',
    'IT_PROG','C',
    'SA_REP','D',
    'ST_CLERK','E',
    '0'
) AS GRADE
FROM hr.EMPLOYEES
```

#### Q : Rewrite the statement in the preceding question using the CASE syntax.

```sql
SELECT last_name, job_id,
CASE job_id
        WHEN 'AD_PRES' THEN 'A'
        WHEN 'ST_MAN' THEN 'B'
        WHEN 'IT_PROG' THEN 'C'
        WHEN 'SA_REP' THEN 'D'
        WHEN 'ST_CLERK' THEN 'E'
        ELSE '0'
        END AS GRADE
FROM hr.EMPLOYEES;
```
