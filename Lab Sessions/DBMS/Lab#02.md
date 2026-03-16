# Lab # 02

#### Q : Create a query to display the last name and salary of employees earning more than $12,000.

```sql
SELECT last_name, salary from hr.employees WHERE salary > 12000 ;
```

#### Q : Create a query to display the employee last name and department number for employee number 176.

```sql
SELECT last_name , department_id from hr.EMPLOYEES WHERE EMPLOYEE_ID = 176;
```

#### Q : Display the last name and salary for all employees whose salary is not in the range of $5,000 and $12,000.

```sql
SELECT last_name, salary from hr.EMPLOYEES WHERE salary NOT BETWEEN 5000 AND 12000;
```

#### Q : Display the employee last name, job ID, and start date of employees hired between February 20, 1998, and May 1, 1998. Order the query in ascending order by start date.

```sql
SELECT last_name, job_id ,hire_date from hr.EMPLOYEES WHERE hire_date BETWEEN '20-FEB-1998' AND '01-MAY-1998' ORDER BY hire_date ASC;
```

#### Q : Display the last name and department number of all employees in departments 20 and 50 in alphabetical order by name.

```sql
SELECT last_name , department_id from hr.EMPLOYEES WHERE department_id IN(20,50) ORDER BY last_name ASC;
```

#### Q : List the last name and salary of employees who earn between $5,000 and $12,000, and are in department 20 or 50. Label the columns Employee and Monthly Salary , respectively.

```sql
SELECT last_name AS "Employee" , salary AS "Monthly Salary"
FROM hr.EMPLOYEES
WHERE salary BETWEEN 5000 AND 12000
AND department_id IN (20,50);
```

#### Q : Display the last name and hire date of every employee who was hired in 1994.

```sql
SELECT last_name , hire_date
from hr.EMPLOYEES
WHERE hire_date BETWEEN '01-JAN-1994' AND '31-DEC-1994';
```

#### Q : Display the last name and job title of all employees who do not have a manager.

```sql
SELECT last_name , job_id
from hr.EMPLOYEES
WHERE MANAGER_ID IS NULL;
```

#### Q : Display the last name, salary, and commission for all employees who earn commissions. Sort data in descending order of salary and commissions.

```sql
SELECT last_name , salary, commission_pct
from hr.EMPLOYEES
WHERE COMMISSION_PCT IS NOT NULL
ORDER BY salary DESC, commission_pct DESC;
```

#### Q : Display the last names of all employees where the third letter of the name is an a.

```sql
SELECT last_name FROM HR.EMPLOYEES
WHERE last_name LIKE '__a%';
```

#### Q : Display the last name of all employees who have an a and an e in their last name.

```sql
SELECT last_name
FROM hr.employees
WHERE last_name LIKE '%a%'
AND last_name LIKE '%e%';
```

#### Q : Display the last name, job, and salary for all employees whose job is sales representative or stock clerk and whose salary is not equal to $2,500, $3,500, or $7,000.

```sql
SELECT last_name , job_id , salary
FROM hr.employees
WHERE job_id IN ('SA_REP', 'ST_CLERK')
AND salary NOT IN (2500,3500,7000);
```

#### Q : Display the last name, salary, and commission for all employees whose commission amount is 20%.

```sql
SELECT last_name , salary, COMMISSION_PCT
FROM hr.employees
WHERE COMMISSION_PCT = '0.20';
```
