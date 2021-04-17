# df.ffill()
reference:
1. [pandas.DataFrame.ffill(pandas.pydata.org)](https://pandas.pydata.org/docs/reference/api/pandas.DataFrame.ffill.html)
2. [Python pandas - 결측값 채우기 ... ](https://rfriend.tistory.com/262)
3. [Python | Pandas dataframe.ffill()](https://www.geeksforgeeks.org/python-pandas-dataframe-ffill/)
4. [Pandas DataFrame ffill() Method](https://www.studytonight.com/pandas/pandas-dataframe-ffill-method)
---
머신러닝 모델은 결측치가 존재하는 데이터프레임을 받아들이지 못한다. 

따라서 데이터 전처리 과정에서는 반드시 NaN 값을 체크하고 해당 결측치를 특정 값으로 대체하거나 해당 결측치가 포함된 열 혹은 행을 제거해야 한다.

그러나 열 혹은 행을 제거한다면 중요한 데이터 소스를 잃어버리게 된다. 이를 감수할 만큼 해당 데이터 열 혹은 행이 유의미하지 않다면 무관하나 유의미하다면 제거하기보다 새로운 값으로 대체하는 것이 좋겠다.

결측치 처리 방법으로 다양한 것이 있지만 여기서는 forward-fill 방식, 즉 ```동일한 column에서 바로 위 인덱스를 참조하여 동일한 값을 입력하는 방식``` 을 정리한다.


forward-fill 방식을 지원하는 함수는 아래와 같다.

1. df.ffill()
2. df.fillna(method='ffill')
3. df.fillna(method='pad')

편한 방식으로 사용하면 되고, 해당 함수를 적용했을 때 결측값이 처리되는 모습은 아래와 같다.

---
**1. df.ffill()**
```python
print(df)
```
```
          X1       X2         X3
0       0.88       56        102
1       0.23       NaN       NaN
2       0.10       52        120
3       0.15       49        114
```
```python
df.ffill() # Default : axis=0 (along the index)
```
```
          X1       X2         X3
0       0.88       56        102
1       0.23       56        102
2       0.10       52        120
3       0.15       49        114
```

여기서는 axis가 0인 경우, 즉 '행(index)'을 기준으로 위 인덱스를 참조하여 아래 인덱스에 해당하는 NaN값을 채웠다.

이와 달리 '열(column)'을 기준으로 앞의 열을 따라 뒤 열을 채우겠다면 axis를 1로 지정하면 된다.
```python
df.ffill(axis=1)
```
```
          X1       X2         X3
0       0.88       56        102
1       0.23       0.23      0.23
2       0.10       52        120
3       0.15       49        114
```

데이터는 row와 column으로 구성되어 있다.
row는 각각의 개별 관측치를 담고, column은 개별 관측치마다의 서로 다른(독립적인) 특징들을 담는다.

```axis=1```은 독립된 특징을 담는 서로 다른 column을 앞 뒤로 참조하여 채우는 방식이다. 독립된 column끼리 참조하여 값을 채운다는 것은 일반적인 사례가 아니다. 

따라서 일반적인 경우 ```axis=0``` Default 파라미터를 사용한다.

---
**2. df.fillna(method='ffill')**

사실, ```df.ffill()``` 보다는 ```df.fillna()``` 메소드가 더 많이 활용된다. 

```df.fillna(n)``` 을 통해 NaN 값을 n으로 채우거나 ```df.fillna(method='ffill')```을 통해 앞에서 봤던 ```df.ffill()```의 기능도 동일하게 구현할 수 있다. 물론 ```df.ffill(axis=1)```과 마찬가지로 ```axis=1``` 파라미터를 지정함으로써 column을 기준으로 앞의 컬럼에 해당하는 값을 참조하여 NaN값을 채우는 것도 가능하다.
```python
print(df)
```
```
          X1       X2         X3
0       0.88       56        102
1       0.23       NaN       NaN
2       0.10       52        120
3       0.15       49        114
```
```python
df.fillna(0) # Default : axis=0 (along the index)
```
```
          X1       X2         X3
0       0.88       56        102
1       0.23        0          0
2       0.10       52        120
3       0.15       49        114
```
```python
df.fillna(method='ffill') # Default : axis=0 (along the index)
```
```
          X1       X2         X3
0       0.88       56        102
1       0.23       56        102
2       0.10       52        120
3       0.15       49        114
```
```python
df.fillna(method='ffill', axis=1) # Default : axis=0 (along the index)
```
```
          X1       X2         X3
0       0.88       56        102
1       0.23     0.23       0.23
2       0.10       52        120
3       0.15       49        114
```
---
**2. df.fillna(method='pad')**
```method='pad'```는 ```mehod='ffill'```과 완전히 동일한 기능을 한다. 내용은 생략한다.