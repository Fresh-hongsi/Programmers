SELECT CRCC.CAR_TYPE, COUNT(*) AS CARS
FROM CAR_RENTAL_COMPANY_CAR CRCC
WHERE CRCC.OPTIONS LIKE '%통풍시트%' OR CRCC.OPTIONS LIKE '%열선시트%' OR CRCC.OPTIONS LIKE '%가죽시트%'
GROUP BY CRCC.CAR_TYPE
ORDER BY CRCC.CAR_TYPE ASC
