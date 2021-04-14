## GradientBoostingClassifier
1. [Gradient Boosting Model](https://woolulu.tistory.com/30)
2. [sklearn.ensemble.GradientBoostingClassifier](https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.GradientBoostingClassifier.html)
3. [지도학습 - 그래디언트 부스팅](https://jfun.tistory.com/122)
4. [2.3.6 결정 트리의 앙상블, 텐서 플로우 블로그](https://tensorflow.blog/파이썬-머신러닝/2-3-6-결정-트리의-앙상블/)
---
GradientBoosting 모델은 RandomForest 모델과 달리 learning_rate를 통해 오차를 줄여나가는 학습 방식을 사용한다.
RandomForest 모델은 말그대로 Random하게 Bagging, Tree를 생성한다. 하지만 GradientBoosting 모델은 Tree를 생성할 때마다 이전 Tree보다 오차를 줄이게 된다. 또한 개별 Tree의 깊이는 얕게 만들어내면서 오차가 줄어든 Tree를 계속해서 연결해나가는 구조다.*(때문에, Tree 깊이는 얕게, 갯수는 늘리는 방식을 주로 사용한다.)*

아래 3가지 하이퍼파라미터는 GradientBoosting 모델 성능(정확도)에 민감하게 작용합니다.

### n_estimator
- default : 100
- 트리의 갯수를 의미한다. GradientBoosting 모델은 매 Tree 생성마다 학습오차를 줄이기 때문에(learning_rate) n_estimator가 많아질 수록, 즉 Tree를 많이 생성할 수록 Training 데이터셋에 대한 학습(예측)오차는 줄어들며 과적합된다.
- 이는 RandomForest 모델과 다른 점이다. RandomForest 모델은 n_estimator를 크게 할 수록 좋다.

### learning_rate
- default : 0.1
- 값이 작으면 이전 Tree의 학습 오차를 살짝만 줄익고, 값이 크면 크게 줄인다. 즉, 값이 커질 수록 training 데이터셋에 과적합된다.

### max_depth
- default : 3
- 개별 Tree의 깊이를 의미한다. 보통 1~3 정도로 설정한다. 
- 깊이가 작은 특성때문에 이러한 단일 트리를 weak learner라고 한다.
- 이러한 weak learner는 적은 데이터(전체 중 좁은 일부)만 담기에 메모리를 적게 사용하고 예측이 빠른 장점이 있다.

---
사용법은 다른 sklearn classification 모델들과 동일하다.
단, sklearn의 ensemble 패키지를 활용한다.

```python
from sklearn.ensemble import GradientBoostingClassifier

model = GradientBoostingClassifier(randome_state=0) # default : max_depth=3, learning_rate=0.1
model.fit(X_train, y_train)

# Prediction
print('Train Score : {}'.format(model.score(X_train, y_train)))
print('Test Score : {}'.format(model.score(X_test,y_test)))
```
```
Train Score : 0.98
Test Score : 0.93
```

---
"sparse한 고차원 데이터에는 잘 동작하지 않는다"는 단점이 있다. 이는 Tree 모델의 공통적인 특징이다.