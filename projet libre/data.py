# OHLCV Datagrab
import ccxt
import pandas as pd

exchange = ccxt.binance()
symbol = str(input("Symbols (Split by .) - "))
symbolList = symbol.split(".")
timeframe = str(input("Timeframe (1m, 3m, 15m, 1h, 4h, 6h, 1d, 1w, 1M) - "))
limit = int(input("Candles - ")) 

for i in symbolList:
    print(i, timeframe, limit)
    ohlcv_data = exchange.fetch_ohlcv(i, timeframe=timeframe, limit=limit)

    df = pd.DataFrame(ohlcv_data, columns=['datetime', 'open', 'high', 'low', 'close', 'volume'])
    df['datetime'] = pd.to_datetime(df['datetime'], unit='ms')

    i = i.split("/")    
    df.to_csv(f'{"_".join(i)}_{timeframe}_binancedata.csv', index=False, sep=";")