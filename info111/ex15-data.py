# OHLCV Datagrab
import ccxt
import pandas as pd

exchange = ccxt.binance()
symbol = "BTC/USD"
symbolList = symbol.split(".")
timeframe = "15m"
limit = 1000000000 

for i in symbolList:
    print(i, timeframe, limit)
    ohlcv_data = exchange.fetch_ohlcv(i, timeframe=timeframe, limit=limit)

    df = pd.DataFrame(ohlcv_data, columns=['datetime', 'open', 'high', 'low', 'close', 'volume'])
    df['datetime'] = pd.to_datetime(df['datetime'], unit='ms')

    i = i.split("/")    
    df.to_csv(f'{"_".join(i)}_{timeframe}_binancedata.csv', index=False, sep=";")