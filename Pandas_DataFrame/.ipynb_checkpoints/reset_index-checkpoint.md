# reset_index(drop=True)

---

데이터전처리가 끝난 후, 혹은 중간에 데이터 정리가 필요한 경우 ```reset_index()```는 유용하게 사용된다.

```reset_index()``` 는 마치 엑셀, 구글스프레드시트의 고정된 index 번호처럼 0부터 순서대로 index를 정리해주는 함수다.

아래와 같은 과일의 특징을 정리한 데이터프레임이 있다고 해보자.


```python
print(df)
```
```
        x1  x2  x3  x4
Apple    1   1   0  0
Banana   1   0   1  1 
Kiwi     0   1   1  0 
```

```reset_index()``` 함수를 사용해보면, 인덱스가 다시 정리되고 기존의 index는 새로운 '열'로 추가된다.

```python
print(df.reset_index())
```
```
    index   x1  x2  x3  x4
0   Apple    1   1   0  0
1   Banana   1   0   1  1 
2   Kiwi     0   1   1  0 
```

그러나 보통은 이러한 형태가 아닌 index를 '정리'하거나 새로운 index로 '변환'하기 위해 reset_index()를 사용하게 된다.

이 때는 파라미터 값으로 ```drop=True```를 주면 된다.

```python
print(df.reset_index(drop=True))
```
```
    x1  x2  x3  x4
0    1   1   0  0
1    1   0   1  1 
2    0   1   1  0 
```


여기서 데이터 원본값을 수정하고 싶다면 ```ìnplace=True```를 추가로 넣어준다.

```python
print(df.reset_index(drop=True, inplace=True))
```
```
    x1  x2  x3  x4
0    1   1   0  0
1    1   0   1  1 
2    0   1   1  0 
```