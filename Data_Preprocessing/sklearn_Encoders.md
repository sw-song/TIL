# Encoder
1. LabelEncoder
2. OneHotEncoder
3. LabelBinarizer


> *reference : 
>1. kaggle, [Heart Attack Prediction_95.4% accuracy, Avinash Bagul](https://www.kaggle.com/avibagul80/heart-attack-prediction)*
>2. [머신러닝 프로젝트 실행-3, cyan91](https://cyan91.tistory.com/16)
---


### 1. LabelEncoder
- object 타입의 label을 숫자형으로 변환
- 머신러닝 모델은 모든 컬럼의 값을 숫자형으로 통일시켜줘야 하는데(혹은 categorical column은 제거해야 하는데) 이는 확률 모델이기 때문에 그렇다(+수식 계산이 가능해야 미분을 통한 학습이 이루어질 수 있다)

> 예시 코드
```python
from sklearn.preprocessing import LabelEncoder
le = LabelEncoder()
X_encoded = le.fit_transform(X)
X_encoded # 출력
```
> 출력
```
array([1,5,3,5...,0,0,3]) 
```
* 0~5 사이의 값으로 endcoding 되었다고 가정.
* 컴퓨터는(머신러닝 모델은) 0과 1, 1과 2의 연관성을 0과 5보다 더 크게 인지한다. 따라서 우리가 의도한(그러한 연관성이 있는) 것이 아니라면 LabelEncoder는 사용하기에 적절하지 않다.


### 2. OneHotEncoder
- 모든 범주를 0 혹은 1로 변환
- 예를 들면, 개와 고양이를 1과 2로 변환하는 것이 아니라 해당 실험군이 '개'라면 '개' column에 1을, '고양이' column에 0을 넣는다.

> 예시 코드
```python
from sklearn.preprocessing import OneHotEncoder
oh = OneHotEncoder()
X_encoded = oh.fit_transform(X)
X_encoded # 출력
```
> 출력
```
<16513x5 sparse matrix of type '<class 'numpy.float64'>' with 16513 stored elements in Compressed Sparse Row Format>
```
* Sparse Row Format으로 저장되었다고 출력한다.
* 이는 메모리 효율성을 위한 것인데, 원핫인코딩은 모든 값을 0과 1로 넣기 위해 매트릭스가 방대하게 확장되기 때문에(+모든 값은 0 혹은 1로 저장되어 있으므로) 메모리에 0이 아닌 요소들(1)의 위치만 저장하도록 하는 방식이다.
* 그런데, 원핫인코딩은 애초에 숫자형 범주를 입력값으로 받기 때문에 텍스트 범주를 LabelEncoder에 먼저 통과시켜야 한다는 번거로운 점이 있다.



### 3. LabelBinarizer
- 컬럼 내 모든 텍스트 값을 숫자형으로 변환 + 숫자형을 원핫벡터로 변환



> 예시 코드
```python
from sklearn.preprocessing import LabelBinarizer # sklearn.preprocessing에서 LabelBinarizer 패키지 사용

lb = LabelBinarizer() # LabelBinarizer() 할당
X_encoded = lb.fit_transform(X) 
X_encoded
```
> 출력 
```
array([[0,1,0,0,0],
       [0,1,0,1,0],
       ...
       [1,0,0,1,1],
       [1,0,0,0,0],
       [0,0,1,0,1]])
```
* LabelBinarizer()는 Default로 numpy 배열을 즉시 할당한다.