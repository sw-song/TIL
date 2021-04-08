# K-Nearest Neighbor Algorithm(최근접 이웃 알고리즘)
> Reference :
> 1. [K-NN 알고리즘(K-최근접이웃) 개념](https://m.blog.naver.com/bestinall/221760380344)
> 2. 파이썬 라이브러리를 활용한 머신러닝, 한빛미디어(전체 코드, 이미지)
1. Classification
2. Regression
---

### 1. Classification
* (n = 1) 기존에 분포하는 값 중 가장 가까운 값의 label을 현재 Test값의 label로 지정한다.
* (n > 1) 기존에 분포하는 값 중 가장 가까운 순서대로 n개의 값을 찾고, **가장 많이 나오는 label**을 현재 Test값의 label로 지정한다.

> ex. N = 3일 때, 탐색 방식 

![image](https://t1.daumcdn.net/cfile/tistory/9931AB3D5A634B8626)

> ex. N = 3일 때, 코드 예시

```python
from sklearn.model_selection import train_test_split
X, y = mglearn.datasets.make_forge()

X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0)
```
```python
from sklearn.neighbors import KNeighborsClassifier
clf = KNeighborsClassifier(n_neighbors=3)
clf.fit(X_train, y_train)
```
> 이산형(분류) y_hat 값을 잘 만들어냈는지 확인
```python
print("y_pred : {}".format(clf.predict(X_test)))
```
> 출력
```
y_pred : [1 0 1 0 1 0 0]
```
> Accuracy Check
```python
print('Accuracy : {:.2f}'.format(clf.score(X_test, y_test))) # Classification의 score는 전체 값 중 맞춘 값의 %를 반환한다.
```
> 출력
```
Accuracy : 0.86
```



### 2. Regression
* (n = 1) 기존에 분포하는 값 중 가장 가까운 값의 label을 현재 Test값의 label로 지정한다.
* (n > 1) 기존에 분포하는 값 중 가장 가까운 순서대로 n개의 값을 찾고, **n개 label의 평균 값(y_mean)**을 현재 Test값의 label로 지정한다.

> ex. N = 3일 때, 탐색 방식 

![image](https://t1.daumcdn.net/cfile/tistory/998AEE3A5A634FF017)

> ex. N = 3일 때, 코드 예시

```python
from sklearn.neighbors import KNeighborsRegressor

X, y = mglearn.datasets.make_wave(n_samples=40)

X_train, X_test, y_train, y_test = train_test_split(X, y, random_state=0) # random_state를 통해 인덱스를 shuffle해주고 seed를 0으로 줌

reg = KNeighborsRegressor(N_neighbors=3)
reg.fit(X_train, y_train)
```
> 연속형(회귀) y_hat 값을 잘 만들어냈는지 확인
```python
print("y_pred : {}".format(reg.predict(X_test)))
```
> 출력
```
y_pred : [-0.054 0.357 1.137 -1.894 -1.139 -1.631 0.357 0.912 -0.447 -1.139]
```
> Accuracy Check
```python
print('Accuracy : {:.2f}'.format(reg.score(X_test, y_test))) # regression의 score는 R^2값을 사용한다. 
```
> 출력
```
Accuracy : 0.83
```

---
### 종합
* 기존에 분포하고 있는 값들을 활요하는 컨셉이기 때문에 '훈련(학습)'의 개념이 필요하지 않다. 
* 머신러닝 모델은 공통적으로 모든 X가 숫자형으로 구성되어야 한다. 여기서, KNN 알고리즘은 모두 숫자형 컬럼이라 하더라도 정규화 되어 있지 않거나, X가 sparse(one-hot-encoded)하다면 성능은 매우 떨어진다.
* 이는 '데이터의 거리'를 기준으로 Y_hat을 찾기 때문에 그렇다. 입력 X는 각 Data Point의 거리가 일관성 있고(정규화, Normalized), 연속 변수로 채워진 Vector(유클리드 거리 계산이 가능한)여야 한다.
* K가 작으면 과대적합, K가 크면 과소적합되는 경향이 있다.

> 분류 분석(이산형 y)에 사용된 KNN의 과대/과소 적합 예시 

![image](https://t1.daumcdn.net/cfile/tistory/99A20A3F5A634C1C0E)
*왼쪽부터 n=1, n=3, n=9*

> 회귀 분석(연속형 y)에 사용된 KNN의 과대/과소 적합 예시

![image](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FT8MQo%2FbtqvWSrBeUC%2FJGGG1Ed5RKdnbWpOcE4PtK%2Fimg.png)
*왼쪽부터 n=1, n=3, n=9*