## pandas.melt

### reference
1. [document : pandas.melt]((https://github.com/sw-song/TIL/blob/main/Statistics/kstest.md))

---

`melt()` 함수는 표현처럼 데이터프레임을 '녹이는' 듯 재구성한다.

기존의 열(columns) 이름을 값(values)으로 내려 각각의 행(index)에 열 이름과 각각 해당하는 값을 나열해서 보여준다.
```python
import pandas as pd

df = pd.DataFrame({
    'id': ['201','873','385','505'],
    'type':['A','B','C','D'],
    'count':[8,8,6,2]
})

print(df)
```
| |id|type|count|
|:-:|:-:|:-:|:-:|
|0|201|A|8|
|1|873|B|8|
|2|385|C|6|
|3|505|D|2|

위 데이터프레임에서 `type` 컬럼은 A,B,C,D 라는 4가지 값을 가지고 있다.

`melt()`를 사용해 `type`을 값으로 표기하고 각각의 기존 값(A,B,C,D)는 그것에 뒤따라 붙일 수 있다.

```python
pd.melt(df, id_vars='id', value_vars='type')
```

|  |id|	variable|	value|
|:-:|:--:|:--:|:--:|
|0|	201|	type|	A|
|1|	873|	type|	B|
|2|	385|	type|	C|
|3|	505|	type|	D|

만약 `type`, `count` 컬럼을 모두 값으로 표기하고 싶다면 `value_vars` 인자를 리스트로 전달하면 된다.

```python
pd.melt(df, id_vars='id', value_vars=['type','count'])
```


||id|	variable|	value|
|:-:|:--:|:--:|:--:|
|0	|201|	type|	A|
|1	|873|	type|	B|
|2	|385|	type|	C|
|3	|505|	type|	D|
|4	|201|	count|	8|
|5	|873|	count|	8|
|6	|385|	count|	6|
|7	|505|	count|	2|


혹은 `id`와 함께 `type`도 그대로 컬럼으로 유지하고 `count`만 값으로 내리고 싶을 수도 있다. 
이 경우 `id_vars`인자를 리스트로 전달하면 된다.

```python
pd.melt(df, id_vars=['id','type'], value_vars='count')
```

||id|type|variable|value|
|:-:|:--:|:--:|:--:|:--:|
|0|	201|	A|	count|	8|
|1|	873|	B|	count|	8|
|2|	385|	C|	count|	6|
|3|	505|	D|	count|	2|

마지막으로 `melt()` 함수를 통해 새롭게 생성된 `variable`, `value` 컬럼의 이름을 바꾸고 싶다면, `var_name`과 `value_name` 파라미터를 추가해주면 되겠다.


```python
pd.melt(df, id_vars='id', 
        value_vars=['type','count'],
        var_name='info_group', value_name='info'
)
```

|	|id	|info_group	|info|
|:-:|:--:|:--:|:--:|
|0	|201	|type	|A|
|1	|873	|type	|B|
|2	|385	|type	|C|
|3	|505	|type	|D|
|4	|201	|count	|8|
|5	|873	|count	|8|
|6	|385	|count	|6|
|7	|505	|count	|2|


각각의 `id`에 대해 정보를 표시하는 `type`과 `count`를 하나의 그룹 `info_group`으로 묶었고, 그룹에 해당하는 값들을 `info`로 묶었다.



