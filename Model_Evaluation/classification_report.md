# sklearn.metrics.classification_report
> **reference :**
> 1. scikit-learn.org, [sklearn.metrics.classification_report, document](https://scikit-learn.org/stable/modules/generated/sklearn.metrics.classification_report.html)
> 2. scikit-learn.org,[sklearn.metrics.f1_score, document](https://scikit-learn.org/stable/modules/generated/sklearn.metrics.f1_score.html)
> 3. stackoverflow, [How to interpret classification report of scikit-learn?,LaSul Answered](https://datascience.stackexchange.com/questions/64441/how-to-interpret-classification-report-of-scikit-learn#)
> 4. [Accuracy(정확도), Recall(재현율), Precision(정밀도), 그리고 F1 Score, eunsukimme](https://eunsukimme.github.io/ml/2019/10/21/Accuracy-Recall-Precision-F1-score/)
---
> **Document :**
```
sklearn.metrix.classification_report(y_true, y_pred, *, Labels=None, target_name=None, sample_weight=None, digits=2, output_dict=False, zero_division='warn')
```
---
> **Examples :**
```python
>> from sklearn.metrix import classification_report
>> y_true = [0, 1, 2, 2, 2] # multivariable classification that targets are '0 or 1 or 2'
>> y_pred = [0, 0, 2, 2, 1] # predicted vector (compared with y_true)
>> target_names = ['class 0', 'class 1', 'class 2'] # 0, 1, 2 중에 맞추는 분류 문제
>> print(classification_report(y_true, y_pred, target_names=target_names))
```
```
               precision    recall  f1-score   support

     class 0       0.50      1.00      0.67         1
     class 1       0.00      0.00      0.00         1
     class 2       1.00      0.67      0.80         3

    accuracy                           0.60         5
   macro avg       0.50      0.56      0.49         5
weighted avg       0.70      0.60      0.61         5
```

---
### 1. support
- y_true(실제값)은 '0', '1', '2'로 구성되어 있고 '0'은 1개, '1'도 1개, '2'는 3개다. ```y_true=[0, 1, 2, 2, 2]``` support는 실제값의 분류별 분포(수)를 나타낸다.

```
class 0 : 1
class 1 : 1
class 2 : 3
```

### 2. precision(정확도)
- y_pred가 예측한 값 중 y_true(실제값)과 일치하는 비율을 나타낸다.
```
class 0 : 0.5  # y_pred는 '0'을 2개 예측했고, 2개 중 1개만 일치
class 1 : 0.0 # y_pred는 '1'을 1개 예측했고, 일치하지 않음
class 2 : 1.0 # y_pred는 '2'를 2개 예측했고, 2개 모두 일치
```

### 3. recall(소환, 호출)
- y_true(실제값) 중 y_pred가 맞춘(불러낸, 호출한) 비율을 나타낸다.
```
class 0 : 1.0 # y_true는 '0'을 1개 가지고 있었고, 해당 값은 y_pred에 의해 예측되었음
class 1 : 0.0 # y_true는 '1'을 1개 가지고 있었고, 해당 값은 y_pred가 맞추지(불러내지) 못했음
class 2 : 0.67 # y_true는 '2'를 3개 가지고 있었고, 해당 값 중 y_pred가 맞춘(불러낸) 값은 2개. 즉 2/3 recall
```

### 4. f1-score
- precision, recall을 모두 고려한 값
- 2 * (precision * recall)/(precision + recall)
- 위 수식은 일반적인 평균 계산식이 아닌 조화 평균이다. 조화평균은 불균형이 심할 수록 낮은 값에 가깝게 나온다. 즉, precision과 recall값이 차이가 크다면, 값이 더 낮게 나오며 이를 통해 불균형도를 체크할 수 있다.

### 5. accuracy
- 전체 값(y_true) 중 맞은 비율, 여기서 총 5개 변수 ```[0, 1, 2, 2, 2]``` 중 3개가 일치했으므로 3/5. 즉 정확도는 0.6

### 6. macro avg
- 전체 평균, ```class 0, class 1, class 2```의 ```precision, recall, f1-score``` 각각 값에 대해 n(3)으로 나눈 값
- ex. ```f1-score```에서, (0.67 + 0.00 + 0.80)/3 = 0.49

### 7. weighted avg
- 변수 가중치가 포함된 값의 평균, 가중치는 support 수(실제값, y_true의 분포 수)
- 즉, 각 분류별 측정값에 가중치를 곱하고 전체 합산하여 전체 support 수로 평균함
- ex. ```precision```에서, (0.50*1 + 0.00*1 + 1.00*3)/5 = 0.70


