## XGBoost(eXtreme Gradient Boost)
1. [캐글로 배우는 머신러닝 #10 XGBoost](https://www.youtube.com/watch?v=XAceJyNrPN4)
2. [파이썬 Scikit-Learn 형식 XGBoost 파라미터](https://blog.naver.com/PostView.nhn?blogId=gustn3964&logNo=221431714122)
3. [XGBoost 알고리즘의 개념 이해](https://bcho.tistory.com/1354)
4. [머신러닝 앙상블(ensemble) xgboost란?](https://lsjsj92.tistory.com/547)

---
XGBoost는 기존 Gradient Boosting 방식의 `느리고, training set에 overfitting되는 문제`를 어느 정도 해결한 고성능 ensemble 기법이다.

### 규제
- Overfitting을 방지하도록 하이퍼파라미터를 통해 `규제`할 수 있다.
- reg_alpha : L1 규제
- reg_lambda : L2 규제

### early stopping
- 주로 딥러닝 학습에 파라미터로 사용되는 early stopping을 지원한다.
- model.fit(X_train, y_train, `early_stopping_rounds=n`...)

### CART
- Classification And Regression Tree
- 분류, 회귀 모두 지원한다.

### Common Hyper-parameters
- n_estimators : 결정 트리 수
- learning_rate : 학습률(학습 보폭)
- max_depth : 트리의 깊이

---
xgboost는 sklearn에서 지원하지 않는다. xgboost library를 별도로 설치하여 사용한다.

```python
from xgboost import XGBClassifier

model = XGBClassifier() # all hyper-parameter : default
model.fit(X_train, y_train)

# Prediction
print('Train Score : {}'.format(model.score(X_train, y_train)))
print('Test Score : {}'.format(model.score(X_test,y_test)))
```
```
Train Score : 1.0
Test Score : 0.98
```

---
XGBoost는 Classification과 Regression 모두 지원한다. 아래는 Regression 예제이다.
```python
from xgboost import XGBRegressor
model = XGBRegressor() # all hyper-parameter : default
model.fit(X_train, y_train)

# Prediction
print('Train Score : {}'.format(model.score(X_train, y_train)))
print('Test Score : {}'.format(model.score(X_test,y_test)))
```
```
Train Score : 0.99
Test Score : 0.97
```
---
이처럼 XGBoost는 분류/회귀 유형 모두를 지원하므로 모델 학습 목적에 따라 XGBClassifier 혹은 XGBRegressor를 유연하게 사용할 수 있다.