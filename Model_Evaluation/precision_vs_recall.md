# Precision and Recall in an anomaly detection situation
> **reference :**
> 1. [Classification : Precision and Recall](https://developers.google.com/machine-learning/crash-course/classification/precision-and-recall?hl=ko)
> 2. [분류성능평가지표 - Precision(정밀도), Recall(재현률) and Accuracy(정확도)](https://sumniya.tistory.com/26)
---

> **Examples : Anomaly Detection**
```
실제 이상 징후 : 1
실제 정상 징후 : 0
```

Timeseries|11|12|13|14|15|16|17|18|19|20|22|23|24|25|
|---------|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
|Actual-Anm|0| 0| 0| 0| 0| 0| 0| 0| 0| 1| 0| 1| 1| 1|
|threshold | |  |  |  |  |  |  |  |  |  |  |> |  |  |
|Detect_Anm|0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 0| 1| 1| 1|
|True-Pstv | |  |  |  |  |  |  |  |  |  |  | T| T| T|
|False-Ngtv| |  |  |  |  |  |  |  |  | F|  |  |  |  |
|True-Ngtv |T| T| T| T| T| T| T| T| T|  | T|  |  |  |
|False-Pstv| |  |  |  |  |  |  |  |  |  |  |  |  |  |

---
```
 Precision(정밀도)
 = 감지해낸(맞췄을 수도, 맞추지 못했을 수도 있는) 이상 징후 중 실제 이상 징후의 비율
 = 실제 이상 징후 수 / 감지해낸 이상 징후 수
 = 실제 이상 징후 수 / (맞춘 이상 징후 수 + 잘못 감지한 이상 징후 수)
 = n(TP) / (n(TP)+n(FP))
 = 3 / 3
 = 1

Recall(재현률)
 = 실제 이상 징후 중 감지해낸(맞춘) 이상 징후의 비율
 = 맞춘 이상 징후 수 / 실제 이상 징후 수 
 = 맞춘 이상 징후 수 / (맞춘 이상 징후 수 + 맞추지 못한 이상 징후 수)
 = n(TP) / (n(TP)+n(FN))
 = 3 / 4
 = 0.75
```
---
보안 침해 대응시 위협을 판별하는 알고리즘은 정확도(Accuracy) 혹은 정밀도(Precision)보다 재현률(Recall)이 중요하다.

실제 이상 징후가 들어왔을 때 모든 이상 징후를 100%에 가깝게 감지해내야 하기 때문이다.
즉, 정확도가 어느 정도 떨어지는 것을 감수하더라도 임계값(Threshold)을 낮춰서 이상치에 기민하게 반응하는(`False Negative`가 없는) 알고리즘을 구현해야 한다.

---

Timeseries|11|12|13|14|15|16|17|18|19|20|22|23|24|25|
|---------|--|--|--|--|--|--|--|--|--|--|--|--|--|--|
|Actual-Anm|0| 0| 0| 0| 0| 0| 0| 0| 0| 1| 0| 1| 1| 1|
|threshold | |  |  |  |  |  |  |  |  | >|  |  |  |  |
|Detect_Anm|0| 0| 0| 0| 0| 0| 0| 0| 0| 1| 1| 1| 1| 1|
|True-Pstv | |  |  |  |  |  |  |  |  | T|  | T| T| T|
|False-Ngtv| |  |  |  |  |  |  |  |  |  |  |  |  |  |
|True-Ngtv |T| T| T| T| T| T| T| T| T|  |  |  |  |  |
|False-Pstv| |  |  |  |  |  |  |  |  |  | F|  |  |  |

---
```
 Precision(정밀도)
 = 감지해낸(맞췄을 수도, 맞추지 못했을 수도 있는) 이상 징후 중 실제 이상 징후의 비율
 = 실제 이상 징후 수 / 감지해낸 이상 징후 수
 = 실제 이상 징후 수 / (맞춘 이상 징후 수 + 잘못 감지한 이상 징후 수)
 = n(TP) / (n(TP)+n(FP))
 = 4 / 5
 = 0.8

Recall(재현률)
 = 실제 이상 징후 중 감지해낸(맞춘) 이상 징후의 비율
 = 맞춘 이상 징후 수 / 실제 이상 징후 수 
 = 맞춘 이상 징후 수 / (맞춘 이상 징후 수 + 맞추지 못한 이상 징후 수)
 = n(TP) / (n(TP)+n(FN))
 = 4 / 4
 = 1
```


