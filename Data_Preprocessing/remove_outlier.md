# Outlier Remove Function 

> *reference : kaggle, [Heart Attack Prediction_95.4% accuracy, Avinash Bagul](https://www.kaggle.com/avibagul80/heart-attack-prediction)*
---



```python
def removeOutlier(att, df): # att <= df.col
    lowerbound = att.mean() -3 * att.std() # df.col 값 평균에서 3표준편차만큼 뺀 값을 최하위 값으로 지정
    upperbound = att.mean() +3 * att.std() # df.col 값 평균에서 3표준편차만큼 더한 값을 최상위 값으로 지정
    
    print('lowerbound: ',lowerbound, ' --------- upperbound:',upperbound)
    
    df1 = df[(att > lowerbound) & (att < upperbound)] # df.col 값 중 lowerbound~upperbound 안으로 들어오는 값만 df1에 저장
    
    print((df.shape[0] - df1.shape[0]), 'number of outliers from ', df.shape[0]) # outlier(제거된 값) 수 출력
    print('****************************************************')
    
    df = df1.copy()
    return df
```

