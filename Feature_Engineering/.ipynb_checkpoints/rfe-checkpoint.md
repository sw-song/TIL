### RFE (recursive feature elimination)

Reference :
1. [Python 데이터 분석 실무 04-06.모델 성과 개선 (WikiDocs)](https://wikidocs.net/16599)
2. [Simple, yet, Powerful Bankrupt Prediction Model](https://www.kaggle.com/jaimebecerraguerrero/simple-yet-powerful-bankrupt-prediction-model)
3. [sklearn.feature_selection.RFE, scikit-learn.org](https://scikit-learn.org/stable/modules/generated/sklearn.feature_selection.RFE.html#sklearn.feature_selection.RFE)
---

RFE는 주요 Feature를 선별해내는 기법 중 하나로 이름(*Recursive feature elimination*) 그대로 '반복적으로 feature를 제거해나가는' 방식이다. 

대표적인 머신러닝 라이브러리 sklearn에서는 feature_selection 모듈을 제공한다.
RFE는 아래와 같이 해당 모듈에서 import 할 수 있다.

```python
from sklearn.feature_selection import RFE
```

RFE를 두고, 반복적으로 feature를 제거해나가는 방식이라 했다. 2개의 파라미터를 넣어주는 것을 통해 간단히 사용해볼 수 있다.

```python
select_10features = RFE(RandomForestClassifier(n_estimators=100, random_state=42), n_features_to_select=10) # RandomForestClassifier 모델 import는 생략하였음.
```
 
> Reference : [Kaggle - Simple, yet, Powerful Bankrupt Prediction Model](https://www.kaggle.com/jaimebecerraguerrero/simple-yet-powerful-bankrupt-prediction-model)

kaggle 아래와 같이 깔끔하게 줄여볼 수 있다.
```python
model = RandomForestClassifier(n_estimators=100, random_state=42)
select_10features = RFE(model, 10) # n_features_to_select 생략
```

RFE는 머신러닝 모델을 학습할 때와 마찬가지로 ```fit```을 통해 feature를 선별해나가는 과정이 필요하다. 

```python
selector = select_10features.fit(X,y)
```

```fit```을 했다면 selector를 통해 몇가지 데이터를 확인할 수 있다.
```python
print('Number of Features : {}'.format(selector.n_features_))
print('Is feature selected? : {}'.format(selector.support_))
print('Ranking of Features : {}'.format(selector.ranking_))
```
```
Number of Features : 10
Is feature selected? [True, True, True, True, True, False, False, False, False, False]
Ranking of Features : [1, 1, 1, 1, 1, 6, 4, 3, 2, 5]
```


