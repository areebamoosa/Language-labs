# Lab # 01

#### Q : Structure of the DEPARTMENTS table

```
DESCRIBE hr.departments;
```

#### Q : Select all data from the table

```
SELECT * from hr.DEPARTMENTS
```

#### Q : Create a query to display the last name, job code, hire date, and employee number for each employee, with employee number appearing first.

```
SELECT employee_id , last_name , job_id , hire_date FROM hr.EMPLOYEES
```

#### Q : Create a query to display unique job codes from the EMPLOYEES table.

```
SELECT DISTINCT job_id FROM hr.EMPLOYEES
```

#### Q : Display the last name concatenated with the job ID, separated by a comma and space, and name the column Employee and Title.

```
SELECT last_name ||','|| job_id AS "Employee And Title" FROM hr.EMPLOYEES
```

#### Q : Create a query to display all the data from the EMPLOYEES table. Separate each column by a comma. Name the column THE_OUTPUT.

```
SELECT employee_id || ', ' || first_name || ', ' || last_name || ', ' || email || ', ' || phone_number || ', ' || TO_CHAR(hire_date, 'DD-MON-YYYY') || ', ' || job_id || ', ' || salary || ', ' || commission_pct || ', ' || manager_id || ', ' || department_id AS "THE_OUTPUT"
FROM hr.employees;
```
