### GridSearchCV

reference :
1. [sklearn.model_selection.GridSearchCV(scikit-learn.org)](https://scikit-learn.org/stable/modules/generated/sklearn.model_selection.GridSearchCV.html)
2. [모형최적화, 데이터사이언스스쿨](https://datascienceschool.net/03%20machine%20learning/14.01%20모형%20최적화.html)
3. [[Chapter 4. 분류] 랜덤포레스트(Random Forest)](https://injo.tistory.com/30)
---

머신러닝 모델의 하이퍼파라미터를 조정하는 일은 매우 까다롭다. 아주 미묘한 파라미터 값 변화가 모델의 성능을 좌우하고, 모델마다 다양한 파라미터들이 유기적으로 얽혀있기 때문이다.
GridSearchCV를 통하면 다양한 하이퍼파라미터 값을 미리 입력하고, 최적의 값과 해당 값으로 표현된 모델 정확도를 돌려받을 수 있다.

```python
from sklearn.model_selection import GridSearchCV

params = {'n_estimators' : [10, 100],
          'max_depth' : [6, 8, 10, 12],
          'min_samples_leaf' : [8, 12, 18],
          'min_samples_split' : [8, 16, 20]
         }
```
이제, 아래와 같이 모델을 넣고, 입력한 하이퍼 파라미터를 ```n_estimators```, ```max_depth```, ```min_samples_leaf```, ```min_samples_split``` 순으로 (10, 6, 8, 8) -> (10, 6, 8, 16) -> (10, 6, 8, 20) -> (10, 6, 12, 8) 과 같이 순회하며 **최고의 성능을 내는 최적의 하이퍼파라미터**를 찾게 된다. 

```python
model = RandomForestClassifier(random_state=42)
grid_cv = GridSearchCV(model, param_grid=params, cv=3) 
```

여기서 cv를 3으로 지정하였는데, train, test set을 '폴드'라는 개념으로 검증을 위해 분할되는 수를 의미한다. 즉, 위에서 하이퍼 파라미터 조합의 수는 72(2x4x3x3)개인데, cv=3으로 넣어주면 72=3, 216번 학습&평가가 진행된다.

해당 알고리즘의 학습은 머신러닝 모델 학습과 마찬가지로 ```fit```을 통해 진행된다.
```python
grid_cv.fit(X_train, y_train)
```

학습을 마친 다음 아래와 같이 최적의 파라미터, 성능을 도출해낼 수 있다.
```python
print('Best Hyper-Parameter : {}'.format(grid_cv.best_params_))
print('Best Accuracy : {:.4f}'.format(grid_cv.best_score_))
```
```
Best Hyper-Parameter : {'max_depth': 12, 'min_samples_leaf': 8, 'min_samples_split': 8, 'n_estimators': 100}
Best Accuracy : 0.9206
```

이제 해당 값을 통해 모델을 다시 학습하게 되고, 최종적으로 test 데이터에 적용하고 마무리한다.
```python
model_final = RandomForestClassifier(n_estimators=100,
                                     max_depth = 12,
                                     min_samples_leaf = 8,
                                     min_samples_split=8,
                                     random_state=0
                                    )
model.fit(X_train, y_train)
pred = model.predict(X_test)
print('Final Accuracy : {:.4f}'.format(accuracy_score(y_test,pred))
```
```
Final Accuracy : 0.9230
```