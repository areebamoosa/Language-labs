# Lab # 03

#### Q : Write a query that displays the employee’s last names with the first letter capitalized and all other letters lowercase and the length of the names, for all employees whose name starts with J , A , or M . Give each column an appropriate label. Sort the results by the employees’ last names.

```
SELECT INITCAP(last_name) AS "Last Name", LENGTH(last_name) AS "Length"
FROM hr.EMPLOYEES
WHERE last_name LIKE 'A%'
OR last_name LIKE 'J%'
OR last_name LIKE 'M%'
ORDER BY (last_name);
```

#### Q : For each employee, display the employee’s last name, and calculate the number of months between today and the date the employee was hired. Label the column MONTHS_WORKED . Order your results by the number of months employed. Round the number of months up to the closest whole number.

```
SELECT last_name AS "Employee Name",
CEIL (MONTHS_BETWEEN(SYSDATE, hire_date)) AS MONTHS_WORKED
from hr.EMPLOYEES
ORDER BY MONTHS_WORKED;
```

#### Q : Write a query that produces the following for each employee < employee last name> earns <salary> monthly but wants <3 times salary > Label the column Dream Salaries

```
SELECT last_name || ' earns' || salary || ' but wants ' || (salary*3) AS "Dream Salaries"
from hr.Employees;
```

#### Q : Create a query to display the last name and salary for all employees. Format the salary to be 15 characters long, left-padded with $. Label the column SALARY .

```
SELECT last_name , LPAD (salary, 15, '$') AS "Salary"
from hr.Employees;
```

#### Q : Display each employee’s last name, hire date, and salary review date, which is the first Monday after six months of service. Label the column REVIEW. Format the dates to appear similar to “Monday, the Thirty-First of July, 2000.”

```
SELECT last_name , hire_date ,
TO_CHAR(
    NEXT_DAY(ADD_MONTHS(hire_date,6) , 'MONDAY' ),
    'Day, "the" DDSP "of" Month, YYYY'
) AS REVIEW
from hr.Employees;
```
