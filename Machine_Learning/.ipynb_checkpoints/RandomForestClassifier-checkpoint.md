## Random Forest
reference:
1. [Random Forest(랜덤 포레스트) 개념 정리](https://eunsukimme.github.io/ml/2019/11/26/Random-Forest/)
2. [sklearn.ensemble.RandomForestClassifier](https://scikit-learn.org/stable/modules/generated/sklearn.ensemble.RandomForestClassifier.html)

---
### Bagging(Bootstrap aggregating)
1. 모집단(데이터셋)에서 부분집합 형태로 임의의 N개를 추출하여 트리 하나를 만든다.
2. 추출한 N개는 다시 넣어서 모집단 원본을 만들고, 또 다시 임의의 N개 데이터를 추출하여 두 번째 트리를 만든다.(실제로 데이터를 다시 넣지는 않는다. 중복을 허용한다는 의미로 서술)
3. ```max_features``` 파라미터를 통해 feature는 최대 몇개를 샘플링하여 트리를 구성할 지 정의할 수 있다.
4. 전체 트리 결과값이 나오면 가장 분포가 많은 값이 RandomForestClassifier 모델의 최종 결과 값으로 선정된다.

RandomForestClassifier는 위 Bagging 동작을 거쳐 최종 모델을 반환한다. 
이 원리만 이해한다면 문법은 단순하다.

```python
from sklearn.ensemble import RandomForestClassifier

model = RandomForestClassifier(n_estimators=100) # 100개의 트리를 만든다. 필요하다면 max_features = n 을 통해 최대 feature 갯수를 지정할 수도 있다.

model.fit(X_train, y_train)
print('Train Accuracy : {:.2f}'.format(model.score(X_train, y_train)))
print('Test Accuracy : {:.2f}'.format(model.score(X_test, y_test)))
```
```
Train Accuracy : 0.96
Test Accuracy : 0.92
```





