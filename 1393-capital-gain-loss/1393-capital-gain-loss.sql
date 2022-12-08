# Write your MySQL query statement below
# SELECT stock_name, SUM(CASE WHEN operation = "Buy" THEN price * (-1) ELSE price END) AS capital_gain_loss
# FROM Stocks
# GROUP BY stock_name

Select stock_name, sum(If(operation='Buy',price*(-1),price)) as capital_gain_loss from Stocks group by stock_name;