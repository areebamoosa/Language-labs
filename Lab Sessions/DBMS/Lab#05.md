# Lab # 05

#### Q1 : Display the highest, lowest, sum, and average salary of all employees. Label the columns Maximum , Minimum , Sum , and Average , respectively. Round your results to the nearest whole number.

```sql
SELECT
ROUND (MAX(salary)) AS "Maximum",
ROUND (MIN(salary)) AS "Minimum",
ROUND (SUM(salary)) AS "Sum",
ROUND (AVG(salary)) AS "Average"
from hr.EMPLOYEES;
```

#### Q2 : Modify the query in prev question to display the minimum, maximum, sum, and average salary for each job type.

```sql
SELECT job_id,
ROUND (MAX(salary)) AS "Maximum",
ROUND (MIN(salary)) AS "Minimum",
ROUND (SUM(salary)) AS "Sum",
ROUND (AVG(salary)) AS "Average"
from hr.EMPLOYEES
GROUP BY job_id;
```

#### Q3 : Write a query to display the number of people with the same job.

```sql
SELECT job_id,
COUNT (*) AS "Number of Employees"
from hr.EMPLOYEES
GROUP BY job_id;
```

#### Q4 : Determine the number of managers without listing them. Label the column Number of Managers .

```sql
SELECT COUNT (DISTINCT manager_id) AS "Number of Managers"
from hr.EMPLOYEES;
```

#### Q5 : Write a query that displays the difference between the highest a nd lowest salaries. Label the column DIFFERENCE.

```sql
SELECT MAX(salary) - MIN(salary) AS "Difference"
from hr.EMPLOYEES;
```

#### Q6 : Display the manager number and the salary of the lowest paid employee for that manager. Exclude anyone whose manager is not known. Exclude any groups where the minimum salary is less than $6,000. Sort the output in descending order of salary.

```sql
SELECT manager_id,  MIN(salary) AS "Lowest Salary"
from hr.EMPLOYEES
WHERE MANAGER_ID IS NOT NULL
GROUP BY manager_id
HAVING MIN(salary) >= 6000
ORDER BY "Lowest Salary" DESC;
```

#### Q6 : Write a query to display each department’s name, location, number of employees, and the average salary for all employees in that department. Label the columns Name , Location , Number of People , and Salary , respectively. Round the average salary to two decimal places.

```sql
SELECT
    d.department_name AS "Name",
    l.city AS "Location",
    COUNT(e.employee_id) AS "Number of People",
    ROUND(AVG(e.salary),2) AS "Salary"
FROM hr.departments d
JOIN hr.locations l
ON d.location_id = l.location_id
JOIN hr.employees e
ON d.department_id = e.department_id
GROUP BY d.department_name, l.city;
```

#### Q7: Create a query that will display the total number of employees and, of that total, the number of employees hired in 1995, 1996, 1997, and 1998. Create appropriate column headings.

```sql
SELECT
    COUNT(*) AS "Total Employees",
    COUNT(CASE WHEN TO_CHAR(hire_date,'YYYY') = '1995' THEN 1 END) AS "1995",
    COUNT(CASE WHEN TO_CHAR(hire_date,'YYYY') = '1996' THEN 1 END) AS "1996",
    COUNT(CASE WHEN TO_CHAR(hire_date,'YYYY') = '1997' THEN 1 END) AS "1997",
    COUNT(CASE WHEN TO_CHAR(hire_date,'YYYY') = '1998' THEN 1 END) AS "1998"
FROM hr.employees;
```

#### Q8 : Create a matrix query to display the job, the salary for that job based on department number, and the total salary for that job, for departments 20, 50, 80, and 90, giving each column an appropriate heading.

```sql
SELECT
    job_id AS "Job",
    SUM(CASE WHEN department_id = 20 THEN salary END) AS "Dept 20",
    SUM(CASE WHEN department_id = 50 THEN salary END) AS "Dept 50",
    SUM(CASE WHEN department_id = 80 THEN salary END) AS "Dept 80",
    SUM(CASE WHEN department_id = 90 THEN salary END) AS "Dept 90",
    SUM(salary) AS "Total Salary"
FROM hr.employees
GROUP BY job_id;
```
