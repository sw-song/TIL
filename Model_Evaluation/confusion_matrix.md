## sklearn.metrics.confusion_matrix
reference :
1. [sklearn.metrics.confusion_matrix, scikit-learn.org](https://scikit-learn.org/stable/modules/generated/sklearn.metrics.confusion_matrix.html)
2. [분류 성능평가, 데이터사이언스스쿨](https://datascienceschool.net/03%20machine%20learning/09.04%20분류%20성능평가.html)
---
> Document
```
sklearn.metrics.confusion_matrix(y_true, y_pred, *, labels=None, sample_weight=None, normalize=None)
```

> 사용 예시
```python
from sklearn.metrics import confusion_matrix
y_true = [2, 0, 2, 2, 0, 1]
y_pred = [0, 0, 2, 2, 0, 2]
confusion_matrix(y_true, y_pred)
```
```
array([[2, 0, 0],
       [0, 0, 1],
       [1, 0, 2]])
```

해석해보면, 

| 클래스 | 0 | 1 | 2 |
| :--: |:-:|:-:|:-:|
| 0    |   |   |   |
| 1    |   |   |   |
| 2    |   |   |   |

위 표가 pandas DataFrame이고, Column은 예측 클래스(y_pred), Index는 정답 클래스(y_true)라고 해보자.
이제 빈 공간(value)은 예측 클래스와 정답 클래스가 일치한다면 1씩 채워지게 된다.

| 클래스 | 0 | 1 | 2 |
| :--: |:-:|:-:|:-:|
| 0    | 2 | 0 | 0 |
| 1    | 0 | 0 | 1 |
| 2    | 1 | 0 | 2 |

즉, 
- 실제 클래스가 0일 때, 0이라 예측한 수가 2
- 실제 클래스가 2일 때, 0이라 예측한 수가 1
- 실제 클래스가 1일 때, 2라 예측한 수가 1
- 실제 클래스가 2일 때, 2라 예측한 수가 2
- 숫자를 합치면 6이 되고, 이는 예측한 클래스 수와 동일.
- 나머지 0으로 표기된 부분은 예측하지 않은 부분.

를 의미한다.

---
마찬가지로 이진분류의 경우도 생각해볼 수 있다.

| 클래스 | False | True |
| :--: |:----:|:-----:|
| False |      |       |
| True|      |       |

(맞다, 아니다), (양성, 음성), (정상, 불량) 등 많은 곳에 활용되는 이진분류는 위 표와 같이 표현할 수 있다.
다중 분류와 마찬가지로 Column은 예측 클래스, Index는 정답 클래스다.

```python
y_true = [1, 0, 1, 1, 0, 1]
y_pred = [0, 0, 1, 1, 0, 1]
confusion_matrix(y_true, y_pred)
```
```
array([[2, 0],
       [1, 3]])
```

표를 통해 아래와 같이 표현할 수 있다.

| 클래스 | False | True |
| :--: |:----:|:-----:|
| False |  2   |  0   |
| True|  1   |  3   |
* False : 0
* True : 1

해석하면,
- 실제 False(0)를 False(0)라고 제대로 예측한 경우가 2번
- 실제 True(1)를 True(1)라고 제대로 예측한 경우가 3번
- 실제 False(0)임에도 불구하고 True(1)라고 잘못 예측한 경우는 0번
- 실제 True(1)를 False(0)로 잘못 예측한 경우가 1번

여기서, 양성(True) 값을 제대로 발견하지 못한 경우가 1번 있었고 이런 부분들이 모델의 정확도(Accuracy)를 떨어뜨린다.




