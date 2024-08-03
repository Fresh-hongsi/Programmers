SELECT UU.USER_ID, UU.NICKNAME, CONCAT(UU.CITY,' ',STREET_ADDRESS1,' ',STREET_ADDRESS2) AS 전체주소, CONCAT(SUBSTRING(UU.TLNO,1,3),'-',SUBSTRING(UU.TLNO,4,4), '-', SUBSTRING(UU.TLNO,8,4)) AS 전화번호
FROM USED_GOODS_BOARD UB
JOIN USED_GOODS_USER UU ON UB.WRITER_ID = UU.USER_ID
GROUP BY UB.WRITER_ID
HAVING COUNT(*)>=3
ORDER BY UU.USER_ID DESC
