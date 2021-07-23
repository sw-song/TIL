## OLS - Regression

### reference 
1. [선형회귀분석 및 OLS](https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=sanghan1990&logNo=221116465873)
2. [document : Ordinary Least Squares](https://www.statsmodels.org/stable/examples/notebooks/generated/ols.html)
3. [Python 기초 통계 - 회귀분석 실시하기](https://mindscale.kr/course/basic-stat-python/11/)
---


회귀분석은 파이썬에서 제공하는 대표적인 통계 분석 패키지 `statsmodels`를 불러와 간단히 사용할 수 있다.

```python
import statsmodels.api as sm

model = sm.OLS(y, X)  # y : 종속 변수(시리즈), X : 독립 변수 집합(데이터프레임)
result = model.fit()
result.summary()
```

혹은, 함수 식 표현을 활용할 수도 있다.
```python
import statsmodels.api as sm

model = sm.OLS.from_formula('y ~ x1+x2+x3', data=df) 
result = model.fit()
result.summary()
```

두 코드의 결과 값은 동일하다. 회귀 계수와 각각의 p-value, 그리고 통계적 유의미성을 확인해주는 R^2까지 유용한 지표를 한번에 확인할 수 있다.
