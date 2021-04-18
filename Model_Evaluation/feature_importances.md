# Feature Importance and Permutation Feature Importance
reference :
1. [Feature selection : feature importance vs permutation importance](https://hwi-doc.tistory.com/entry/Feature-selection-feature-importance-vs-permutation-importance)
2. [Permutation feature importance(sklearn.org)](https://scikit-learn.org/stable/modules/permutation_importance.html)
3. [The Mathematics of Decision Trees, Random Forest and Feature Importance in Scikit-learn and Spark](https://towardsdatascience.com/the-mathematics-of-decision-trees-random-forest-and-feature-importance-in-scikit-learn-and-spark-f2861df67e3)
4. [머신러닝의 해석 2편 - 1. 트리 기반 모델의 Feature Importance 속성](https://soohee410.github.io/iml_tree_importance)
5. [랜덤 포레스트에서의 변수 중요도(Variable Importance) 3가지](https://velog.io/@vvakki_/랜덤-포레스트에서의-변수-중요도Variable-Importance-3가지)
6. [Feature Importance(변수 중요도) - 트리 기반 모델](https://pangyo-datascientist.tistory.com/m/entry/Featrue-Importance변수-중요도-트리-기반-모델?category=391202)
7. [선형 회귀 모델에서 '선형'이 의미하는 것은 무엇인가?](https://brunch.co.kr/@gimmesilver/18)
8. [머신러닝 - 4. 결정 트리(Decision Tree)](https://bkshin.tistory.com/entry/머신러닝-4-결정-트리Decision-Tree)
---
### Feature Importance
Tree 기반 머신러닝 모델은 모델 생성 과정에서 각 Node별 Entropy가 발생(계산)한다. Entropy는 '불순도'를 표현하며, 각 Node가 연장되며 가지치기(의사결정)해나가는 과정에서 제대로 가지치기를 하고 있다면 '불순도'가 낮아지고 그 값(Entroypy)은 0에 가까워진다. Gradient Boosting 계열의 트리 모델은 이 Entropy 값을 낮추는 방향으로 노드를 이어나간다.

만약 제대로 가지치기를 하지 못해 정확히 A 와 B로 나누지 못했다면, 즉 A로 분류한 공간에 B가 많이 남아있을 수록 그 값(Entropy)는 점점 올라간다.

Tree 모델에서 자체 함수로 제공하는 feature importance는 이렇게 Entropy가 0으로 잘 수렴하고 있는지를 확인하는데, 정보이론 관점에서 보면 정보를 얼마나 잘 획득하고 있는지 확인하는 과정과 같다.

다시 말하면 Entropy값이 상하 노드에서 얼마나 차이가 나는가? 즉 제대로 된 정보를 얼마나 취득해가고 있는가(정보이득)를 체크해서 feature별 유의미성을 판단한다.






### Permutation Feature Importance
feature importance가 '불순도'를 얼마나 낮추는 feature인지 확인하는 것을 통해 유의미한 feature를 찾는 방식이라면 Permutation feature importance는 학습을 완료한 모델에서 feature 하나씩 row를 shuffle하면서 모델 성능의 변화를 관찰하는 방식이다.

즉, shuffle한 feature가 모델에 중요한 feature였다면 row를 무작위로 shuffle했을 때 성능이 크게 떨어질 것이고 중요한 feature가 아니었다면 shuffle하더라도 성능에 큰 변화가 없을 것이다.(우연히 성능이 올라가거나 떨어질 risk도 분명 존재한다.)

Permutation Feature Importance는 eli5 패키지를 통해 사용할 수 있다.