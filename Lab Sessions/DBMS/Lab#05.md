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
