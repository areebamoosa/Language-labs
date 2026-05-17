# Lab # 04

#### Q1 : Write a query to display the last name, department number, and department name for all employees.

```sql
SELECT e.last_name , d.department_id , d.department_name
FROM hr.EMPLOYEES e
JOIN hr.DEPARTMENTS d
ON e.department_id = d.department_id;
```

#### Q2 : Create a unique listing of all jobs that are in department 30. Include the location of department 90 in the output.

```sql
SELECT DISTINCT e.job_id,
       (SELECT l.city
        FROM hr.departments d
        JOIN hr.locations l
        ON d.location_id = l.location_id
        WHERE d.department_id = 90) AS location
FROM hr.employees e
WHERE e.department_id = 30;
```

#### Q3 : Write a query to display the employee last name, department name, location ID, and city of all employees who earn a commission.

```sql
SELECT e.last_name, d.department_name , d.location_id , l.city
FROM hr.EMPLOYEES e
JOIN hr.DEPARTMENTS d
ON e.DEPARTMENT_ID = d.DEPARTMENT_ID
JOIN hr.LOCATIONS l
ON d.location_id = l.LOCATION_ID
WHERE e.COMMISSION_PCT IS NOT NULL;
```

#### Q4 : Display the employee last name and department name for all employees who have an a (lowercase) in their last names.

```sql
SELECT e.last_name , d.department_name
FROM hr.EMPLOYEES e
JOIN hr.DEPARTMENTS d
ON e.EMPLOYEE_ID = d.DEPARTMENT_ID
WHERE e.last_name LIKE ('%a%');
```

#### Q5 : Write a query to display the last name, job, department number, and department name for all employees who work in Toronto.

```sql
SELECT e.last_name , e.job_id , e.department_id , d.department_name
FROM hr.EMPLOYEES e
JOIN hr.DEPARTMENTS d
ON e.DEPARTMENT_ID = d.DEPARTMENT_ID
JOIN hr.LOCATIONS l
ON d.LOCATION_ID = l.LOCATION_ID
WHERE l.city = 'Toronto';
```

#### Q6 : Display the employee last name and employee number along with their manager’s last name and manager number. Label the columns Employee , Emp# , Manager , and Mgr# , respectively.

```sql
SELECT  e.last_name AS "Employee", e.employee_id AS "Emp#", m.last_name AS "Manager", m.employee_id AS "Mgr#"
FROM hr.employees e
JOIN hr.employees m
ON e.manager_id = m.employee_id;
```

#### Q7 : Display all employees including King, who has no manager. Order the results by the employee number.

```sql
SELECT e.last_name AS Employee , e.employee_id AS Emp# , m.last_name AS Manager , m.employee_id AS Mgr#
FROM hr.EMPLOYEES e
LEFT JOIN hr.EMPLOYEES m
ON e.manager_id = m.EMPLOYEE_ID
ORDER BY e.EMPLOYEE_ID;
```

#### Q8 : Create a query that displays employee last names, department numbers, and all the employees who work in the same department as a given employee. Give each column an appropriate label.

```sql
SELECT
    e.last_name AS "Employee",
    e.department_id AS "Dept ID",
    c.last_name AS "Colleague"
FROM hr.employees e
JOIN hr.employees c
ON e.department_id = c.department_id
ORDER BY e.department_id, e.last_name, c.last_name;
```

#### Q9 : Show the structure of the JOB_GRADES table. Create a query that displays the name, job, department name, salary, and grade for all employees.

```sql
DESCRIBE * job_grades;
```

```sql
SELECT  e.last_name, e.job_id, e.salary ,d.department_name, j.job_grades
FROM hr.employees e
JOIN hr.departments d
ON e.department_id = d.department_id
JOIN hr.jobs j
ON e.salary BETWEEN j.min_salary AND j.max_salary;
```

#### Q10 : Create a query to display the name and hire date of any employee hired after employee Davies.

```sql
SELECT  e.last_name AS "Employee", e.hire_date AS "Hire Date"
FROM hr.employees e
WHERE e.hire_date > (
    SELECT hire_date
    FROM hr.employees
    WHERE last_name = 'Davies'
);
```

#### Q11 : Display the names and hire dates for all employees who were hired before their managers, along with their manager’s names and hire dates. Label the columns Employee , Emp Hired , Manager , and Mgr Hired , respectively.

```sql
SELECT  e.last_name AS "Employee", e.hire_date AS "Emp Hired", m.last_name AS "Manager", m.hire_date AS "Mgr Hired"
FROM hr.employees e
JOIN hr.employees m
ON e.manager_id = m.employee_id
WHERE e.hire_date < m.hire_date;
```
