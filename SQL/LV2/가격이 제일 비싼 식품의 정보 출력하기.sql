SELECT P.PRODUCT_ID, P.PRODUCT_NAME, P.PRODUCT_CD, P.CATEGORY, P.PRICE
FROM FOOD_PRODUCT P
ORDER BY P.PRICE DESC
LIMIT 1
