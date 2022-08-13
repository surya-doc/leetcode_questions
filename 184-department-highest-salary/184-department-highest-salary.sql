# Write your MySQL query statement below
SELECT Department.name AS Department, Employee.name AS Employee, Employee.salary AS Salary
FROM Employee
JOIN Department
on Employee.departmentId=Department.id
WHERE(departmentId, salary) IN(
    SELECT departmentId, MAX(salary) as Salary
    FROM Employee
    GROUP BY departmentId
);