WITH GRADES AS (
    SELECT EMP_NO,
           CASE
                WHEN AVG(SCORE) >= 96 THEN "S"
                WHEN AVG(SCORE) >= 90 THEN "A"
                WHEN AVG(SCORE) >= 80 THEN "B"
                ELSE "C"
            END AS GRADE,
            CASE
                WHEN AVG(SCORE) >= 96 THEN 0.2
                WHEN AVG(SCORE) >= 90 THEN 0.15
                WHEN AVG(SCORE) >= 80 THEN 0.1
                ELSE 0
            END AS BONUS_RATE
        FROM HR_GRADE
        GROUP BY EMP_NO    
)

SELECT GRADES.EMP_NO AS EMP_NO,
        HR_EMPLOYEES.EMP_NAME AS EMP_NAME,
        GRADES.GRADE AS GRADE,
        HR_EMPLOYEES.SAL * GRADES.BONUS_RATE AS BONUS
    FROM GRADES
    INNER JOIN HR_EMPLOYEES
        ON GRADES.EMP_NO = HR_EMPLOYEES.EMP_NO
    ORDER BY EMP_NO ASC;

