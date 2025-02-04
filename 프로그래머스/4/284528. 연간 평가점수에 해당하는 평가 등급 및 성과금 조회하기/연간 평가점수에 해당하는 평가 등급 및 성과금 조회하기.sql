SELECT
    HR.EMP_NO,
    HR.EMP_NAME,
    GT.GRADE,
    CASE
        WHEN GT.GRADE = 'S' THEN HR.SAL * 0.20
        WHEN GT.GRADE = 'A' THEN HR.SAL * 0.15
        WHEN GT.GRADE = 'B' THEN HR.SAL * 0.10
        ELSE 0
    END AS BONUS
FROM HR_EMPLOYEES HR

JOIN (
    SELECT
        EMP_NO,
        CASE
            WHEN AVG(SCORE) >= 96 THEN 'S'
            WHEN AVG(SCORE) >= 90 THEN 'A'
            WHEN AVG(SCORE) >= 80 THEN 'B'
            ELSE 'C'
        END AS GRADE,
        AVG(SCORE) AS SCORE
    FROM HR_GRADE 
    GROUP BY EMP_NO
) AS GT
ON HR.EMP_NO = GT.EMP_NO
ORDER BY HR.EMP_NO ASC;
