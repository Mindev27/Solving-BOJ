SELECT 
    HRD.DEPT_ID,
    HRD.DEPT_NAME_EN,
    ROUND(AVG(HRE.SAL), 0) AS AVG_SAL
FROM HR_EMPLOYEES HRE
LEFT JOIN HR_DEPARTMENT HRD
ON  HRE.DEPT_ID = HRD.DEPT_ID
GROUP BY HRD.DEPT_ID
ORDER BY AVG_SAL DESC;