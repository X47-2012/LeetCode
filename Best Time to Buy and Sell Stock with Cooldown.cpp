/*
    buy[i] means before day i (include day i) what is the maxProfit for any sequence end with buy.
    sell[i] means before day i (include day i) what is the maxProfit for any sequence end with sell.
    
    buy[i] = max(sell[i-2]-price, buy[i-1])
    sell[i] = max(buy[i-1]+price, sell[i-1])
*/

int maxProfit(vector<int>& prices) {
    int sell = 0, prev_sell = 0, buy = INT_MIN, prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, prev_buy);
        prev_sell = sell;
        sell = max(prev_buy + price, prev_sell);
    }
    return sell; 
}