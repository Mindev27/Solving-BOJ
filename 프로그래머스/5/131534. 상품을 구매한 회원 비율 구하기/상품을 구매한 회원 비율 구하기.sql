#전체 회원 수
WITH TOTAL_USER AS (
    SELECT COUNT(DISTINCT USER_ID) AS CNT
    FROM USER_INFO 
    WHERE JOINED LIKE '2021%'
    
)

SELECT
    YEAR(ONLINE_SALE.SALES_DATE) AS YEAR,
    MONTH(ONLINE_SALE.SALES_DATE) AS MONTH,
    COUNT(DISTINCT ONLINE_SALE.USER_ID) AS PURCHASED_USERS,
    ROUND(COUNT(DISTINCT ONLINE_SALE.USER_ID) / (SELECT CNT FROM TOTAL_USER), 1) AS PUCHASED_RATIO
FROM ONLINE_SALE 
JOIN USER_INFO
ON ONLINE_SALE.USER_ID = USER_INFO.USER_ID
WHERE USER_INFO.JOINED LIKE '2021%'
GROUP BY YEAR(ONLINE_SALE.SALES_DATE), MONTH(ONLINE_SALE.SALES_DATE) 
ORDER BY YEAR(ONLINE_SALE.SALES_DATE) ASC, MONTH(ONLINE_SALE.SALES_DATE) ASC;

