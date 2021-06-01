## LGBM(Light Gradient Boosting Machine)
1. [LightGBM's documentation](https://lightgbm.readthedocs.io/en/latest/)
2. [LightGBM 주요 파라미터 정리](https://gorakgarak.tistory.com/1285)
3. [LightGBM이란?](https://nurilee.com/2020/04/03/lightgbm-definition-parameter-tuning/)

---
LGBM은 'Light'(`==fast`)하고 또 'Light'(`==low memory`)하다. 그만큼 또 예민하다는 단점이 있다. 예민하다는 것은 과적합(Overfitting)되기 쉽다는 것이며 1만 개 이하의 적은 데이터셋을 다루기에는 적합하지 않은 모델이다.

LGBM을 사용할 때에는 과적합에 특히 유의해야 하며 아래의 하이퍼파라미터들을 통해 학습을 조절할 필요가 있다.

### max_depth
- Tree의 깊이가 깊을 수록 당연하게도 train set에 더 가까운 가중치를 학습하게 된다. 다른 모델을 사용할 때보다 현저하게 max_depth를 줄일 필요가 있으며 max_depth를 줄여도 test set에 대한 정확도가 올라가지 않는다면 해당 모델이 적합하지 않은 것이다.

### min_data_in_leaf
- 하나의 Leaf가 가져야 할 최소한의 record 수. 과적합을 해결하기 위해 20 아래로 줄여볼 수 있다.(default : 20)

### bagging_fraction
- bagging 단계에서 모든 데이터를 사용하지 않고 일부만 사용하는 비율
- 딥러닝 신경망에서 drop_out과 같이 과적합 방지 목적으로 사용된다.

### early_stopping_round
- XGBoost처럼 early_stopping 옵션을 지원한다.
- training set에 과하게 적합될 수록 validation set에 대한 정확도는 떨어지는데 이 때 계속해서 validation accuracy(혹은 성능)이 떨어지는 방향으로 머물러 있다면 학습을 중단한다.
- early_stopping은 모델 설계보다는 학습 단에서 과적합을 막아주는 옵션이다.

---
lightGBM은 XGBoost와 마찬가지로 sklearn에서 지원하지 않는다. `lightgbm` library를 별도로 설치하여 사용한다. 

```python
from lightgbm import LGBMClassifier

model = LGBMClassifier() # all hyper-parameter : default
model.fit(X_train, y_train)

# Prediction
print('Train Score : {}'.format(model.score(X_train, y_train)))
print('Test Score : {}'.format(model.score(X_test,y_test)))
```
```
Train Score : 1.0
Test Score : 0.97
```

---
`lightgbm`은 Classification과 Regression 모두 지원한다. 아래는 Regression 예제이다.
```python
from lightgbm import LGBMRegressor
model = LGBMRegressor() # all hyper-parameter : default
model.fit(X_train, y_train)

# Prediction
print('Train Score : {}'.format(model.score(X_train, y_train)))
print('Test Score : {}'.format(model.score(X_test,y_test)))
```
```
Train Score : 0.97
Test Score : 0.89
```
---
lightgbm 역시 XGBoost와 마찬가지로 분류/회귀 유형 모두를 지원하므로 모델 학습 목적에 따라 LGBMClassifier 혹은 LGBMRegressor를 유연하게 사용할 수 있다. 

추가로, 위 Regression 예제에서 암묵적으로 사용된 데이터는 sklearn에 내장된 boston 데이터이다. 데이터의 수(X:404x13, y:404x1)가 적다보니 XGBoost보다 성능이 좋지 않다. lightgbm은 말 그대로 light하므로 대용량 데이터에 더 적합한(이점이 있는) 모델임을 알 수 있다.

