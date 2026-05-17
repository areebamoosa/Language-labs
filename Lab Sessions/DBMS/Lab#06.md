# Lab # 06

#### Q1. Write a query to display the last name and hire date of any employee in the same department as Zlotkey. Exclude Zlotkey.

```sql
SELECT e.last_name, e.hire_date , d.department_name
FROM hr.EMPLOYEES e
JOIN hr.DEPARTMENTS d
ON e.DEPARTMENT_ID = d.DEPARTMENT_ID;
WHERE e.DEPARTMENT_ID = (
    SELECT DEPARTMENT_ID
    FROM hr.EMPLOYEES
    WHERE last_name = 'Zlotkey'
)
AND e.last_name <> 'Zlotkey';
```

#### Q2. Create a query to display the employee numbers and last names of all employees who earn more than the average salary. Sort the results in ascending order of salary.

```sql
SELECT
employee_id, last_name , salary
FROM hr.Employees
WHERE salary > (
   SELECT  AVG(salary)
   FROM hr.Employees
);
ORDER BY salary ASC;
```

#### Q3. Write a query that displays the employee numbers and last names of all employees who work in a department with any employee whose last name contains a u.

```sql
SELECT
employee_id, last_name
FROM hr.Employees
WHERE department_id IN (
    SELECT DEPARTMENT_ID
   FROM hr.Employees
   WHERE  last_name LIKE '%u%'
);
```

#### Q4. Display the last name, department number, and job ID of all employees whose department location ID is 1700.

```sql
SELECT
    e.last_name,
    e.department_id,
    e.job_id,
    l.location_id
FROM hr.employees e
JOIN hr.departments d
    ON e.department_id = d.department_id
JOIN hr.locations l
    ON d.location_id = l.location_id
WHERE d.location_id = 1700;
```

#### Q5. Display the last name and salary of every employee who reports to King.

```sql
SELECT e.last_name AS "Employee", e.salary AS "Salary" , m.last_name
FROM hr.employees e
JOIN hr.employees m
ON e.manager_id = m.employee_id
WHERE m.last_name = 'King';
```

#### Q6. Display the department number, last name, and job ID for every employee in the Executive department.

```sql
SELECT e.last_name AS "Employee", e.salary AS "Salary" , d.department_name
FROM hr.employees e
JOIN hr.DEPARTMENTS d
ON e.DEPARTMENT_ID = d.DEPARTMENT_ID
WHERE d.department_name = 'Executive';
```

#### Q7. Display the employee numbers, last names, and salaries of all employees who earn more than the average salary and who work in a department with any employee with a u in their name.

```sql
SELECT employee_id, last_name, salary
FROM hr.EMPLOYEES
WHERE department_id IN (
    SELECT department_id
    FROM hr.EMPLOYEES
    WHERE last_name LIKE '%u%'
)
AND salary > (
    SELECT AVG(salary)
    FROM hr.EMPLOYEES
)
```
