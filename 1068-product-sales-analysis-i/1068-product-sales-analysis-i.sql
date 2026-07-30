# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT  sales.year,sales.price,Product.product_name
FROM Sales 
LEFT JOIN Product
ON sales.product_id=Product.product_id
